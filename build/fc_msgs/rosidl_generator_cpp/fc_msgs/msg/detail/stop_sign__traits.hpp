// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from fc_msgs:msg/StopSign.idl
// generated code does not contain a copyright notice

#ifndef FC_MSGS__MSG__DETAIL__STOP_SIGN__TRAITS_HPP_
#define FC_MSGS__MSG__DETAIL__STOP_SIGN__TRAITS_HPP_

#include "fc_msgs/msg/detail/stop_sign__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'bounding_box'
#include "sensor_msgs/msg/detail/image__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<fc_msgs::msg::StopSign>()
{
  return "fc_msgs::msg::StopSign";
}

template<>
inline const char * name<fc_msgs::msg::StopSign>()
{
  return "fc_msgs/msg/StopSign";
}

template<>
struct has_fixed_size<fc_msgs::msg::StopSign>
  : std::integral_constant<bool, has_fixed_size<sensor_msgs::msg::Image>::value> {};

template<>
struct has_bounded_size<fc_msgs::msg::StopSign>
  : std::integral_constant<bool, has_bounded_size<sensor_msgs::msg::Image>::value> {};

template<>
struct is_message<fc_msgs::msg::StopSign>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // FC_MSGS__MSG__DETAIL__STOP_SIGN__TRAITS_HPP_
