#include <ConvertingFunctions.hpp>

#include <map>

namespace converting_functions
{

enum class StringValue
{
    // example_convertion_function
};

std::map<std::string, StringValue> mapStringValues
{
    // {"example_convertion_function", StringValue::example_convertion_function}
};

bool convert (const rapidjson::Value& object, rapidjson::Value& result_value, const std::string& function_name)
{
    if (mapStringValues.find(function_name) == mapStringValues.end())
    {
        return false;
    }
    switch (mapStringValues[function_name])
    {
        // case (StringValue::example_convertion_function): return example_convertion_function(object, result_value);
    }
    return true;
}

// bool example_convertion_function(const rapidjson::Value& object, rapidjson::Value& result_value)
// {
//     return;
// }

} //converting_functions