#ifndef CONVERTING_FUNCTIONS_HPP
#define CONVERTING_FUNCTIONS_HPP

#include <string>
#include <unordered_map>
#include <functional>

#include <rapidjson/document.h>

namespace converting_functions
{

/**
 * @brief the main convertion function that will be expected to be of type:
 * const rapidjson::Value&, rapidjson::Value& -> bool by the data convertor.
 * Changing the type of this function will cause the data server to throw an error on startup
 * 
 * @param object the original object to be  converted
 * @param result_value reference to the result value (might be an object or array) that should be created by the function
 * @param function_name the string representation of the function
 * @return true if the conversion could be done successfully
 * @return false if the conversion could not be done successfully
 */
bool convert (const rapidjson::Value& object, rapidjson::Value& result_value, const std::string& function_name);


/*************************************************************************************
                                    EXTERNAL SOURCE: BOB
*************************************************************************************/

/**
 * @brief function to convert the unit of the course from radians to degrees
 * 
 * @param object a generic value record that contains all fields from the source message instance. Accessable by iterator or Index
 * @param result_value generic value record where the value of the field to be changed should be written to.
 */
bool course_to_degrees(const rapidjson::Value& object, rapidjson::Value& result_value);

/**
 * @brief function to put the 'PL_' prefix to an id-value field
 * 
 * @param object the object that contains the input data
 * @param result_value the converted value
 * @return true if the id conversion was successfull
 * @return false if the id conversion was not successfull
 */
bool id_to_pl(const rapidjson::Value& object, rapidjson::Value& result_value);


/*************************************************************************************
                                    EXTERNAL SOURCE: OPENSIM-CMS
*************************************************************************************/

/**
* @brief function to contain the username field of the message with id 30
* 
* @param object the object that contains the input data
* @param result_value the converted username value
* @return true if the username conversion was successfull
* @return false if the username conversion was not successfull
*/
bool message_30_username(const rapidjson::Value& object, rapidjson::Value&  result_value);
}
#endif //CONVERTING_FUNCTIONS_HPP