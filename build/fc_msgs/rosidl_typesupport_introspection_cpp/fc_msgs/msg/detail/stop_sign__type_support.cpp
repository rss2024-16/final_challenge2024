// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from fc_msgs:msg/StopSign.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "fc_msgs/msg/detail/stop_sign__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace fc_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void StopSign_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) fc_msgs::msg::StopSign(_init);
}

void StopSign_fini_function(void * message_memory)
{
  auto typed_message = static_cast<fc_msgs::msg::StopSign *>(message_memory);
  typed_message->~StopSign();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember StopSign_message_member_array[2] = {
  {
    "is_stop",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fc_msgs::msg::StopSign, is_stop),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "bounding_box",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<sensor_msgs::msg::Image>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fc_msgs::msg::StopSign, bounding_box),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers StopSign_message_members = {
  "fc_msgs::msg",  // message namespace
  "StopSign",  // message name
  2,  // number of fields
  sizeof(fc_msgs::msg::StopSign),
  StopSign_message_member_array,  // message members
  StopSign_init_function,  // function to initialize message memory (memory has to be allocated)
  StopSign_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t StopSign_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &StopSign_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace fc_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<fc_msgs::msg::StopSign>()
{
  return &::fc_msgs::msg::rosidl_typesupport_introspection_cpp::StopSign_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, fc_msgs, msg, StopSign)() {
  return &::fc_msgs::msg::rosidl_typesupport_introspection_cpp::StopSign_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
