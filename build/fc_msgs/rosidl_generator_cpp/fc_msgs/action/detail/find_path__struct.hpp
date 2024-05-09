// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from fc_msgs:action/FindPath.idl
// generated code does not contain a copyright notice

#ifndef FC_MSGS__ACTION__DETAIL__FIND_PATH__STRUCT_HPP_
#define FC_MSGS__ACTION__DETAIL__FIND_PATH__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 's_and_t'
#include "geometry_msgs/msg/detail/pose_array__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__fc_msgs__action__FindPath_Goal __attribute__((deprecated))
#else
# define DEPRECATED__fc_msgs__action__FindPath_Goal __declspec(deprecated)
#endif

namespace fc_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct FindPath_Goal_
{
  using Type = FindPath_Goal_<ContainerAllocator>;

  explicit FindPath_Goal_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : s_and_t(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->follow_lane = false;
      this->right = false;
    }
  }

  explicit FindPath_Goal_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : s_and_t(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->follow_lane = false;
      this->right = false;
    }
  }

  // field types and members
  using _s_and_t_type =
    geometry_msgs::msg::PoseArray_<ContainerAllocator>;
  _s_and_t_type s_and_t;
  using _follow_lane_type =
    bool;
  _follow_lane_type follow_lane;
  using _right_type =
    bool;
  _right_type right;

  // setters for named parameter idiom
  Type & set__s_and_t(
    const geometry_msgs::msg::PoseArray_<ContainerAllocator> & _arg)
  {
    this->s_and_t = _arg;
    return *this;
  }
  Type & set__follow_lane(
    const bool & _arg)
  {
    this->follow_lane = _arg;
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
    fc_msgs::action::FindPath_Goal_<ContainerAllocator> *;
  using ConstRawPtr =
    const fc_msgs::action::FindPath_Goal_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<fc_msgs::action::FindPath_Goal_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<fc_msgs::action::FindPath_Goal_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      fc_msgs::action::FindPath_Goal_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<fc_msgs::action::FindPath_Goal_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      fc_msgs::action::FindPath_Goal_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<fc_msgs::action::FindPath_Goal_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<fc_msgs::action::FindPath_Goal_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<fc_msgs::action::FindPath_Goal_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__fc_msgs__action__FindPath_Goal
    std::shared_ptr<fc_msgs::action::FindPath_Goal_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__fc_msgs__action__FindPath_Goal
    std::shared_ptr<fc_msgs::action::FindPath_Goal_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FindPath_Goal_ & other) const
  {
    if (this->s_and_t != other.s_and_t) {
      return false;
    }
    if (this->follow_lane != other.follow_lane) {
      return false;
    }
    if (this->right != other.right) {
      return false;
    }
    return true;
  }
  bool operator!=(const FindPath_Goal_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FindPath_Goal_

// alias to use template instance with default allocator
using FindPath_Goal =
  fc_msgs::action::FindPath_Goal_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace fc_msgs


// Include directives for member types
// Member 'trajectory'
// already included above
// #include "geometry_msgs/msg/detail/pose_array__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__fc_msgs__action__FindPath_Result __attribute__((deprecated))
#else
# define DEPRECATED__fc_msgs__action__FindPath_Result __declspec(deprecated)
#endif

namespace fc_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct FindPath_Result_
{
  using Type = FindPath_Result_<ContainerAllocator>;

  explicit FindPath_Result_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : trajectory(_init)
  {
    (void)_init;
  }

  explicit FindPath_Result_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : trajectory(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _trajectory_type =
    geometry_msgs::msg::PoseArray_<ContainerAllocator>;
  _trajectory_type trajectory;

  // setters for named parameter idiom
  Type & set__trajectory(
    const geometry_msgs::msg::PoseArray_<ContainerAllocator> & _arg)
  {
    this->trajectory = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    fc_msgs::action::FindPath_Result_<ContainerAllocator> *;
  using ConstRawPtr =
    const fc_msgs::action::FindPath_Result_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<fc_msgs::action::FindPath_Result_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<fc_msgs::action::FindPath_Result_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      fc_msgs::action::FindPath_Result_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<fc_msgs::action::FindPath_Result_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      fc_msgs::action::FindPath_Result_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<fc_msgs::action::FindPath_Result_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<fc_msgs::action::FindPath_Result_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<fc_msgs::action::FindPath_Result_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__fc_msgs__action__FindPath_Result
    std::shared_ptr<fc_msgs::action::FindPath_Result_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__fc_msgs__action__FindPath_Result
    std::shared_ptr<fc_msgs::action::FindPath_Result_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FindPath_Result_ & other) const
  {
    if (this->trajectory != other.trajectory) {
      return false;
    }
    return true;
  }
  bool operator!=(const FindPath_Result_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FindPath_Result_

// alias to use template instance with default allocator
using FindPath_Result =
  fc_msgs::action::FindPath_Result_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace fc_msgs


#ifndef _WIN32
# define DEPRECATED__fc_msgs__action__FindPath_Feedback __attribute__((deprecated))
#else
# define DEPRECATED__fc_msgs__action__FindPath_Feedback __declspec(deprecated)
#endif

namespace fc_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct FindPath_Feedback_
{
  using Type = FindPath_Feedback_<ContainerAllocator>;

  explicit FindPath_Feedback_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->outcome = "";
    }
  }

  explicit FindPath_Feedback_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : outcome(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->outcome = "";
    }
  }

  // field types and members
  using _outcome_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _outcome_type outcome;

  // setters for named parameter idiom
  Type & set__outcome(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->outcome = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    fc_msgs::action::FindPath_Feedback_<ContainerAllocator> *;
  using ConstRawPtr =
    const fc_msgs::action::FindPath_Feedback_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<fc_msgs::action::FindPath_Feedback_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<fc_msgs::action::FindPath_Feedback_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      fc_msgs::action::FindPath_Feedback_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<fc_msgs::action::FindPath_Feedback_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      fc_msgs::action::FindPath_Feedback_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<fc_msgs::action::FindPath_Feedback_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<fc_msgs::action::FindPath_Feedback_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<fc_msgs::action::FindPath_Feedback_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__fc_msgs__action__FindPath_Feedback
    std::shared_ptr<fc_msgs::action::FindPath_Feedback_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__fc_msgs__action__FindPath_Feedback
    std::shared_ptr<fc_msgs::action::FindPath_Feedback_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FindPath_Feedback_ & other) const
  {
    if (this->outcome != other.outcome) {
      return false;
    }
    return true;
  }
  bool operator!=(const FindPath_Feedback_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FindPath_Feedback_

// alias to use template instance with default allocator
using FindPath_Feedback =
  fc_msgs::action::FindPath_Feedback_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace fc_msgs


// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'goal'
#include "fc_msgs/action/detail/find_path__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__fc_msgs__action__FindPath_SendGoal_Request __attribute__((deprecated))
#else
# define DEPRECATED__fc_msgs__action__FindPath_SendGoal_Request __declspec(deprecated)
#endif

namespace fc_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct FindPath_SendGoal_Request_
{
  using Type = FindPath_SendGoal_Request_<ContainerAllocator>;

  explicit FindPath_SendGoal_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    goal(_init)
  {
    (void)_init;
  }

  explicit FindPath_SendGoal_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    goal(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _goal_type =
    fc_msgs::action::FindPath_Goal_<ContainerAllocator>;
  _goal_type goal;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__goal(
    const fc_msgs::action::FindPath_Goal_<ContainerAllocator> & _arg)
  {
    this->goal = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    fc_msgs::action::FindPath_SendGoal_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const fc_msgs::action::FindPath_SendGoal_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<fc_msgs::action::FindPath_SendGoal_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<fc_msgs::action::FindPath_SendGoal_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      fc_msgs::action::FindPath_SendGoal_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<fc_msgs::action::FindPath_SendGoal_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      fc_msgs::action::FindPath_SendGoal_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<fc_msgs::action::FindPath_SendGoal_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<fc_msgs::action::FindPath_SendGoal_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<fc_msgs::action::FindPath_SendGoal_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__fc_msgs__action__FindPath_SendGoal_Request
    std::shared_ptr<fc_msgs::action::FindPath_SendGoal_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__fc_msgs__action__FindPath_SendGoal_Request
    std::shared_ptr<fc_msgs::action::FindPath_SendGoal_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FindPath_SendGoal_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->goal != other.goal) {
      return false;
    }
    return true;
  }
  bool operator!=(const FindPath_SendGoal_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FindPath_SendGoal_Request_

// alias to use template instance with default allocator
using FindPath_SendGoal_Request =
  fc_msgs::action::FindPath_SendGoal_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace fc_msgs


// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__fc_msgs__action__FindPath_SendGoal_Response __attribute__((deprecated))
#else
# define DEPRECATED__fc_msgs__action__FindPath_SendGoal_Response __declspec(deprecated)
#endif

namespace fc_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct FindPath_SendGoal_Response_
{
  using Type = FindPath_SendGoal_Response_<ContainerAllocator>;

  explicit FindPath_SendGoal_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  explicit FindPath_SendGoal_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  // field types and members
  using _accepted_type =
    bool;
  _accepted_type accepted;
  using _stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _stamp_type stamp;

  // setters for named parameter idiom
  Type & set__accepted(
    const bool & _arg)
  {
    this->accepted = _arg;
    return *this;
  }
  Type & set__stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->stamp = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    fc_msgs::action::FindPath_SendGoal_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const fc_msgs::action::FindPath_SendGoal_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<fc_msgs::action::FindPath_SendGoal_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<fc_msgs::action::FindPath_SendGoal_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      fc_msgs::action::FindPath_SendGoal_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<fc_msgs::action::FindPath_SendGoal_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      fc_msgs::action::FindPath_SendGoal_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<fc_msgs::action::FindPath_SendGoal_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<fc_msgs::action::FindPath_SendGoal_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<fc_msgs::action::FindPath_SendGoal_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__fc_msgs__action__FindPath_SendGoal_Response
    std::shared_ptr<fc_msgs::action::FindPath_SendGoal_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__fc_msgs__action__FindPath_SendGoal_Response
    std::shared_ptr<fc_msgs::action::FindPath_SendGoal_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FindPath_SendGoal_Response_ & other) const
  {
    if (this->accepted != other.accepted) {
      return false;
    }
    if (this->stamp != other.stamp) {
      return false;
    }
    return true;
  }
  bool operator!=(const FindPath_SendGoal_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FindPath_SendGoal_Response_

// alias to use template instance with default allocator
using FindPath_SendGoal_Response =
  fc_msgs::action::FindPath_SendGoal_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace fc_msgs

namespace fc_msgs
{

namespace action
{

struct FindPath_SendGoal
{
  using Request = fc_msgs::action::FindPath_SendGoal_Request;
  using Response = fc_msgs::action::FindPath_SendGoal_Response;
};

}  // namespace action

}  // namespace fc_msgs


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__fc_msgs__action__FindPath_GetResult_Request __attribute__((deprecated))
#else
# define DEPRECATED__fc_msgs__action__FindPath_GetResult_Request __declspec(deprecated)
#endif

namespace fc_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct FindPath_GetResult_Request_
{
  using Type = FindPath_GetResult_Request_<ContainerAllocator>;

  explicit FindPath_GetResult_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init)
  {
    (void)_init;
  }

  explicit FindPath_GetResult_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    fc_msgs::action::FindPath_GetResult_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const fc_msgs::action::FindPath_GetResult_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<fc_msgs::action::FindPath_GetResult_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<fc_msgs::action::FindPath_GetResult_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      fc_msgs::action::FindPath_GetResult_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<fc_msgs::action::FindPath_GetResult_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      fc_msgs::action::FindPath_GetResult_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<fc_msgs::action::FindPath_GetResult_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<fc_msgs::action::FindPath_GetResult_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<fc_msgs::action::FindPath_GetResult_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__fc_msgs__action__FindPath_GetResult_Request
    std::shared_ptr<fc_msgs::action::FindPath_GetResult_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__fc_msgs__action__FindPath_GetResult_Request
    std::shared_ptr<fc_msgs::action::FindPath_GetResult_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FindPath_GetResult_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const FindPath_GetResult_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FindPath_GetResult_Request_

// alias to use template instance with default allocator
using FindPath_GetResult_Request =
  fc_msgs::action::FindPath_GetResult_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace fc_msgs


// Include directives for member types
// Member 'result'
// already included above
// #include "fc_msgs/action/detail/find_path__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__fc_msgs__action__FindPath_GetResult_Response __attribute__((deprecated))
#else
# define DEPRECATED__fc_msgs__action__FindPath_GetResult_Response __declspec(deprecated)
#endif

namespace fc_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct FindPath_GetResult_Response_
{
  using Type = FindPath_GetResult_Response_<ContainerAllocator>;

  explicit FindPath_GetResult_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  explicit FindPath_GetResult_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  // field types and members
  using _status_type =
    int8_t;
  _status_type status;
  using _result_type =
    fc_msgs::action::FindPath_Result_<ContainerAllocator>;
  _result_type result;

  // setters for named parameter idiom
  Type & set__status(
    const int8_t & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__result(
    const fc_msgs::action::FindPath_Result_<ContainerAllocator> & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    fc_msgs::action::FindPath_GetResult_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const fc_msgs::action::FindPath_GetResult_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<fc_msgs::action::FindPath_GetResult_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<fc_msgs::action::FindPath_GetResult_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      fc_msgs::action::FindPath_GetResult_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<fc_msgs::action::FindPath_GetResult_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      fc_msgs::action::FindPath_GetResult_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<fc_msgs::action::FindPath_GetResult_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<fc_msgs::action::FindPath_GetResult_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<fc_msgs::action::FindPath_GetResult_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__fc_msgs__action__FindPath_GetResult_Response
    std::shared_ptr<fc_msgs::action::FindPath_GetResult_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__fc_msgs__action__FindPath_GetResult_Response
    std::shared_ptr<fc_msgs::action::FindPath_GetResult_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FindPath_GetResult_Response_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const FindPath_GetResult_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FindPath_GetResult_Response_

// alias to use template instance with default allocator
using FindPath_GetResult_Response =
  fc_msgs::action::FindPath_GetResult_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace fc_msgs

namespace fc_msgs
{

namespace action
{

struct FindPath_GetResult
{
  using Request = fc_msgs::action::FindPath_GetResult_Request;
  using Response = fc_msgs::action::FindPath_GetResult_Response;
};

}  // namespace action

}  // namespace fc_msgs


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'feedback'
// already included above
// #include "fc_msgs/action/detail/find_path__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__fc_msgs__action__FindPath_FeedbackMessage __attribute__((deprecated))
#else
# define DEPRECATED__fc_msgs__action__FindPath_FeedbackMessage __declspec(deprecated)
#endif

namespace fc_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct FindPath_FeedbackMessage_
{
  using Type = FindPath_FeedbackMessage_<ContainerAllocator>;

  explicit FindPath_FeedbackMessage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    feedback(_init)
  {
    (void)_init;
  }

  explicit FindPath_FeedbackMessage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    feedback(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _feedback_type =
    fc_msgs::action::FindPath_Feedback_<ContainerAllocator>;
  _feedback_type feedback;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__feedback(
    const fc_msgs::action::FindPath_Feedback_<ContainerAllocator> & _arg)
  {
    this->feedback = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    fc_msgs::action::FindPath_FeedbackMessage_<ContainerAllocator> *;
  using ConstRawPtr =
    const fc_msgs::action::FindPath_FeedbackMessage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<fc_msgs::action::FindPath_FeedbackMessage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<fc_msgs::action::FindPath_FeedbackMessage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      fc_msgs::action::FindPath_FeedbackMessage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<fc_msgs::action::FindPath_FeedbackMessage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      fc_msgs::action::FindPath_FeedbackMessage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<fc_msgs::action::FindPath_FeedbackMessage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<fc_msgs::action::FindPath_FeedbackMessage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<fc_msgs::action::FindPath_FeedbackMessage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__fc_msgs__action__FindPath_FeedbackMessage
    std::shared_ptr<fc_msgs::action::FindPath_FeedbackMessage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__fc_msgs__action__FindPath_FeedbackMessage
    std::shared_ptr<fc_msgs::action::FindPath_FeedbackMessage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FindPath_FeedbackMessage_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->feedback != other.feedback) {
      return false;
    }
    return true;
  }
  bool operator!=(const FindPath_FeedbackMessage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FindPath_FeedbackMessage_

// alias to use template instance with default allocator
using FindPath_FeedbackMessage =
  fc_msgs::action::FindPath_FeedbackMessage_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace fc_msgs

#include "action_msgs/srv/cancel_goal.hpp"
#include "action_msgs/msg/goal_info.hpp"
#include "action_msgs/msg/goal_status_array.hpp"

namespace fc_msgs
{

namespace action
{

struct FindPath
{
  /// The goal message defined in the action definition.
  using Goal = fc_msgs::action::FindPath_Goal;
  /// The result message defined in the action definition.
  using Result = fc_msgs::action::FindPath_Result;
  /// The feedback message defined in the action definition.
  using Feedback = fc_msgs::action::FindPath_Feedback;

  struct Impl
  {
    /// The send_goal service using a wrapped version of the goal message as a request.
    using SendGoalService = fc_msgs::action::FindPath_SendGoal;
    /// The get_result service using a wrapped version of the result message as a response.
    using GetResultService = fc_msgs::action::FindPath_GetResult;
    /// The feedback message with generic fields which wraps the feedback message.
    using FeedbackMessage = fc_msgs::action::FindPath_FeedbackMessage;

    /// The generic service to cancel a goal.
    using CancelGoalService = action_msgs::srv::CancelGoal;
    /// The generic message for the status of a goal.
    using GoalStatusMessage = action_msgs::msg::GoalStatusArray;
  };
};

typedef struct FindPath FindPath;

}  // namespace action

}  // namespace fc_msgs

#endif  // FC_MSGS__ACTION__DETAIL__FIND_PATH__STRUCT_HPP_
