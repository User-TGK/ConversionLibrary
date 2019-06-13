## First we create the build image from the existing Server

FROM dcs_image AS build

COPY . /

RUN apt update \ 
    && apt install -y   g++   \
                        make  \
                        cmake

# Installating conversion functions library
RUN cd /ConversionLibrary \
    && mkdir build && cd build \
    && cmake ../ \
    && make -j8 \
    && make install \
    && cd .. && rm -rf ConversionLibrary

## Then we create the release image with only the DCS and updated Conversion Library

FROM phusion/baseimage:0.11

RUN mkdir -p /DataConversionServer/build && mkdir /config

COPY --from=build /DataConversionServer/build /DataConversionServer/build
COPY --from=build /usr/local/lib /usr/local/lib

ENV CONFIG_PATH /config/DataConversionServer.ini
ENV SOURCES_PATH /config/sources/

CMD ./DataConversionServer/build/DataConversionServer --config=${CONFIG_PATH} --sources-config=${SOURCES_PATH}