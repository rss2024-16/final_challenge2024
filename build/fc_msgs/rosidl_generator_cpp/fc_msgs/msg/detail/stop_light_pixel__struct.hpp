// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from fc_msgs:msg/StopLightPixel.idl
// generated code does not contain a copyright notice

#ifndef FC_MSGS__MSG__DETAIL__STOP_LIGHT_PIXEL__STRUCT_HPP_
#define FC_MSGS__MSG__DETAIL__STOP_LIGHT_PIXEL__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__fc_msgs__msg__StopLightPixel __attribute__((deprecated))
#else
# define DEPRECATED__fc_msgs__msg__StopLightPixel __declspec(deprecated)
#endif

namespace fc_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct StopLightPixel_
{
  using Type = StopLightPixel_<ContainerAllocator>;

  explicit StopLightPixel_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->u = 0.0f;
      this->v = 0.0f;
    }
  }

  explicit StopLightPixel_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->u = 0.0f;
      this->v = 0.0f;
    }
  }

  // field types and members
  using _u_type =
    float;
  _u_type u;
  using _v_type =
    float;
  _v_type v;

  // setters for named parameter idiom
  Type & set__u(
    const float & _arg)
  {
    this->u = _arg;
    return *this;
  }
  Type & set__v(
    const float & _arg)
  {
    this->v = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    fc_msgs::msg::StopLightPixel_<ContainerAllocator> *;
  using ConstRawPtr =
    const fc_msgs::msg::StopLightPixel_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<fc_msgs::msg::StopLightPixel_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<fc_msgs::msg::StopLightPixel_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      fc_msgs::msg::StopLightPixel_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<fc_msgs::msg::StopLightPixel_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      fc_msgs::msg::StopLightPixel_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<fc_msgs::msg::StopLightPixel_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<fc_msgs::msg::StopLightPixel_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<fc_msgs::msg::StopLightPixel_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__fc_msgs__msg__StopLightPixel
    std::shared_ptr<fc_msgs::msg::StopLightPixel_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__fc_msgs__msg__StopLightPixel
    std::shared_ptr<fc_msgs::msg::StopLightPixel_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const StopLightPixel_ & other) const
  {
    if (this->u != other.u) {
      return false;
    }
    if (this->v != other.v) {
      return false;
    }
    return true;
  }
  bool operator!=(const StopLightPixel_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct StopLightPixel_

// alias to use template instance with default allocator
using StopLightPixel =
  fc_msgs::msg::StopLightPixel_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace fc_msgs

#endif  // FC_MSGS__MSG__DETAIL__STOP_LIGHT_PIXEL__STRUCT_HPP_
