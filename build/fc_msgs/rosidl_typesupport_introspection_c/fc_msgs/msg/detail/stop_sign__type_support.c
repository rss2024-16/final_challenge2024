// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from fc_msgs:msg/StopSign.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "fc_msgs/msg/detail/stop_sign__rosidl_typesupport_introspection_c.h"
#include "fc_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "fc_msgs/msg/detail/stop_sign__functions.h"
#include "fc_msgs/msg/detail/stop_sign__struct.h"


// Include directives for member types
// Member `bounding_box`
#include "sensor_msgs/msg/image.h"
// Member `bounding_box`
#include "sensor_msgs/msg/detail/image__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void StopSign__rosidl_typesupport_introspection_c__StopSign_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  fc_msgs__msg__StopSign__init(message_memory);
}

void StopSign__rosidl_typesupport_introspection_c__StopSign_fini_function(void * message_memory)
{
  fc_msgs__msg__StopSign__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember StopSign__rosidl_typesupport_introspection_c__StopSign_message_member_array[2] = {
  {
    "is_stop",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fc_msgs__msg__StopSign, is_stop),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "bounding_box",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fc_msgs__msg__StopSign, bounding_box),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers StopSign__rosidl_typesupport_introspection_c__StopSign_message_members = {
  "fc_msgs__msg",  // message namespace
  "StopSign",  // message name
  2,  // number of fields
  sizeof(fc_msgs__msg__StopSign),
  StopSign__rosidl_typesupport_introspection_c__StopSign_message_member_array,  // message members
  StopSign__rosidl_typesupport_introspection_c__StopSign_init_function,  // function to initialize message memory (memory has to be allocated)
  StopSign__rosidl_typesupport_introspection_c__StopSign_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t StopSign__rosidl_typesupport_introspection_c__StopSign_message_type_support_handle = {
  0,
  &StopSign__rosidl_typesupport_introspection_c__StopSign_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_fc_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fc_msgs, msg, StopSign)() {
  StopSign__rosidl_typesupport_introspection_c__StopSign_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, Image)();
  if (!StopSign__rosidl_typesupport_introspection_c__StopSign_message_type_support_handle.typesupport_identifier) {
    StopSign__rosidl_typesupport_introspection_c__StopSign_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &StopSign__rosidl_typesupport_introspection_c__StopSign_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
