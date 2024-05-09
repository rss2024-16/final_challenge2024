// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from fc_msgs:action/FindPath.idl
// generated code does not contain a copyright notice

#ifndef FC_MSGS__ACTION__DETAIL__FIND_PATH__STRUCT_H_
#define FC_MSGS__ACTION__DETAIL__FIND_PATH__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 's_and_t'
#include "geometry_msgs/msg/detail/pose_array__struct.h"

// Struct defined in action/FindPath in the package fc_msgs.
typedef struct fc_msgs__action__FindPath_Goal
{
  geometry_msgs__msg__PoseArray s_and_t;
  bool follow_lane;
  bool right;
} fc_msgs__action__FindPath_Goal;

// Struct for a sequence of fc_msgs__action__FindPath_Goal.
typedef struct fc_msgs__action__FindPath_Goal__Sequence
{
  fc_msgs__action__FindPath_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} fc_msgs__action__FindPath_Goal__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'trajectory'
// already included above
// #include "geometry_msgs/msg/detail/pose_array__struct.h"

// Struct defined in action/FindPath in the package fc_msgs.
typedef struct fc_msgs__action__FindPath_Result
{
  geometry_msgs__msg__PoseArray trajectory;
} fc_msgs__action__FindPath_Result;

// Struct for a sequence of fc_msgs__action__FindPath_Result.
typedef struct fc_msgs__action__FindPath_Result__Sequence
{
  fc_msgs__action__FindPath_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} fc_msgs__action__FindPath_Result__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'outcome'
#include "rosidl_runtime_c/string.h"

// Struct defined in action/FindPath in the package fc_msgs.
typedef struct fc_msgs__action__FindPath_Feedback
{
  rosidl_runtime_c__String outcome;
} fc_msgs__action__FindPath_Feedback;

// Struct for a sequence of fc_msgs__action__FindPath_Feedback.
typedef struct fc_msgs__action__FindPath_Feedback__Sequence
{
  fc_msgs__action__FindPath_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} fc_msgs__action__FindPath_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "fc_msgs/action/detail/find_path__struct.h"

// Struct defined in action/FindPath in the package fc_msgs.
typedef struct fc_msgs__action__FindPath_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  fc_msgs__action__FindPath_Goal goal;
} fc_msgs__action__FindPath_SendGoal_Request;

// Struct for a sequence of fc_msgs__action__FindPath_SendGoal_Request.
typedef struct fc_msgs__action__FindPath_SendGoal_Request__Sequence
{
  fc_msgs__action__FindPath_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} fc_msgs__action__FindPath_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

// Struct defined in action/FindPath in the package fc_msgs.
typedef struct fc_msgs__action__FindPath_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} fc_msgs__action__FindPath_SendGoal_Response;

// Struct for a sequence of fc_msgs__action__FindPath_SendGoal_Response.
typedef struct fc_msgs__action__FindPath_SendGoal_Response__Sequence
{
  fc_msgs__action__FindPath_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} fc_msgs__action__FindPath_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

// Struct defined in action/FindPath in the package fc_msgs.
typedef struct fc_msgs__action__FindPath_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} fc_msgs__action__FindPath_GetResult_Request;

// Struct for a sequence of fc_msgs__action__FindPath_GetResult_Request.
typedef struct fc_msgs__action__FindPath_GetResult_Request__Sequence
{
  fc_msgs__action__FindPath_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} fc_msgs__action__FindPath_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "fc_msgs/action/detail/find_path__struct.h"

// Struct defined in action/FindPath in the package fc_msgs.
typedef struct fc_msgs__action__FindPath_GetResult_Response
{
  int8_t status;
  fc_msgs__action__FindPath_Result result;
} fc_msgs__action__FindPath_GetResult_Response;

// Struct for a sequence of fc_msgs__action__FindPath_GetResult_Response.
typedef struct fc_msgs__action__FindPath_GetResult_Response__Sequence
{
  fc_msgs__action__FindPath_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} fc_msgs__action__FindPath_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "fc_msgs/action/detail/find_path__struct.h"

// Struct defined in action/FindPath in the package fc_msgs.
typedef struct fc_msgs__action__FindPath_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  fc_msgs__action__FindPath_Feedback feedback;
} fc_msgs__action__FindPath_FeedbackMessage;

// Struct for a sequence of fc_msgs__action__FindPath_FeedbackMessage.
typedef struct fc_msgs__action__FindPath_FeedbackMessage__Sequence
{
  fc_msgs__action__FindPath_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} fc_msgs__action__FindPath_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FC_MSGS__ACTION__DETAIL__FIND_PATH__STRUCT_H_
