// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from fc_msgs:msg/StopLightLocation.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "fc_msgs/msg/detail/stop_light_location__rosidl_typesupport_introspection_c.h"
#include "fc_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "fc_msgs/msg/detail/stop_light_location__functions.h"
#include "fc_msgs/msg/detail/stop_light_location__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void StopLightLocation__rosidl_typesupport_introspection_c__StopLightLocation_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  fc_msgs__msg__StopLightLocation__init(message_memory);
}

void StopLightLocation__rosidl_typesupport_introspection_c__StopLightLocation_fini_function(void * message_memory)
{
  fc_msgs__msg__StopLightLocation__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember StopLightLocation__rosidl_typesupport_introspection_c__StopLightLocation_message_member_array[2] = {
  {
    "x_pos",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fc_msgs__msg__StopLightLocation, x_pos),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "y_pos",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fc_msgs__msg__StopLightLocation, y_pos),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers StopLightLocation__rosidl_typesupport_introspection_c__StopLightLocation_message_members = {
  "fc_msgs__msg",  // message namespace
  "StopLightLocation",  // message name
  2,  // number of fields
  sizeof(fc_msgs__msg__StopLightLocation),
  StopLightLocation__rosidl_typesupport_introspection_c__StopLightLocation_message_member_array,  // message members
  StopLightLocation__rosidl_typesupport_introspection_c__StopLightLocation_init_function,  // function to initialize message memory (memory has to be allocated)
  StopLightLocation__rosidl_typesupport_introspection_c__StopLightLocation_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t StopLightLocation__rosidl_typesupport_introspection_c__StopLightLocation_message_type_support_handle = {
  0,
  &StopLightLocation__rosidl_typesupport_introspection_c__StopLightLocation_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_fc_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fc_msgs, msg, StopLightLocation)() {
  if (!StopLightLocation__rosidl_typesupport_introspection_c__StopLightLocation_message_type_support_handle.typesupport_identifier) {
    StopLightLocation__rosidl_typesupport_introspection_c__StopLightLocation_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &StopLightLocation__rosidl_typesupport_introspection_c__StopLightLocation_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
