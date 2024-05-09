// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from fc_msgs:srv/LaneProject.idl
// generated code does not contain a copyright notice

#ifndef FC_MSGS__SRV__DETAIL__LANE_PROJECT__BUILDER_HPP_
#define FC_MSGS__SRV__DETAIL__LANE_PROJECT__BUILDER_HPP_

#include "fc_msgs/srv/detail/lane_project__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace fc_msgs
{

namespace srv
{

namespace builder
{

class Init_LaneProject_Request_right
{
public:
  explicit Init_LaneProject_Request_right(::fc_msgs::srv::LaneProject_Request & msg)
  : msg_(msg)
  {}
  ::fc_msgs::srv::LaneProject_Request right(::fc_msgs::srv::LaneProject_Request::_right_type arg)
  {
    msg_.right = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fc_msgs::srv::LaneProject_Request msg_;
};

class Init_LaneProject_Request_location
{
public:
  Init_LaneProject_Request_location()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LaneProject_Request_right location(::fc_msgs::srv::LaneProject_Request::_location_type arg)
  {
    msg_.location = std::move(arg);
    return Init_LaneProject_Request_right(msg_);
  }

private:
  ::fc_msgs::srv::LaneProject_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::fc_msgs::srv::LaneProject_Request>()
{
  return fc_msgs::srv::builder::Init_LaneProject_Request_location();
}

}  // namespace fc_msgs


namespace fc_msgs
{

namespace srv
{

namespace builder
{

class Init_LaneProject_Response_projection
{
public:
  Init_LaneProject_Response_projection()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::fc_msgs::srv::LaneProject_Response projection(::fc_msgs::srv::LaneProject_Response::_projection_type arg)
  {
    msg_.projection = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fc_msgs::srv::LaneProject_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::fc_msgs::srv::LaneProject_Response>()
{
  return fc_msgs::srv::builder::Init_LaneProject_Response_projection();
}

}  // namespace fc_msgs

#endif  // FC_MSGS__SRV__DETAIL__LANE_PROJECT__BUILDER_HPP_
