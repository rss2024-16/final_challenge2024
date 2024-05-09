// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from fc_msgs:msg/StopLightPixel.idl
// generated code does not contain a copyright notice

#ifndef FC_MSGS__MSG__DETAIL__STOP_LIGHT_PIXEL__STRUCT_H_
#define FC_MSGS__MSG__DETAIL__STOP_LIGHT_PIXEL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/StopLightPixel in the package fc_msgs.
typedef struct fc_msgs__msg__StopLightPixel
{
  float u;
  float v;
} fc_msgs__msg__StopLightPixel;

// Struct for a sequence of fc_msgs__msg__StopLightPixel.
typedef struct fc_msgs__msg__StopLightPixel__Sequence
{
  fc_msgs__msg__StopLightPixel * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} fc_msgs__msg__StopLightPixel__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FC_MSGS__MSG__DETAIL__STOP_LIGHT_PIXEL__STRUCT_H_
