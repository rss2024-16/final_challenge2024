// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from fc_msgs:srv/LaneProject.idl
// generated code does not contain a copyright notice

#ifndef FC_MSGS__SRV__DETAIL__LANE_PROJECT__TRAITS_HPP_
#define FC_MSGS__SRV__DETAIL__LANE_PROJECT__TRAITS_HPP_

#include "fc_msgs/srv/detail/lane_project__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'location'
#include "geometry_msgs/msg/detail/point_stamped__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<fc_msgs::srv::LaneProject_Request>()
{
  return "fc_msgs::srv::LaneProject_Request";
}

template<>
inline const char * name<fc_msgs::srv::LaneProject_Request>()
{
  return "fc_msgs/srv/LaneProject_Request";
}

template<>
struct has_fixed_size<fc_msgs::srv::LaneProject_Request>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::PointStamped>::value> {};

template<>
struct has_bounded_size<fc_msgs::srv::LaneProject_Request>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::PointStamped>::value> {};

template<>
struct is_message<fc_msgs::srv::LaneProject_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'projection'
#include "geometry_msgs/msg/detail/pose__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<fc_msgs::srv::LaneProject_Response>()
{
  return "fc_msgs::srv::LaneProject_Response";
}

template<>
inline const char * name<fc_msgs::srv::LaneProject_Response>()
{
  return "fc_msgs/srv/LaneProject_Response";
}

template<>
struct has_fixed_size<fc_msgs::srv::LaneProject_Response>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Pose>::value> {};

template<>
struct has_bounded_size<fc_msgs::srv::LaneProject_Response>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Pose>::value> {};

template<>
struct is_message<fc_msgs::srv::LaneProject_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<fc_msgs::srv::LaneProject>()
{
  return "fc_msgs::srv::LaneProject";
}

template<>
inline const char * name<fc_msgs::srv::LaneProject>()
{
  return "fc_msgs/srv/LaneProject";
}

template<>
struct has_fixed_size<fc_msgs::srv::LaneProject>
  : std::integral_constant<
    bool,
    has_fixed_size<fc_msgs::srv::LaneProject_Request>::value &&
    has_fixed_size<fc_msgs::srv::LaneProject_Response>::value
  >
{
};

template<>
struct has_bounded_size<fc_msgs::srv::LaneProject>
  : std::integral_constant<
    bool,
    has_bounded_size<fc_msgs::srv::LaneProject_Request>::value &&
    has_bounded_size<fc_msgs::srv::LaneProject_Response>::value
  >
{
};

template<>
struct is_service<fc_msgs::srv::LaneProject>
  : std::true_type
{
};

template<>
struct is_service_request<fc_msgs::srv::LaneProject_Request>
  : std::true_type
{
};

template<>
struct is_service_response<fc_msgs::srv::LaneProject_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // FC_MSGS__SRV__DETAIL__LANE_PROJECT__TRAITS_HPP_
