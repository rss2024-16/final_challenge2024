// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from fc_msgs:msg/StopSign.idl
// generated code does not contain a copyright notice

#ifndef FC_MSGS__MSG__DETAIL__STOP_SIGN__STRUCT_HPP_
#define FC_MSGS__MSG__DETAIL__STOP_SIGN__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'bounding_box'
#include "sensor_msgs/msg/detail/image__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__fc_msgs__msg__StopSign __attribute__((deprecated))
#else
# define DEPRECATED__fc_msgs__msg__StopSign __declspec(deprecated)
#endif

namespace fc_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct StopSign_
{
  using Type = StopSign_<ContainerAllocator>;

  explicit StopSign_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : bounding_box(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->is_stop = false;
    }
  }

  explicit StopSign_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : bounding_box(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->is_stop = false;
    }
  }

  // field types and members
  using _is_stop_type =
    bool;
  _is_stop_type is_stop;
  using _bounding_box_type =
    sensor_msgs::msg::Image_<ContainerAllocator>;
  _bounding_box_type bounding_box;

  // setters for named parameter idiom
  Type & set__is_stop(
    const bool & _arg)
  {
    this->is_stop = _arg;
    return *this;
  }
  Type & set__bounding_box(
    const sensor_msgs::msg::Image_<ContainerAllocator> & _arg)
  {
    this->bounding_box = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    fc_msgs::msg::StopSign_<ContainerAllocator> *;
  using ConstRawPtr =
    const fc_msgs::msg::StopSign_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<fc_msgs::msg::StopSign_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<fc_msgs::msg::StopSign_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      fc_msgs::msg::StopSign_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<fc_msgs::msg::StopSign_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      fc_msgs::msg::StopSign_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<fc_msgs::msg::StopSign_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<fc_msgs::msg::StopSign_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<fc_msgs::msg::StopSign_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__fc_msgs__msg__StopSign
    std::shared_ptr<fc_msgs::msg::StopSign_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__fc_msgs__msg__StopSign
    std::shared_ptr<fc_msgs::msg::StopSign_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const StopSign_ & other) const
  {
    if (this->is_stop != other.is_stop) {
      return false;
    }
    if (this->bounding_box != other.bounding_box) {
      return false;
    }
    return true;
  }
  bool operator!=(const StopSign_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct StopSign_

// alias to use template instance with default allocator
using StopSign =
  fc_msgs::msg::StopSign_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace fc_msgs

#endif  // FC_MSGS__MSG__DETAIL__STOP_SIGN__STRUCT_HPP_
