// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from fc_msgs:action/FindPath.idl
// generated code does not contain a copyright notice

#ifndef FC_MSGS__ACTION__DETAIL__FIND_PATH__TRAITS_HPP_
#define FC_MSGS__ACTION__DETAIL__FIND_PATH__TRAITS_HPP_

#include "fc_msgs/action/detail/find_path__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 's_and_t'
#include "geometry_msgs/msg/detail/pose_array__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<fc_msgs::action::FindPath_Goal>()
{
  return "fc_msgs::action::FindPath_Goal";
}

template<>
inline const char * name<fc_msgs::action::FindPath_Goal>()
{
  return "fc_msgs/action/FindPath_Goal";
}

template<>
struct has_fixed_size<fc_msgs::action::FindPath_Goal>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::PoseArray>::value> {};

template<>
struct has_bounded_size<fc_msgs::action::FindPath_Goal>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::PoseArray>::value> {};

template<>
struct is_message<fc_msgs::action::FindPath_Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'trajectory'
// already included above
// #include "geometry_msgs/msg/detail/pose_array__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<fc_msgs::action::FindPath_Result>()
{
  return "fc_msgs::action::FindPath_Result";
}

template<>
inline const char * name<fc_msgs::action::FindPath_Result>()
{
  return "fc_msgs/action/FindPath_Result";
}

template<>
struct has_fixed_size<fc_msgs::action::FindPath_Result>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::PoseArray>::value> {};

template<>
struct has_bounded_size<fc_msgs::action::FindPath_Result>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::PoseArray>::value> {};

template<>
struct is_message<fc_msgs::action::FindPath_Result>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<fc_msgs::action::FindPath_Feedback>()
{
  return "fc_msgs::action::FindPath_Feedback";
}

template<>
inline const char * name<fc_msgs::action::FindPath_Feedback>()
{
  return "fc_msgs/action/FindPath_Feedback";
}

template<>
struct has_fixed_size<fc_msgs::action::FindPath_Feedback>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<fc_msgs::action::FindPath_Feedback>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<fc_msgs::action::FindPath_Feedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'goal'
#include "fc_msgs/action/detail/find_path__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<fc_msgs::action::FindPath_SendGoal_Request>()
{
  return "fc_msgs::action::FindPath_SendGoal_Request";
}

template<>
inline const char * name<fc_msgs::action::FindPath_SendGoal_Request>()
{
  return "fc_msgs/action/FindPath_SendGoal_Request";
}

template<>
struct has_fixed_size<fc_msgs::action::FindPath_SendGoal_Request>
  : std::integral_constant<bool, has_fixed_size<fc_msgs::action::FindPath_Goal>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<fc_msgs::action::FindPath_SendGoal_Request>
  : std::integral_constant<bool, has_bounded_size<fc_msgs::action::FindPath_Goal>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<fc_msgs::action::FindPath_SendGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<fc_msgs::action::FindPath_SendGoal_Response>()
{
  return "fc_msgs::action::FindPath_SendGoal_Response";
}

template<>
inline const char * name<fc_msgs::action::FindPath_SendGoal_Response>()
{
  return "fc_msgs/action/FindPath_SendGoal_Response";
}

template<>
struct has_fixed_size<fc_msgs::action::FindPath_SendGoal_Response>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<fc_msgs::action::FindPath_SendGoal_Response>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<fc_msgs::action::FindPath_SendGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<fc_msgs::action::FindPath_SendGoal>()
{
  return "fc_msgs::action::FindPath_SendGoal";
}

template<>
inline const char * name<fc_msgs::action::FindPath_SendGoal>()
{
  return "fc_msgs/action/FindPath_SendGoal";
}

template<>
struct has_fixed_size<fc_msgs::action::FindPath_SendGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<fc_msgs::action::FindPath_SendGoal_Request>::value &&
    has_fixed_size<fc_msgs::action::FindPath_SendGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<fc_msgs::action::FindPath_SendGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<fc_msgs::action::FindPath_SendGoal_Request>::value &&
    has_bounded_size<fc_msgs::action::FindPath_SendGoal_Response>::value
  >
{
};

template<>
struct is_service<fc_msgs::action::FindPath_SendGoal>
  : std::true_type
{
};

template<>
struct is_service_request<fc_msgs::action::FindPath_SendGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<fc_msgs::action::FindPath_SendGoal_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<fc_msgs::action::FindPath_GetResult_Request>()
{
  return "fc_msgs::action::FindPath_GetResult_Request";
}

template<>
inline const char * name<fc_msgs::action::FindPath_GetResult_Request>()
{
  return "fc_msgs/action/FindPath_GetResult_Request";
}

template<>
struct has_fixed_size<fc_msgs::action::FindPath_GetResult_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<fc_msgs::action::FindPath_GetResult_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<fc_msgs::action::FindPath_GetResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
// already included above
// #include "fc_msgs/action/detail/find_path__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<fc_msgs::action::FindPath_GetResult_Response>()
{
  return "fc_msgs::action::FindPath_GetResult_Response";
}

template<>
inline const char * name<fc_msgs::action::FindPath_GetResult_Response>()
{
  return "fc_msgs/action/FindPath_GetResult_Response";
}

template<>
struct has_fixed_size<fc_msgs::action::FindPath_GetResult_Response>
  : std::integral_constant<bool, has_fixed_size<fc_msgs::action::FindPath_Result>::value> {};

template<>
struct has_bounded_size<fc_msgs::action::FindPath_GetResult_Response>
  : std::integral_constant<bool, has_bounded_size<fc_msgs::action::FindPath_Result>::value> {};

template<>
struct is_message<fc_msgs::action::FindPath_GetResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<fc_msgs::action::FindPath_GetResult>()
{
  return "fc_msgs::action::FindPath_GetResult";
}

template<>
inline const char * name<fc_msgs::action::FindPath_GetResult>()
{
  return "fc_msgs/action/FindPath_GetResult";
}

template<>
struct has_fixed_size<fc_msgs::action::FindPath_GetResult>
  : std::integral_constant<
    bool,
    has_fixed_size<fc_msgs::action::FindPath_GetResult_Request>::value &&
    has_fixed_size<fc_msgs::action::FindPath_GetResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<fc_msgs::action::FindPath_GetResult>
  : std::integral_constant<
    bool,
    has_bounded_size<fc_msgs::action::FindPath_GetResult_Request>::value &&
    has_bounded_size<fc_msgs::action::FindPath_GetResult_Response>::value
  >
{
};

template<>
struct is_service<fc_msgs::action::FindPath_GetResult>
  : std::true_type
{
};

template<>
struct is_service_request<fc_msgs::action::FindPath_GetResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<fc_msgs::action::FindPath_GetResult_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'feedback'
// already included above
// #include "fc_msgs/action/detail/find_path__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<fc_msgs::action::FindPath_FeedbackMessage>()
{
  return "fc_msgs::action::FindPath_FeedbackMessage";
}

template<>
inline const char * name<fc_msgs::action::FindPath_FeedbackMessage>()
{
  return "fc_msgs/action/FindPath_FeedbackMessage";
}

template<>
struct has_fixed_size<fc_msgs::action::FindPath_FeedbackMessage>
  : std::integral_constant<bool, has_fixed_size<fc_msgs::action::FindPath_Feedback>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<fc_msgs::action::FindPath_FeedbackMessage>
  : std::integral_constant<bool, has_bounded_size<fc_msgs::action::FindPath_Feedback>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<fc_msgs::action::FindPath_FeedbackMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits


namespace rosidl_generator_traits
{

template<>
struct is_action<fc_msgs::action::FindPath>
  : std::true_type
{
};

template<>
struct is_action_goal<fc_msgs::action::FindPath_Goal>
  : std::true_type
{
};

template<>
struct is_action_result<fc_msgs::action::FindPath_Result>
  : std::true_type
{
};

template<>
struct is_action_feedback<fc_msgs::action::FindPath_Feedback>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits


#endif  // FC_MSGS__ACTION__DETAIL__FIND_PATH__TRAITS_HPP_
