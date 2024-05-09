// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from fc_msgs:srv/LaneProject.idl
// generated code does not contain a copyright notice

#ifndef FC_MSGS__SRV__DETAIL__LANE_PROJECT__STRUCT_HPP_
#define FC_MSGS__SRV__DETAIL__LANE_PROJECT__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'location'
#include "geometry_msgs/msg/detail/point_stamped__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__fc_msgs__srv__LaneProject_Request __attribute__((deprecated))
#else
# define DEPRECATED__fc_msgs__srv__LaneProject_Request __declspec(deprecated)
#endif

namespace fc_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct LaneProject_Request_
{
  using Type = LaneProject_Request_<ContainerAllocator>;

  explicit LaneProject_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : location(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->right = false;
    }
  }

  explicit LaneProject_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : location(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->right = false;
    }
  }

  // field types and members
  using _location_type =
    geometry_msgs::msg::PointStamped_<ContainerAllocator>;
  _location_type location;
  using _right_type =
    bool;
  _right_type right;

  // setters for named parameter idiom
  Type & set__location(
    const geometry_msgs::msg::PointStamped_<ContainerAllocator> & _arg)
  {
    this->location = _arg;
    return *this;
  }
  Type & set__right(
    const bool & _arg)
  {
    this->right = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    fc_msgs::srv::LaneProject_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const fc_msgs::srv::LaneProject_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<fc_msgs::srv::LaneProject_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<fc_msgs::srv::LaneProject_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      fc_msgs::srv::LaneProject_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<fc_msgs::srv::LaneProject_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      fc_msgs::srv::LaneProject_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<fc_msgs::srv::LaneProject_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<fc_msgs::srv::LaneProject_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<fc_msgs::srv::LaneProject_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__fc_msgs__srv__LaneProject_Request
    std::shared_ptr<fc_msgs::srv::LaneProject_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__fc_msgs__srv__LaneProject_Request
    std::shared_ptr<fc_msgs::srv::LaneProject_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LaneProject_Request_ & other) const
  {
    if (this->location != other.location) {
      return false;
    }
    if (this->right != other.right) {
      return false;
    }
    return true;
  }
  bool operator!=(const LaneProject_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LaneProject_Request_

// alias to use template instance with default allocator
using LaneProject_Request =
  fc_msgs::srv::LaneProject_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace fc_msgs


// Include directives for member types
// Member 'projection'
#include "geometry_msgs/msg/detail/pose__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__fc_msgs__srv__LaneProject_Response __attribute__((deprecated))
#else
# define DEPRECATED__fc_msgs__srv__LaneProject_Response __declspec(deprecated)
#endif

namespace fc_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct LaneProject_Response_
{
  using Type = LaneProject_Response_<ContainerAllocator>;

  explicit LaneProject_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : projection(_init)
  {
    (void)_init;
  }

  explicit LaneProject_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : projection(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _projection_type =
    geometry_msgs::msg::Pose_<ContainerAllocator>;
  _projection_type projection;

  // setters for named parameter idiom
  Type & set__projection(
    const geometry_msgs::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->projection = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    fc_msgs::srv::LaneProject_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const fc_msgs::srv::LaneProject_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<fc_msgs::srv::LaneProject_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<fc_msgs::srv::LaneProject_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      fc_msgs::srv::LaneProject_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<fc_msgs::srv::LaneProject_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      fc_msgs::srv::LaneProject_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<fc_msgs::srv::LaneProject_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<fc_msgs::srv::LaneProject_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<fc_msgs::srv::LaneProject_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__fc_msgs__srv__LaneProject_Response
    std::shared_ptr<fc_msgs::srv::LaneProject_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__fc_msgs__srv__LaneProject_Response
    std::shared_ptr<fc_msgs::srv::LaneProject_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LaneProject_Response_ & other) const
  {
    if (this->projection != other.projection) {
      return false;
    }
    return true;
  }
  bool operator!=(const LaneProject_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LaneProject_Response_

// alias to use template instance with default allocator
using LaneProject_Response =
  fc_msgs::srv::LaneProject_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace fc_msgs

namespace fc_msgs
{

namespace srv
{

struct LaneProject
{
  using Request = fc_msgs::srv::LaneProject_Request;
  using Response = fc_msgs::srv::LaneProject_Response;
};

}  // namespace srv

}  // namespace fc_msgs

#endif  // FC_MSGS__SRV__DETAIL__LANE_PROJECT__STRUCT_HPP_
