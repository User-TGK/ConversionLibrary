#ifndef CONVERTING_FUNCTIONS_HPP
#define CONVERTING_FUNCTIONS_HPP

#include <string>
#include <unordered_map>

#include <rapidjson/document.h>

namespace converting_functions
{

/**
 * @brief the main convertion function that will be expected to be of type:
 * const rapidjson::Value&, rapidjson::Value& -> bool by the data convertor.
 * Changing the type of this function will cause the data server to throw an error on startup
 * 
 * @param object the original object to be converted
 * @param result_value reference to the result value (might be an object or array) that should be created by the function
 * @param function_name the string representation of the function
 * @return true if the conversion could be done successfully
 * @return false if the conversion could not be done successfully
 */
bool convert (const rapidjson::Value& object, rapidjson::Value& result_value, const std::string& function_name);

/**
 * @brief example convertion function
 * 
 * @param object the original object to be converted by the defined function
 * @param result_value the result value of the convertion
 * @return true if the convertion was successfull
 * @return false if the convertion was not successfull
 */

//bool example_convertion_function(const rapidjson::Value& object, rapidjson::Value& result_value);

}
#endif //CONVERTING_FUNCTIONS_HPP