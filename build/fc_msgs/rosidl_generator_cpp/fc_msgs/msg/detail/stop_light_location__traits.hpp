// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from fc_msgs:msg/StopLightLocation.idl
// generated code does not contain a copyright notice

#ifndef FC_MSGS__MSG__DETAIL__STOP_LIGHT_LOCATION__TRAITS_HPP_
#define FC_MSGS__MSG__DETAIL__STOP_LIGHT_LOCATION__TRAITS_HPP_

#include "fc_msgs/msg/detail/stop_light_location__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<fc_msgs::msg::StopLightLocation>()
{
  return "fc_msgs::msg::StopLightLocation";
}

template<>
inline const char * name<fc_msgs::msg::StopLightLocation>()
{
  return "fc_msgs/msg/StopLightLocation";
}

template<>
struct has_fixed_size<fc_msgs::msg::StopLightLocation>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<fc_msgs::msg::StopLightLocation>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<fc_msgs::msg::StopLightLocation>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // FC_MSGS__MSG__DETAIL__STOP_LIGHT_LOCATION__TRAITS_HPP_
