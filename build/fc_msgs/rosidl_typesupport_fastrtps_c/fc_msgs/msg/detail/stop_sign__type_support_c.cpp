// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from fc_msgs:msg/StopSign.idl
// generated code does not contain a copyright notice
#include "fc_msgs/msg/detail/stop_sign__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "fc_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "fc_msgs/msg/detail/stop_sign__struct.h"
#include "fc_msgs/msg/detail/stop_sign__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "sensor_msgs/msg/detail/image__functions.h"  // bounding_box

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_fc_msgs
size_t get_serialized_size_sensor_msgs__msg__Image(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_fc_msgs
size_t max_serialized_size_sensor_msgs__msg__Image(
  bool & full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_fc_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, sensor_msgs, msg, Image)();


using _StopSign__ros_msg_type = fc_msgs__msg__StopSign;

static bool _StopSign__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _StopSign__ros_msg_type * ros_message = static_cast<const _StopSign__ros_msg_type *>(untyped_ros_message);
  // Field name: is_stop
  {
    cdr << (ros_message->is_stop ? true : false);
  }

  // Field name: bounding_box
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, sensor_msgs, msg, Image
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->bounding_box, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _StopSign__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _StopSign__ros_msg_type * ros_message = static_cast<_StopSign__ros_msg_type *>(untyped_ros_message);
  // Field name: is_stop
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->is_stop = tmp ? true : false;
  }

  // Field name: bounding_box
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, sensor_msgs, msg, Image
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->bounding_box))
    {
      return false;
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_fc_msgs
size_t get_serialized_size_fc_msgs__msg__StopSign(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _StopSign__ros_msg_type * ros_message = static_cast<const _StopSign__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name is_stop
  {
    size_t item_size = sizeof(ros_message->is_stop);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name bounding_box

  current_alignment += get_serialized_size_sensor_msgs__msg__Image(
    &(ros_message->bounding_box), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _StopSign__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_fc_msgs__msg__StopSign(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_fc_msgs
size_t max_serialized_size_fc_msgs__msg__StopSign(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: is_stop
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: bounding_box
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_sensor_msgs__msg__Image(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _StopSign__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_fc_msgs__msg__StopSign(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_StopSign = {
  "fc_msgs::msg",
  "StopSign",
  _StopSign__cdr_serialize,
  _StopSign__cdr_deserialize,
  _StopSign__get_serialized_size,
  _StopSign__max_serialized_size
};

static rosidl_message_type_support_t _StopSign__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_StopSign,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, fc_msgs, msg, StopSign)() {
  return &_StopSign__type_support;
}

#if defined(__cplusplus)
}
#endif
