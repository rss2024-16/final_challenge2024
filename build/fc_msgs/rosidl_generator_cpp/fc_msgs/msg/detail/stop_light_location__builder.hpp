// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from fc_msgs:msg/StopLightLocation.idl
// generated code does not contain a copyright notice

#ifndef FC_MSGS__MSG__DETAIL__STOP_LIGHT_LOCATION__BUILDER_HPP_
#define FC_MSGS__MSG__DETAIL__STOP_LIGHT_LOCATION__BUILDER_HPP_

#include "fc_msgs/msg/detail/stop_light_location__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace fc_msgs
{

namespace msg
{

namespace builder
{

class Init_StopLightLocation_y_pos
{
public:
  explicit Init_StopLightLocation_y_pos(::fc_msgs::msg::StopLightLocation & msg)
  : msg_(msg)
  {}
  ::fc_msgs::msg::StopLightLocation y_pos(::fc_msgs::msg::StopLightLocation::_y_pos_type arg)
  {
    msg_.y_pos = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fc_msgs::msg::StopLightLocation msg_;
};

class Init_StopLightLocation_x_pos
{
public:
  Init_StopLightLocation_x_pos()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_StopLightLocation_y_pos x_pos(::fc_msgs::msg::StopLightLocation::_x_pos_type arg)
  {
    msg_.x_pos = std::move(arg);
    return Init_StopLightLocation_y_pos(msg_);
  }

private:
  ::fc_msgs::msg::StopLightLocation msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::fc_msgs::msg::StopLightLocation>()
{
  return fc_msgs::msg::builder::Init_StopLightLocation_x_pos();
}

}  // namespace fc_msgs

#endif  // FC_MSGS__MSG__DETAIL__STOP_LIGHT_LOCATION__BUILDER_HPP_
