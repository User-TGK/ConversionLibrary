# Converting functions (shared) library

This package contains the framework for the shared library where conversion functions can be defined.

# Prerequisites

To build and install this package the following prerequisites have to be met:

1. Operating system: Ubuntu 18.04 LTS
2. GCC compiler version 7.3.0 or later (or any other C++17 supporting compiler)
3. CMake 3.8.0 or later

# Compilation

```
> mkdir build && cd build
> cmake ../
> make
```

# Installation

```
> sudo make install
```

When installing the package the path where the library (.so) is installed will be printed on the console. This will usually be something like '/usr/local/lib/libConvertionFunctions.so'. In order to let the data conversion server know where you installed the library either manually set the path, or change the LD_LIBRARY_PATH environment variable to the installation directory. In the case of the above installation directory you would run the below command.

```
> export LD_LIBRARY_PATH=/usr/local/lib
```