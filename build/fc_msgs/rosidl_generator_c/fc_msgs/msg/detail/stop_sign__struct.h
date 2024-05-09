// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from fc_msgs:msg/StopSign.idl
// generated code does not contain a copyright notice

#ifndef FC_MSGS__MSG__DETAIL__STOP_SIGN__STRUCT_H_
#define FC_MSGS__MSG__DETAIL__STOP_SIGN__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'bounding_box'
#include "sensor_msgs/msg/detail/image__struct.h"

// Struct defined in msg/StopSign in the package fc_msgs.
typedef struct fc_msgs__msg__StopSign
{
  bool is_stop;
  sensor_msgs__msg__Image bounding_box;
} fc_msgs__msg__StopSign;

// Struct for a sequence of fc_msgs__msg__StopSign.
typedef struct fc_msgs__msg__StopSign__Sequence
{
  fc_msgs__msg__StopSign * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} fc_msgs__msg__StopSign__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FC_MSGS__MSG__DETAIL__STOP_SIGN__STRUCT_H_
