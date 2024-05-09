// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from fc_msgs:action/NavigateToPose.idl
// generated code does not contain a copyright notice

#ifndef FC_MSGS__ACTION__DETAIL__NAVIGATE_TO_POSE__BUILDER_HPP_
#define FC_MSGS__ACTION__DETAIL__NAVIGATE_TO_POSE__BUILDER_HPP_

#include "fc_msgs/action/detail/navigate_to_pose__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace fc_msgs
{

namespace action
{

namespace builder
{

class Init_NavigateToPose_Goal_follow_lane
{
public:
  explicit Init_NavigateToPose_Goal_follow_lane(::fc_msgs::action::NavigateToPose_Goal & msg)
  : msg_(msg)
  {}
  ::fc_msgs::action::NavigateToPose_Goal follow_lane(::fc_msgs::action::NavigateToPose_Goal::_follow_lane_type arg)
  {
    msg_.follow_lane = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fc_msgs::action::NavigateToPose_Goal msg_;
};

class Init_NavigateToPose_Goal_trajectory
{
public:
  Init_NavigateToPose_Goal_trajectory()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavigateToPose_Goal_follow_lane trajectory(::fc_msgs::action::NavigateToPose_Goal::_trajectory_type arg)
  {
    msg_.trajectory = std::move(arg);
    return Init_NavigateToPose_Goal_follow_lane(msg_);
  }

private:
  ::fc_msgs::action::NavigateToPose_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::fc_msgs::action::NavigateToPose_Goal>()
{
  return fc_msgs::action::builder::Init_NavigateToPose_Goal_trajectory();
}

}  // namespace fc_msgs


namespace fc_msgs
{

namespace action
{

namespace builder
{

class Init_NavigateToPose_Result_car_position
{
public:
  Init_NavigateToPose_Result_car_position()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::fc_msgs::action::NavigateToPose_Result car_position(::fc_msgs::action::NavigateToPose_Result::_car_position_type arg)
  {
    msg_.car_position = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fc_msgs::action::NavigateToPose_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::fc_msgs::action::NavigateToPose_Result>()
{
  return fc_msgs::action::builder::Init_NavigateToPose_Result_car_position();
}

}  // namespace fc_msgs


namespace fc_msgs
{

namespace action
{

namespace builder
{

class Init_NavigateToPose_Feedback_outcome
{
public:
  Init_NavigateToPose_Feedback_outcome()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::fc_msgs::action::NavigateToPose_Feedback outcome(::fc_msgs::action::NavigateToPose_Feedback::_outcome_type arg)
  {
    msg_.outcome = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fc_msgs::action::NavigateToPose_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::fc_msgs::action::NavigateToPose_Feedback>()
{
  return fc_msgs::action::builder::Init_NavigateToPose_Feedback_outcome();
}

}  // namespace fc_msgs


namespace fc_msgs
{

namespace action
{

namespace builder
{

class Init_NavigateToPose_SendGoal_Request_goal
{
public:
  explicit Init_NavigateToPose_SendGoal_Request_goal(::fc_msgs::action::NavigateToPose_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::fc_msgs::action::NavigateToPose_SendGoal_Request goal(::fc_msgs::action::NavigateToPose_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fc_msgs::action::NavigateToPose_SendGoal_Request msg_;
};

class Init_NavigateToPose_SendGoal_Request_goal_id
{
public:
  Init_NavigateToPose_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavigateToPose_SendGoal_Request_goal goal_id(::fc_msgs::action::NavigateToPose_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_NavigateToPose_SendGoal_Request_goal(msg_);
  }

private:
  ::fc_msgs::action::NavigateToPose_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::fc_msgs::action::NavigateToPose_SendGoal_Request>()
{
  return fc_msgs::action::builder::Init_NavigateToPose_SendGoal_Request_goal_id();
}

}  // namespace fc_msgs


namespace fc_msgs
{

namespace action
{

namespace builder
{

class Init_NavigateToPose_SendGoal_Response_stamp
{
public:
  explicit Init_NavigateToPose_SendGoal_Response_stamp(::fc_msgs::action::NavigateToPose_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::fc_msgs::action::NavigateToPose_SendGoal_Response stamp(::fc_msgs::action::NavigateToPose_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fc_msgs::action::NavigateToPose_SendGoal_Response msg_;
};

class Init_NavigateToPose_SendGoal_Response_accepted
{
public:
  Init_NavigateToPose_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavigateToPose_SendGoal_Response_stamp accepted(::fc_msgs::action::NavigateToPose_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_NavigateToPose_SendGoal_Response_stamp(msg_);
  }

private:
  ::fc_msgs::action::NavigateToPose_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::fc_msgs::action::NavigateToPose_SendGoal_Response>()
{
  return fc_msgs::action::builder::Init_NavigateToPose_SendGoal_Response_accepted();
}

}  // namespace fc_msgs


namespace fc_msgs
{

namespace action
{

namespace builder
{

class Init_NavigateToPose_GetResult_Request_goal_id
{
public:
  Init_NavigateToPose_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::fc_msgs::action::NavigateToPose_GetResult_Request goal_id(::fc_msgs::action::NavigateToPose_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fc_msgs::action::NavigateToPose_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::fc_msgs::action::NavigateToPose_GetResult_Request>()
{
  return fc_msgs::action::builder::Init_NavigateToPose_GetResult_Request_goal_id();
}

}  // namespace fc_msgs


namespace fc_msgs
{

namespace action
{

namespace builder
{

class Init_NavigateToPose_GetResult_Response_result
{
public:
  explicit Init_NavigateToPose_GetResult_Response_result(::fc_msgs::action::NavigateToPose_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::fc_msgs::action::NavigateToPose_GetResult_Response result(::fc_msgs::action::NavigateToPose_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fc_msgs::action::NavigateToPose_GetResult_Response msg_;
};

class Init_NavigateToPose_GetResult_Response_status
{
public:
  Init_NavigateToPose_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavigateToPose_GetResult_Response_result status(::fc_msgs::action::NavigateToPose_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_NavigateToPose_GetResult_Response_result(msg_);
  }

private:
  ::fc_msgs::action::NavigateToPose_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::fc_msgs::action::NavigateToPose_GetResult_Response>()
{
  return fc_msgs::action::builder::Init_NavigateToPose_GetResult_Response_status();
}

}  // namespace fc_msgs


namespace fc_msgs
{

namespace action
{

namespace builder
{

class Init_NavigateToPose_FeedbackMessage_feedback
{
public:
  explicit Init_NavigateToPose_FeedbackMessage_feedback(::fc_msgs::action::NavigateToPose_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::fc_msgs::action::NavigateToPose_FeedbackMessage feedback(::fc_msgs::action::NavigateToPose_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fc_msgs::action::NavigateToPose_FeedbackMessage msg_;
};

class Init_NavigateToPose_FeedbackMessage_goal_id
{
public:
  Init_NavigateToPose_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavigateToPose_FeedbackMessage_feedback goal_id(::fc_msgs::action::NavigateToPose_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_NavigateToPose_FeedbackMessage_feedback(msg_);
  }

private:
  ::fc_msgs::action::NavigateToPose_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::fc_msgs::action::NavigateToPose_FeedbackMessage>()
{
  return fc_msgs::action::builder::Init_NavigateToPose_FeedbackMessage_goal_id();
}

}  // namespace fc_msgs

#endif  // FC_MSGS__ACTION__DETAIL__NAVIGATE_TO_POSE__BUILDER_HPP_
