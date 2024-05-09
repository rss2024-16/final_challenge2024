// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from fc_msgs:msg/StopLightPixel.idl
// generated code does not contain a copyright notice

#ifndef FC_MSGS__MSG__DETAIL__STOP_LIGHT_PIXEL__BUILDER_HPP_
#define FC_MSGS__MSG__DETAIL__STOP_LIGHT_PIXEL__BUILDER_HPP_

#include "fc_msgs/msg/detail/stop_light_pixel__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace fc_msgs
{

namespace msg
{

namespace builder
{

class Init_StopLightPixel_v
{
public:
  explicit Init_StopLightPixel_v(::fc_msgs::msg::StopLightPixel & msg)
  : msg_(msg)
  {}
  ::fc_msgs::msg::StopLightPixel v(::fc_msgs::msg::StopLightPixel::_v_type arg)
  {
    msg_.v = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fc_msgs::msg::StopLightPixel msg_;
};

class Init_StopLightPixel_u
{
public:
  Init_StopLightPixel_u()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_StopLightPixel_v u(::fc_msgs::msg::StopLightPixel::_u_type arg)
  {
    msg_.u = std::move(arg);
    return Init_StopLightPixel_v(msg_);
  }

private:
  ::fc_msgs::msg::StopLightPixel msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::fc_msgs::msg::StopLightPixel>()
{
  return fc_msgs::msg::builder::Init_StopLightPixel_u();
}

}  // namespace fc_msgs

#endif  // FC_MSGS__MSG__DETAIL__STOP_LIGHT_PIXEL__BUILDER_HPP_
