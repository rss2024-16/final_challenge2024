// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from fc_msgs:msg/StopLightLocation.idl
// generated code does not contain a copyright notice

#ifndef FC_MSGS__MSG__DETAIL__STOP_LIGHT_LOCATION__STRUCT_HPP_
#define FC_MSGS__MSG__DETAIL__STOP_LIGHT_LOCATION__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__fc_msgs__msg__StopLightLocation __attribute__((deprecated))
#else
# define DEPRECATED__fc_msgs__msg__StopLightLocation __declspec(deprecated)
#endif

namespace fc_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct StopLightLocation_
{
  using Type = StopLightLocation_<ContainerAllocator>;

  explicit StopLightLocation_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x_pos = 0.0f;
      this->y_pos = 0.0f;
    }
  }

  explicit StopLightLocation_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x_pos = 0.0f;
      this->y_pos = 0.0f;
    }
  }

  // field types and members
  using _x_pos_type =
    float;
  _x_pos_type x_pos;
  using _y_pos_type =
    float;
  _y_pos_type y_pos;

  // setters for named parameter idiom
  Type & set__x_pos(
    const float & _arg)
  {
    this->x_pos = _arg;
    return *this;
  }
  Type & set__y_pos(
    const float & _arg)
  {
    this->y_pos = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    fc_msgs::msg::StopLightLocation_<ContainerAllocator> *;
  using ConstRawPtr =
    const fc_msgs::msg::StopLightLocation_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<fc_msgs::msg::StopLightLocation_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<fc_msgs::msg::StopLightLocation_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      fc_msgs::msg::StopLightLocation_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<fc_msgs::msg::StopLightLocation_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      fc_msgs::msg::StopLightLocation_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<fc_msgs::msg::StopLightLocation_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<fc_msgs::msg::StopLightLocation_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<fc_msgs::msg::StopLightLocation_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__fc_msgs__msg__StopLightLocation
    std::shared_ptr<fc_msgs::msg::StopLightLocation_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__fc_msgs__msg__StopLightLocation
    std::shared_ptr<fc_msgs::msg::StopLightLocation_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const StopLightLocation_ & other) const
  {
    if (this->x_pos != other.x_pos) {
      return false;
    }
    if (this->y_pos != other.y_pos) {
      return false;
    }
    return true;
  }
  bool operator!=(const StopLightLocation_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct StopLightLocation_

// alias to use template instance with default allocator
using StopLightLocation =
  fc_msgs::msg::StopLightLocation_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace fc_msgs

#endif  // FC_MSGS__MSG__DETAIL__STOP_LIGHT_LOCATION__STRUCT_HPP_
