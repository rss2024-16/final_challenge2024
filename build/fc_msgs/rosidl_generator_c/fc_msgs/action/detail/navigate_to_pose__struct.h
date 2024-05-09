// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from fc_msgs:action/NavigateToPose.idl
// generated code does not contain a copyright notice

#ifndef FC_MSGS__ACTION__DETAIL__NAVIGATE_TO_POSE__STRUCT_H_
#define FC_MSGS__ACTION__DETAIL__NAVIGATE_TO_POSE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'trajectory'
#include "geometry_msgs/msg/detail/pose_array__struct.h"

// Struct defined in action/NavigateToPose in the package fc_msgs.
typedef struct fc_msgs__action__NavigateToPose_Goal
{
  geometry_msgs__msg__PoseArray trajectory;
  bool follow_lane;
} fc_msgs__action__NavigateToPose_Goal;

// Struct for a sequence of fc_msgs__action__NavigateToPose_Goal.
typedef struct fc_msgs__action__NavigateToPose_Goal__Sequence
{
  fc_msgs__action__NavigateToPose_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} fc_msgs__action__NavigateToPose_Goal__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'car_position'
#include "geometry_msgs/msg/detail/pose__struct.h"

// Struct defined in action/NavigateToPose in the package fc_msgs.
typedef struct fc_msgs__action__NavigateToPose_Result
{
  geometry_msgs__msg__Pose car_position;
} fc_msgs__action__NavigateToPose_Result;

// Struct for a sequence of fc_msgs__action__NavigateToPose_Result.
typedef struct fc_msgs__action__NavigateToPose_Result__Sequence
{
  fc_msgs__action__NavigateToPose_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} fc_msgs__action__NavigateToPose_Result__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'outcome'
#include "rosidl_runtime_c/string.h"

// Struct defined in action/NavigateToPose in the package fc_msgs.
typedef struct fc_msgs__action__NavigateToPose_Feedback
{
  rosidl_runtime_c__String outcome;
} fc_msgs__action__NavigateToPose_Feedback;

// Struct for a sequence of fc_msgs__action__NavigateToPose_Feedback.
typedef struct fc_msgs__action__NavigateToPose_Feedback__Sequence
{
  fc_msgs__action__NavigateToPose_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} fc_msgs__action__NavigateToPose_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "fc_msgs/action/detail/navigate_to_pose__struct.h"

// Struct defined in action/NavigateToPose in the package fc_msgs.
typedef struct fc_msgs__action__NavigateToPose_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  fc_msgs__action__NavigateToPose_Goal goal;
} fc_msgs__action__NavigateToPose_SendGoal_Request;

// Struct for a sequence of fc_msgs__action__NavigateToPose_SendGoal_Request.
typedef struct fc_msgs__action__NavigateToPose_SendGoal_Request__Sequence
{
  fc_msgs__action__NavigateToPose_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} fc_msgs__action__NavigateToPose_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

// Struct defined in action/NavigateToPose in the package fc_msgs.
typedef struct fc_msgs__action__NavigateToPose_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} fc_msgs__action__NavigateToPose_SendGoal_Response;

// Struct for a sequence of fc_msgs__action__NavigateToPose_SendGoal_Response.
typedef struct fc_msgs__action__NavigateToPose_SendGoal_Response__Sequence
{
  fc_msgs__action__NavigateToPose_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} fc_msgs__action__NavigateToPose_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

// Struct defined in action/NavigateToPose in the package fc_msgs.
typedef struct fc_msgs__action__NavigateToPose_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} fc_msgs__action__NavigateToPose_GetResult_Request;

// Struct for a sequence of fc_msgs__action__NavigateToPose_GetResult_Request.
typedef struct fc_msgs__action__NavigateToPose_GetResult_Request__Sequence
{
  fc_msgs__action__NavigateToPose_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} fc_msgs__action__NavigateToPose_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "fc_msgs/action/detail/navigate_to_pose__struct.h"

// Struct defined in action/NavigateToPose in the package fc_msgs.
typedef struct fc_msgs__action__NavigateToPose_GetResult_Response
{
  int8_t status;
  fc_msgs__action__NavigateToPose_Result result;
} fc_msgs__action__NavigateToPose_GetResult_Response;

// Struct for a sequence of fc_msgs__action__NavigateToPose_GetResult_Response.
typedef struct fc_msgs__action__NavigateToPose_GetResult_Response__Sequence
{
  fc_msgs__action__NavigateToPose_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} fc_msgs__action__NavigateToPose_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "fc_msgs/action/detail/navigate_to_pose__struct.h"

// Struct defined in action/NavigateToPose in the package fc_msgs.
typedef struct fc_msgs__action__NavigateToPose_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  fc_msgs__action__NavigateToPose_Feedback feedback;
} fc_msgs__action__NavigateToPose_FeedbackMessage;

// Struct for a sequence of fc_msgs__action__NavigateToPose_FeedbackMessage.
typedef struct fc_msgs__action__NavigateToPose_FeedbackMessage__Sequence
{
  fc_msgs__action__NavigateToPose_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} fc_msgs__action__NavigateToPose_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FC_MSGS__ACTION__DETAIL__NAVIGATE_TO_POSE__STRUCT_H_
