// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from fc_msgs:msg/StopSign.idl
// generated code does not contain a copyright notice
#include "fc_msgs/msg/detail/stop_sign__rosidl_typesupport_fastrtps_cpp.hpp"
#include "fc_msgs/msg/detail/stop_sign__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace sensor_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const sensor_msgs::msg::Image &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  sensor_msgs::msg::Image &);
size_t get_serialized_size(
  const sensor_msgs::msg::Image &,
  size_t current_alignment);
size_t
max_serialized_size_Image(
  bool & full_bounded,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace sensor_msgs


namespace fc_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_fc_msgs
cdr_serialize(
  const fc_msgs::msg::StopSign & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: is_stop
  cdr << (ros_message.is_stop ? true : false);
  // Member: bounding_box
  sensor_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.bounding_box,
    cdr);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_fc_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  fc_msgs::msg::StopSign & ros_message)
{
  // Member: is_stop
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.is_stop = tmp ? true : false;
  }

  // Member: bounding_box
  sensor_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.bounding_box);

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_fc_msgs
get_serialized_size(
  const fc_msgs::msg::StopSign & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: is_stop
  {
    size_t item_size = sizeof(ros_message.is_stop);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: bounding_box

  current_alignment +=
    sensor_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.bounding_box, current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_fc_msgs
max_serialized_size_StopSign(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: is_stop
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: bounding_box
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        sensor_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Image(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static bool _StopSign__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const fc_msgs::msg::StopSign *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _StopSign__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<fc_msgs::msg::StopSign *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _StopSign__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const fc_msgs::msg::StopSign *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _StopSign__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_StopSign(full_bounded, 0);
}

static message_type_support_callbacks_t _StopSign__callbacks = {
  "fc_msgs::msg",
  "StopSign",
  _StopSign__cdr_serialize,
  _StopSign__cdr_deserialize,
  _StopSign__get_serialized_size,
  _StopSign__max_serialized_size
};

static rosidl_message_type_support_t _StopSign__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_StopSign__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace fc_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_fc_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<fc_msgs::msg::StopSign>()
{
  return &fc_msgs::msg::typesupport_fastrtps_cpp::_StopSign__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, fc_msgs, msg, StopSign)() {
  return &fc_msgs::msg::typesupport_fastrtps_cpp::_StopSign__handle;
}

#ifdef __cplusplus
}
#endif
