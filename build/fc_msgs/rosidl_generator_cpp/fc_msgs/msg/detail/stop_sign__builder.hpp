// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from fc_msgs:msg/StopSign.idl
// generated code does not contain a copyright notice

#ifndef FC_MSGS__MSG__DETAIL__STOP_SIGN__BUILDER_HPP_
#define FC_MSGS__MSG__DETAIL__STOP_SIGN__BUILDER_HPP_

#include "fc_msgs/msg/detail/stop_sign__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace fc_msgs
{

namespace msg
{

namespace builder
{

class Init_StopSign_bounding_box
{
public:
  explicit Init_StopSign_bounding_box(::fc_msgs::msg::StopSign & msg)
  : msg_(msg)
  {}
  ::fc_msgs::msg::StopSign bounding_box(::fc_msgs::msg::StopSign::_bounding_box_type arg)
  {
    msg_.bounding_box = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fc_msgs::msg::StopSign msg_;
};

class Init_StopSign_is_stop
{
public:
  Init_StopSign_is_stop()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_StopSign_bounding_box is_stop(::fc_msgs::msg::StopSign::_is_stop_type arg)
  {
    msg_.is_stop = std::move(arg);
    return Init_StopSign_bounding_box(msg_);
  }

private:
  ::fc_msgs::msg::StopSign msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::fc_msgs::msg::StopSign>()
{
  return fc_msgs::msg::builder::Init_StopSign_is_stop();
}

}  // namespace fc_msgs

#endif  // FC_MSGS__MSG__DETAIL__STOP_SIGN__BUILDER_HPP_
