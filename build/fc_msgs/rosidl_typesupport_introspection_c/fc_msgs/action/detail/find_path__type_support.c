// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from fc_msgs:action/FindPath.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "fc_msgs/action/detail/find_path__rosidl_typesupport_introspection_c.h"
#include "fc_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "fc_msgs/action/detail/find_path__functions.h"
#include "fc_msgs/action/detail/find_path__struct.h"


// Include directives for member types
// Member `s_and_t`
#include "geometry_msgs/msg/pose_array.h"
// Member `s_and_t`
#include "geometry_msgs/msg/detail/pose_array__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void FindPath_Goal__rosidl_typesupport_introspection_c__FindPath_Goal_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  fc_msgs__action__FindPath_Goal__init(message_memory);
}

void FindPath_Goal__rosidl_typesupport_introspection_c__FindPath_Goal_fini_function(void * message_memory)
{
  fc_msgs__action__FindPath_Goal__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember FindPath_Goal__rosidl_typesupport_introspection_c__FindPath_Goal_message_member_array[3] = {
  {
    "s_and_t",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fc_msgs__action__FindPath_Goal, s_and_t),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "follow_lane",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fc_msgs__action__FindPath_Goal, follow_lane),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "right",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fc_msgs__action__FindPath_Goal, right),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers FindPath_Goal__rosidl_typesupport_introspection_c__FindPath_Goal_message_members = {
  "fc_msgs__action",  // message namespace
  "FindPath_Goal",  // message name
  3,  // number of fields
  sizeof(fc_msgs__action__FindPath_Goal),
  FindPath_Goal__rosidl_typesupport_introspection_c__FindPath_Goal_message_member_array,  // message members
  FindPath_Goal__rosidl_typesupport_introspection_c__FindPath_Goal_init_function,  // function to initialize message memory (memory has to be allocated)
  FindPath_Goal__rosidl_typesupport_introspection_c__FindPath_Goal_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t FindPath_Goal__rosidl_typesupport_introspection_c__FindPath_Goal_message_type_support_handle = {
  0,
  &FindPath_Goal__rosidl_typesupport_introspection_c__FindPath_Goal_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_fc_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fc_msgs, action, FindPath_Goal)() {
  FindPath_Goal__rosidl_typesupport_introspection_c__FindPath_Goal_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, PoseArray)();
  if (!FindPath_Goal__rosidl_typesupport_introspection_c__FindPath_Goal_message_type_support_handle.typesupport_identifier) {
    FindPath_Goal__rosidl_typesupport_introspection_c__FindPath_Goal_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &FindPath_Goal__rosidl_typesupport_introspection_c__FindPath_Goal_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "fc_msgs/action/detail/find_path__rosidl_typesupport_introspection_c.h"
// already included above
// #include "fc_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "fc_msgs/action/detail/find_path__functions.h"
// already included above
// #include "fc_msgs/action/detail/find_path__struct.h"


// Include directives for member types
// Member `trajectory`
// already included above
// #include "geometry_msgs/msg/pose_array.h"
// Member `trajectory`
// already included above
// #include "geometry_msgs/msg/detail/pose_array__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void FindPath_Result__rosidl_typesupport_introspection_c__FindPath_Result_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  fc_msgs__action__FindPath_Result__init(message_memory);
}

void FindPath_Result__rosidl_typesupport_introspection_c__FindPath_Result_fini_function(void * message_memory)
{
  fc_msgs__action__FindPath_Result__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember FindPath_Result__rosidl_typesupport_introspection_c__FindPath_Result_message_member_array[1] = {
  {
    "trajectory",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fc_msgs__action__FindPath_Result, trajectory),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers FindPath_Result__rosidl_typesupport_introspection_c__FindPath_Result_message_members = {
  "fc_msgs__action",  // message namespace
  "FindPath_Result",  // message name
  1,  // number of fields
  sizeof(fc_msgs__action__FindPath_Result),
  FindPath_Result__rosidl_typesupport_introspection_c__FindPath_Result_message_member_array,  // message members
  FindPath_Result__rosidl_typesupport_introspection_c__FindPath_Result_init_function,  // function to initialize message memory (memory has to be allocated)
  FindPath_Result__rosidl_typesupport_introspection_c__FindPath_Result_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t FindPath_Result__rosidl_typesupport_introspection_c__FindPath_Result_message_type_support_handle = {
  0,
  &FindPath_Result__rosidl_typesupport_introspection_c__FindPath_Result_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_fc_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fc_msgs, action, FindPath_Result)() {
  FindPath_Result__rosidl_typesupport_introspection_c__FindPath_Result_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, PoseArray)();
  if (!FindPath_Result__rosidl_typesupport_introspection_c__FindPath_Result_message_type_support_handle.typesupport_identifier) {
    FindPath_Result__rosidl_typesupport_introspection_c__FindPath_Result_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &FindPath_Result__rosidl_typesupport_introspection_c__FindPath_Result_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "fc_msgs/action/detail/find_path__rosidl_typesupport_introspection_c.h"
// already included above
// #include "fc_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "fc_msgs/action/detail/find_path__functions.h"
// already included above
// #include "fc_msgs/action/detail/find_path__struct.h"


// Include directives for member types
// Member `outcome`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void FindPath_Feedback__rosidl_typesupport_introspection_c__FindPath_Feedback_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  fc_msgs__action__FindPath_Feedback__init(message_memory);
}

void FindPath_Feedback__rosidl_typesupport_introspection_c__FindPath_Feedback_fini_function(void * message_memory)
{
  fc_msgs__action__FindPath_Feedback__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember FindPath_Feedback__rosidl_typesupport_introspection_c__FindPath_Feedback_message_member_array[1] = {
  {
    "outcome",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fc_msgs__action__FindPath_Feedback, outcome),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers FindPath_Feedback__rosidl_typesupport_introspection_c__FindPath_Feedback_message_members = {
  "fc_msgs__action",  // message namespace
  "FindPath_Feedback",  // message name
  1,  // number of fields
  sizeof(fc_msgs__action__FindPath_Feedback),
  FindPath_Feedback__rosidl_typesupport_introspection_c__FindPath_Feedback_message_member_array,  // message members
  FindPath_Feedback__rosidl_typesupport_introspection_c__FindPath_Feedback_init_function,  // function to initialize message memory (memory has to be allocated)
  FindPath_Feedback__rosidl_typesupport_introspection_c__FindPath_Feedback_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t FindPath_Feedback__rosidl_typesupport_introspection_c__FindPath_Feedback_message_type_support_handle = {
  0,
  &FindPath_Feedback__rosidl_typesupport_introspection_c__FindPath_Feedback_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_fc_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fc_msgs, action, FindPath_Feedback)() {
  if (!FindPath_Feedback__rosidl_typesupport_introspection_c__FindPath_Feedback_message_type_support_handle.typesupport_identifier) {
    FindPath_Feedback__rosidl_typesupport_introspection_c__FindPath_Feedback_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &FindPath_Feedback__rosidl_typesupport_introspection_c__FindPath_Feedback_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "fc_msgs/action/detail/find_path__rosidl_typesupport_introspection_c.h"
// already included above
// #include "fc_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "fc_msgs/action/detail/find_path__functions.h"
// already included above
// #include "fc_msgs/action/detail/find_path__struct.h"


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `goal`
#include "fc_msgs/action/find_path.h"
// Member `goal`
// already included above
// #include "fc_msgs/action/detail/find_path__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void FindPath_SendGoal_Request__rosidl_typesupport_introspection_c__FindPath_SendGoal_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  fc_msgs__action__FindPath_SendGoal_Request__init(message_memory);
}

void FindPath_SendGoal_Request__rosidl_typesupport_introspection_c__FindPath_SendGoal_Request_fini_function(void * message_memory)
{
  fc_msgs__action__FindPath_SendGoal_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember FindPath_SendGoal_Request__rosidl_typesupport_introspection_c__FindPath_SendGoal_Request_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fc_msgs__action__FindPath_SendGoal_Request, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "goal",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fc_msgs__action__FindPath_SendGoal_Request, goal),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers FindPath_SendGoal_Request__rosidl_typesupport_introspection_c__FindPath_SendGoal_Request_message_members = {
  "fc_msgs__action",  // message namespace
  "FindPath_SendGoal_Request",  // message name
  2,  // number of fields
  sizeof(fc_msgs__action__FindPath_SendGoal_Request),
  FindPath_SendGoal_Request__rosidl_typesupport_introspection_c__FindPath_SendGoal_Request_message_member_array,  // message members
  FindPath_SendGoal_Request__rosidl_typesupport_introspection_c__FindPath_SendGoal_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  FindPath_SendGoal_Request__rosidl_typesupport_introspection_c__FindPath_SendGoal_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t FindPath_SendGoal_Request__rosidl_typesupport_introspection_c__FindPath_SendGoal_Request_message_type_support_handle = {
  0,
  &FindPath_SendGoal_Request__rosidl_typesupport_introspection_c__FindPath_SendGoal_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_fc_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fc_msgs, action, FindPath_SendGoal_Request)() {
  FindPath_SendGoal_Request__rosidl_typesupport_introspection_c__FindPath_SendGoal_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  FindPath_SendGoal_Request__rosidl_typesupport_introspection_c__FindPath_SendGoal_Request_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fc_msgs, action, FindPath_Goal)();
  if (!FindPath_SendGoal_Request__rosidl_typesupport_introspection_c__FindPath_SendGoal_Request_message_type_support_handle.typesupport_identifier) {
    FindPath_SendGoal_Request__rosidl_typesupport_introspection_c__FindPath_SendGoal_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &FindPath_SendGoal_Request__rosidl_typesupport_introspection_c__FindPath_SendGoal_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "fc_msgs/action/detail/find_path__rosidl_typesupport_introspection_c.h"
// already included above
// #include "fc_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "fc_msgs/action/detail/find_path__functions.h"
// already included above
// #include "fc_msgs/action/detail/find_path__struct.h"


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/time.h"
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void FindPath_SendGoal_Response__rosidl_typesupport_introspection_c__FindPath_SendGoal_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  fc_msgs__action__FindPath_SendGoal_Response__init(message_memory);
}

void FindPath_SendGoal_Response__rosidl_typesupport_introspection_c__FindPath_SendGoal_Response_fini_function(void * message_memory)
{
  fc_msgs__action__FindPath_SendGoal_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember FindPath_SendGoal_Response__rosidl_typesupport_introspection_c__FindPath_SendGoal_Response_message_member_array[2] = {
  {
    "accepted",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fc_msgs__action__FindPath_SendGoal_Response, accepted),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "stamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fc_msgs__action__FindPath_SendGoal_Response, stamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers FindPath_SendGoal_Response__rosidl_typesupport_introspection_c__FindPath_SendGoal_Response_message_members = {
  "fc_msgs__action",  // message namespace
  "FindPath_SendGoal_Response",  // message name
  2,  // number of fields
  sizeof(fc_msgs__action__FindPath_SendGoal_Response),
  FindPath_SendGoal_Response__rosidl_typesupport_introspection_c__FindPath_SendGoal_Response_message_member_array,  // message members
  FindPath_SendGoal_Response__rosidl_typesupport_introspection_c__FindPath_SendGoal_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  FindPath_SendGoal_Response__rosidl_typesupport_introspection_c__FindPath_SendGoal_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t FindPath_SendGoal_Response__rosidl_typesupport_introspection_c__FindPath_SendGoal_Response_message_type_support_handle = {
  0,
  &FindPath_SendGoal_Response__rosidl_typesupport_introspection_c__FindPath_SendGoal_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_fc_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fc_msgs, action, FindPath_SendGoal_Response)() {
  FindPath_SendGoal_Response__rosidl_typesupport_introspection_c__FindPath_SendGoal_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  if (!FindPath_SendGoal_Response__rosidl_typesupport_introspection_c__FindPath_SendGoal_Response_message_type_support_handle.typesupport_identifier) {
    FindPath_SendGoal_Response__rosidl_typesupport_introspection_c__FindPath_SendGoal_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &FindPath_SendGoal_Response__rosidl_typesupport_introspection_c__FindPath_SendGoal_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "fc_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "fc_msgs/action/detail/find_path__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers fc_msgs__action__detail__find_path__rosidl_typesupport_introspection_c__FindPath_SendGoal_service_members = {
  "fc_msgs__action",  // service namespace
  "FindPath_SendGoal",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // fc_msgs__action__detail__find_path__rosidl_typesupport_introspection_c__FindPath_SendGoal_Request_message_type_support_handle,
  NULL  // response message
  // fc_msgs__action__detail__find_path__rosidl_typesupport_introspection_c__FindPath_SendGoal_Response_message_type_support_handle
};

static rosidl_service_type_support_t fc_msgs__action__detail__find_path__rosidl_typesupport_introspection_c__FindPath_SendGoal_service_type_support_handle = {
  0,
  &fc_msgs__action__detail__find_path__rosidl_typesupport_introspection_c__FindPath_SendGoal_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fc_msgs, action, FindPath_SendGoal_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fc_msgs, action, FindPath_SendGoal_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_fc_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fc_msgs, action, FindPath_SendGoal)() {
  if (!fc_msgs__action__detail__find_path__rosidl_typesupport_introspection_c__FindPath_SendGoal_service_type_support_handle.typesupport_identifier) {
    fc_msgs__action__detail__find_path__rosidl_typesupport_introspection_c__FindPath_SendGoal_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)fc_msgs__action__detail__find_path__rosidl_typesupport_introspection_c__FindPath_SendGoal_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fc_msgs, action, FindPath_SendGoal_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fc_msgs, action, FindPath_SendGoal_Response)()->data;
  }

  return &fc_msgs__action__detail__find_path__rosidl_typesupport_introspection_c__FindPath_SendGoal_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "fc_msgs/action/detail/find_path__rosidl_typesupport_introspection_c.h"
// already included above
// #include "fc_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "fc_msgs/action/detail/find_path__functions.h"
// already included above
// #include "fc_msgs/action/detail/find_path__struct.h"


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void FindPath_GetResult_Request__rosidl_typesupport_introspection_c__FindPath_GetResult_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  fc_msgs__action__FindPath_GetResult_Request__init(message_memory);
}

void FindPath_GetResult_Request__rosidl_typesupport_introspection_c__FindPath_GetResult_Request_fini_function(void * message_memory)
{
  fc_msgs__action__FindPath_GetResult_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember FindPath_GetResult_Request__rosidl_typesupport_introspection_c__FindPath_GetResult_Request_message_member_array[1] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fc_msgs__action__FindPath_GetResult_Request, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers FindPath_GetResult_Request__rosidl_typesupport_introspection_c__FindPath_GetResult_Request_message_members = {
  "fc_msgs__action",  // message namespace
  "FindPath_GetResult_Request",  // message name
  1,  // number of fields
  sizeof(fc_msgs__action__FindPath_GetResult_Request),
  FindPath_GetResult_Request__rosidl_typesupport_introspection_c__FindPath_GetResult_Request_message_member_array,  // message members
  FindPath_GetResult_Request__rosidl_typesupport_introspection_c__FindPath_GetResult_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  FindPath_GetResult_Request__rosidl_typesupport_introspection_c__FindPath_GetResult_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t FindPath_GetResult_Request__rosidl_typesupport_introspection_c__FindPath_GetResult_Request_message_type_support_handle = {
  0,
  &FindPath_GetResult_Request__rosidl_typesupport_introspection_c__FindPath_GetResult_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_fc_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fc_msgs, action, FindPath_GetResult_Request)() {
  FindPath_GetResult_Request__rosidl_typesupport_introspection_c__FindPath_GetResult_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  if (!FindPath_GetResult_Request__rosidl_typesupport_introspection_c__FindPath_GetResult_Request_message_type_support_handle.typesupport_identifier) {
    FindPath_GetResult_Request__rosidl_typesupport_introspection_c__FindPath_GetResult_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &FindPath_GetResult_Request__rosidl_typesupport_introspection_c__FindPath_GetResult_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "fc_msgs/action/detail/find_path__rosidl_typesupport_introspection_c.h"
// already included above
// #include "fc_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "fc_msgs/action/detail/find_path__functions.h"
// already included above
// #include "fc_msgs/action/detail/find_path__struct.h"


// Include directives for member types
// Member `result`
// already included above
// #include "fc_msgs/action/find_path.h"
// Member `result`
// already included above
// #include "fc_msgs/action/detail/find_path__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void FindPath_GetResult_Response__rosidl_typesupport_introspection_c__FindPath_GetResult_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  fc_msgs__action__FindPath_GetResult_Response__init(message_memory);
}

void FindPath_GetResult_Response__rosidl_typesupport_introspection_c__FindPath_GetResult_Response_fini_function(void * message_memory)
{
  fc_msgs__action__FindPath_GetResult_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember FindPath_GetResult_Response__rosidl_typesupport_introspection_c__FindPath_GetResult_Response_message_member_array[2] = {
  {
    "status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fc_msgs__action__FindPath_GetResult_Response, status),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "result",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fc_msgs__action__FindPath_GetResult_Response, result),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers FindPath_GetResult_Response__rosidl_typesupport_introspection_c__FindPath_GetResult_Response_message_members = {
  "fc_msgs__action",  // message namespace
  "FindPath_GetResult_Response",  // message name
  2,  // number of fields
  sizeof(fc_msgs__action__FindPath_GetResult_Response),
  FindPath_GetResult_Response__rosidl_typesupport_introspection_c__FindPath_GetResult_Response_message_member_array,  // message members
  FindPath_GetResult_Response__rosidl_typesupport_introspection_c__FindPath_GetResult_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  FindPath_GetResult_Response__rosidl_typesupport_introspection_c__FindPath_GetResult_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t FindPath_GetResult_Response__rosidl_typesupport_introspection_c__FindPath_GetResult_Response_message_type_support_handle = {
  0,
  &FindPath_GetResult_Response__rosidl_typesupport_introspection_c__FindPath_GetResult_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_fc_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fc_msgs, action, FindPath_GetResult_Response)() {
  FindPath_GetResult_Response__rosidl_typesupport_introspection_c__FindPath_GetResult_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fc_msgs, action, FindPath_Result)();
  if (!FindPath_GetResult_Response__rosidl_typesupport_introspection_c__FindPath_GetResult_Response_message_type_support_handle.typesupport_identifier) {
    FindPath_GetResult_Response__rosidl_typesupport_introspection_c__FindPath_GetResult_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &FindPath_GetResult_Response__rosidl_typesupport_introspection_c__FindPath_GetResult_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "fc_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "fc_msgs/action/detail/find_path__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers fc_msgs__action__detail__find_path__rosidl_typesupport_introspection_c__FindPath_GetResult_service_members = {
  "fc_msgs__action",  // service namespace
  "FindPath_GetResult",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // fc_msgs__action__detail__find_path__rosidl_typesupport_introspection_c__FindPath_GetResult_Request_message_type_support_handle,
  NULL  // response message
  // fc_msgs__action__detail__find_path__rosidl_typesupport_introspection_c__FindPath_GetResult_Response_message_type_support_handle
};

static rosidl_service_type_support_t fc_msgs__action__detail__find_path__rosidl_typesupport_introspection_c__FindPath_GetResult_service_type_support_handle = {
  0,
  &fc_msgs__action__detail__find_path__rosidl_typesupport_introspection_c__FindPath_GetResult_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fc_msgs, action, FindPath_GetResult_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fc_msgs, action, FindPath_GetResult_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_fc_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fc_msgs, action, FindPath_GetResult)() {
  if (!fc_msgs__action__detail__find_path__rosidl_typesupport_introspection_c__FindPath_GetResult_service_type_support_handle.typesupport_identifier) {
    fc_msgs__action__detail__find_path__rosidl_typesupport_introspection_c__FindPath_GetResult_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)fc_msgs__action__detail__find_path__rosidl_typesupport_introspection_c__FindPath_GetResult_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fc_msgs, action, FindPath_GetResult_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fc_msgs, action, FindPath_GetResult_Response)()->data;
  }

  return &fc_msgs__action__detail__find_path__rosidl_typesupport_introspection_c__FindPath_GetResult_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "fc_msgs/action/detail/find_path__rosidl_typesupport_introspection_c.h"
// already included above
// #include "fc_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "fc_msgs/action/detail/find_path__functions.h"
// already included above
// #include "fc_msgs/action/detail/find_path__struct.h"


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `feedback`
// already included above
// #include "fc_msgs/action/find_path.h"
// Member `feedback`
// already included above
// #include "fc_msgs/action/detail/find_path__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void FindPath_FeedbackMessage__rosidl_typesupport_introspection_c__FindPath_FeedbackMessage_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  fc_msgs__action__FindPath_FeedbackMessage__init(message_memory);
}

void FindPath_FeedbackMessage__rosidl_typesupport_introspection_c__FindPath_FeedbackMessage_fini_function(void * message_memory)
{
  fc_msgs__action__FindPath_FeedbackMessage__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember FindPath_FeedbackMessage__rosidl_typesupport_introspection_c__FindPath_FeedbackMessage_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fc_msgs__action__FindPath_FeedbackMessage, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "feedback",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fc_msgs__action__FindPath_FeedbackMessage, feedback),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers FindPath_FeedbackMessage__rosidl_typesupport_introspection_c__FindPath_FeedbackMessage_message_members = {
  "fc_msgs__action",  // message namespace
  "FindPath_FeedbackMessage",  // message name
  2,  // number of fields
  sizeof(fc_msgs__action__FindPath_FeedbackMessage),
  FindPath_FeedbackMessage__rosidl_typesupport_introspection_c__FindPath_FeedbackMessage_message_member_array,  // message members
  FindPath_FeedbackMessage__rosidl_typesupport_introspection_c__FindPath_FeedbackMessage_init_function,  // function to initialize message memory (memory has to be allocated)
  FindPath_FeedbackMessage__rosidl_typesupport_introspection_c__FindPath_FeedbackMessage_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t FindPath_FeedbackMessage__rosidl_typesupport_introspection_c__FindPath_FeedbackMessage_message_type_support_handle = {
  0,
  &FindPath_FeedbackMessage__rosidl_typesupport_introspection_c__FindPath_FeedbackMessage_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_fc_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fc_msgs, action, FindPath_FeedbackMessage)() {
  FindPath_FeedbackMessage__rosidl_typesupport_introspection_c__FindPath_FeedbackMessage_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  FindPath_FeedbackMessage__rosidl_typesupport_introspection_c__FindPath_FeedbackMessage_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fc_msgs, action, FindPath_Feedback)();
  if (!FindPath_FeedbackMessage__rosidl_typesupport_introspection_c__FindPath_FeedbackMessage_message_type_support_handle.typesupport_identifier) {
    FindPath_FeedbackMessage__rosidl_typesupport_introspection_c__FindPath_FeedbackMessage_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &FindPath_FeedbackMessage__rosidl_typesupport_introspection_c__FindPath_FeedbackMessage_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
