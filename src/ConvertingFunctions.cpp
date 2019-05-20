#include <ConvertingFunctions.hpp>

#include <cmath>
#include <iostream>
#include <map>

namespace converting_functions
{

enum class StringValue
{
    course_to_degrees,
    id_to_pl
};

std::map<std::string, StringValue> mapStringValues
{
    {"course_to_degrees", StringValue::course_to_degrees},
    {"id_to_pl", StringValue::id_to_pl}
};

bool convert (const rapidjson::Value& object, rapidjson::Value& result_value, const std::string& function_name)
{
    if (mapStringValues.find(function_name) == mapStringValues.end())
    {
        return false;
    }
    switch (mapStringValues[function_name])
    {
        case (StringValue::id_to_pl): return id_to_pl(object, result_value);
        case (StringValue::course_to_degrees): return course_to_degrees(object, result_value);
    }
    return true;
}

bool course_to_degrees(const rapidjson::Value& object, rapidjson::Value& result_value)
{
    auto find_itr = object.FindMember("course");
    if (find_itr != object.MemberEnd())
    {
        if (find_itr->value.IsDouble())
        {
            result_value = find_itr->value.GetDouble() * (180/M_PI);
            return true;
        }
    }
    return false;
}

bool id_to_pl(const rapidjson::Value& object, rapidjson::Value& result_value)
{
    rapidjson::Document result_document;
    rapidjson::Document::AllocatorType& allocator = result_document.GetAllocator();

    auto find_itr = object.FindMember("id");
    if (find_itr != object.MemberEnd())
    {
        if (find_itr->value.IsInt())
        {
            std::string value = std::string("PL_" + std::to_string(find_itr->value.GetInt()));
            
            result_value.SetString(value.c_str(), value.length(), allocator);
            return true;
        }
    }
    return false;
}
} //converting_functions