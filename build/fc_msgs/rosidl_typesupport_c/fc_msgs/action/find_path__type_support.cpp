// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from fc_msgs:action/FindPath.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "fc_msgs/msg/rosidl_typesupport_c__visibility_control.h"
#include "fc_msgs/action/detail/find_path__struct.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace fc_msgs
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _FindPath_Goal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _FindPath_Goal_type_support_ids_t;

static const _FindPath_Goal_type_support_ids_t _FindPath_Goal_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _FindPath_Goal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _FindPath_Goal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _FindPath_Goal_type_support_symbol_names_t _FindPath_Goal_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, fc_msgs, action, FindPath_Goal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fc_msgs, action, FindPath_Goal)),
  }
};

typedef struct _FindPath_Goal_type_support_data_t
{
  void * data[2];
} _FindPath_Goal_type_support_data_t;

static _FindPath_Goal_type_support_data_t _FindPath_Goal_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _FindPath_Goal_message_typesupport_map = {
  2,
  "fc_msgs",
  &_FindPath_Goal_message_typesupport_ids.typesupport_identifier[0],
  &_FindPath_Goal_message_typesupport_symbol_names.symbol_name[0],
  &_FindPath_Goal_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t FindPath_Goal_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_FindPath_Goal_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace fc_msgs

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_C_EXPORT_fc_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, fc_msgs, action, FindPath_Goal)() {
  return &::fc_msgs::action::rosidl_typesupport_c::FindPath_Goal_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "fc_msgs/msg/rosidl_typesupport_c__visibility_control.h"
// already included above
// #include "fc_msgs/action/detail/find_path__struct.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace fc_msgs
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _FindPath_Result_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _FindPath_Result_type_support_ids_t;

static const _FindPath_Result_type_support_ids_t _FindPath_Result_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _FindPath_Result_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _FindPath_Result_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _FindPath_Result_type_support_symbol_names_t _FindPath_Result_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, fc_msgs, action, FindPath_Result)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fc_msgs, action, FindPath_Result)),
  }
};

typedef struct _FindPath_Result_type_support_data_t
{
  void * data[2];
} _FindPath_Result_type_support_data_t;

static _FindPath_Result_type_support_data_t _FindPath_Result_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _FindPath_Result_message_typesupport_map = {
  2,
  "fc_msgs",
  &_FindPath_Result_message_typesupport_ids.typesupport_identifier[0],
  &_FindPath_Result_message_typesupport_symbol_names.symbol_name[0],
  &_FindPath_Result_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t FindPath_Result_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_FindPath_Result_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace fc_msgs

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_C_EXPORT_fc_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, fc_msgs, action, FindPath_Result)() {
  return &::fc_msgs::action::rosidl_typesupport_c::FindPath_Result_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "fc_msgs/msg/rosidl_typesupport_c__visibility_control.h"
// already included above
// #include "fc_msgs/action/detail/find_path__struct.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace fc_msgs
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _FindPath_Feedback_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _FindPath_Feedback_type_support_ids_t;

static const _FindPath_Feedback_type_support_ids_t _FindPath_Feedback_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _FindPath_Feedback_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _FindPath_Feedback_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _FindPath_Feedback_type_support_symbol_names_t _FindPath_Feedback_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, fc_msgs, action, FindPath_Feedback)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fc_msgs, action, FindPath_Feedback)),
  }
};

typedef struct _FindPath_Feedback_type_support_data_t
{
  void * data[2];
} _FindPath_Feedback_type_support_data_t;

static _FindPath_Feedback_type_support_data_t _FindPath_Feedback_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _FindPath_Feedback_message_typesupport_map = {
  2,
  "fc_msgs",
  &_FindPath_Feedback_message_typesupport_ids.typesupport_identifier[0],
  &_FindPath_Feedback_message_typesupport_symbol_names.symbol_name[0],
  &_FindPath_Feedback_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t FindPath_Feedback_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_FindPath_Feedback_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace fc_msgs

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_C_EXPORT_fc_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, fc_msgs, action, FindPath_Feedback)() {
  return &::fc_msgs::action::rosidl_typesupport_c::FindPath_Feedback_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "fc_msgs/msg/rosidl_typesupport_c__visibility_control.h"
// already included above
// #include "fc_msgs/action/detail/find_path__struct.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace fc_msgs
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _FindPath_SendGoal_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _FindPath_SendGoal_Request_type_support_ids_t;

static const _FindPath_SendGoal_Request_type_support_ids_t _FindPath_SendGoal_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _FindPath_SendGoal_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _FindPath_SendGoal_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _FindPath_SendGoal_Request_type_support_symbol_names_t _FindPath_SendGoal_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, fc_msgs, action, FindPath_SendGoal_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fc_msgs, action, FindPath_SendGoal_Request)),
  }
};

typedef struct _FindPath_SendGoal_Request_type_support_data_t
{
  void * data[2];
} _FindPath_SendGoal_Request_type_support_data_t;

static _FindPath_SendGoal_Request_type_support_data_t _FindPath_SendGoal_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _FindPath_SendGoal_Request_message_typesupport_map = {
  2,
  "fc_msgs",
  &_FindPath_SendGoal_Request_message_typesupport_ids.typesupport_identifier[0],
  &_FindPath_SendGoal_Request_message_typesupport_symbol_names.symbol_name[0],
  &_FindPath_SendGoal_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t FindPath_SendGoal_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_FindPath_SendGoal_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace fc_msgs

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_C_EXPORT_fc_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, fc_msgs, action, FindPath_SendGoal_Request)() {
  return &::fc_msgs::action::rosidl_typesupport_c::FindPath_SendGoal_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "fc_msgs/msg/rosidl_typesupport_c__visibility_control.h"
// already included above
// #include "fc_msgs/action/detail/find_path__struct.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace fc_msgs
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _FindPath_SendGoal_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _FindPath_SendGoal_Response_type_support_ids_t;

static const _FindPath_SendGoal_Response_type_support_ids_t _FindPath_SendGoal_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _FindPath_SendGoal_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _FindPath_SendGoal_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _FindPath_SendGoal_Response_type_support_symbol_names_t _FindPath_SendGoal_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, fc_msgs, action, FindPath_SendGoal_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fc_msgs, action, FindPath_SendGoal_Response)),
  }
};

typedef struct _FindPath_SendGoal_Response_type_support_data_t
{
  void * data[2];
} _FindPath_SendGoal_Response_type_support_data_t;

static _FindPath_SendGoal_Response_type_support_data_t _FindPath_SendGoal_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _FindPath_SendGoal_Response_message_typesupport_map = {
  2,
  "fc_msgs",
  &_FindPath_SendGoal_Response_message_typesupport_ids.typesupport_identifier[0],
  &_FindPath_SendGoal_Response_message_typesupport_symbol_names.symbol_name[0],
  &_FindPath_SendGoal_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t FindPath_SendGoal_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_FindPath_SendGoal_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace fc_msgs

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_C_EXPORT_fc_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, fc_msgs, action, FindPath_SendGoal_Response)() {
  return &::fc_msgs::action::rosidl_typesupport_c::FindPath_SendGoal_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "fc_msgs/msg/rosidl_typesupport_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace fc_msgs
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _FindPath_SendGoal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _FindPath_SendGoal_type_support_ids_t;

static const _FindPath_SendGoal_type_support_ids_t _FindPath_SendGoal_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _FindPath_SendGoal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _FindPath_SendGoal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _FindPath_SendGoal_type_support_symbol_names_t _FindPath_SendGoal_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, fc_msgs, action, FindPath_SendGoal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fc_msgs, action, FindPath_SendGoal)),
  }
};

typedef struct _FindPath_SendGoal_type_support_data_t
{
  void * data[2];
} _FindPath_SendGoal_type_support_data_t;

static _FindPath_SendGoal_type_support_data_t _FindPath_SendGoal_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _FindPath_SendGoal_service_typesupport_map = {
  2,
  "fc_msgs",
  &_FindPath_SendGoal_service_typesupport_ids.typesupport_identifier[0],
  &_FindPath_SendGoal_service_typesupport_symbol_names.symbol_name[0],
  &_FindPath_SendGoal_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t FindPath_SendGoal_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_FindPath_SendGoal_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace fc_msgs

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_C_EXPORT_fc_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, fc_msgs, action, FindPath_SendGoal)() {
  return &::fc_msgs::action::rosidl_typesupport_c::FindPath_SendGoal_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "fc_msgs/msg/rosidl_typesupport_c__visibility_control.h"
// already included above
// #include "fc_msgs/action/detail/find_path__struct.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace fc_msgs
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _FindPath_GetResult_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _FindPath_GetResult_Request_type_support_ids_t;

static const _FindPath_GetResult_Request_type_support_ids_t _FindPath_GetResult_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _FindPath_GetResult_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _FindPath_GetResult_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _FindPath_GetResult_Request_type_support_symbol_names_t _FindPath_GetResult_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, fc_msgs, action, FindPath_GetResult_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fc_msgs, action, FindPath_GetResult_Request)),
  }
};

typedef struct _FindPath_GetResult_Request_type_support_data_t
{
  void * data[2];
} _FindPath_GetResult_Request_type_support_data_t;

static _FindPath_GetResult_Request_type_support_data_t _FindPath_GetResult_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _FindPath_GetResult_Request_message_typesupport_map = {
  2,
  "fc_msgs",
  &_FindPath_GetResult_Request_message_typesupport_ids.typesupport_identifier[0],
  &_FindPath_GetResult_Request_message_typesupport_symbol_names.symbol_name[0],
  &_FindPath_GetResult_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t FindPath_GetResult_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_FindPath_GetResult_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace fc_msgs

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_C_EXPORT_fc_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, fc_msgs, action, FindPath_GetResult_Request)() {
  return &::fc_msgs::action::rosidl_typesupport_c::FindPath_GetResult_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "fc_msgs/msg/rosidl_typesupport_c__visibility_control.h"
// already included above
// #include "fc_msgs/action/detail/find_path__struct.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace fc_msgs
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _FindPath_GetResult_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _FindPath_GetResult_Response_type_support_ids_t;

static const _FindPath_GetResult_Response_type_support_ids_t _FindPath_GetResult_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _FindPath_GetResult_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _FindPath_GetResult_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _FindPath_GetResult_Response_type_support_symbol_names_t _FindPath_GetResult_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, fc_msgs, action, FindPath_GetResult_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fc_msgs, action, FindPath_GetResult_Response)),
  }
};

typedef struct _FindPath_GetResult_Response_type_support_data_t
{
  void * data[2];
} _FindPath_GetResult_Response_type_support_data_t;

static _FindPath_GetResult_Response_type_support_data_t _FindPath_GetResult_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _FindPath_GetResult_Response_message_typesupport_map = {
  2,
  "fc_msgs",
  &_FindPath_GetResult_Response_message_typesupport_ids.typesupport_identifier[0],
  &_FindPath_GetResult_Response_message_typesupport_symbol_names.symbol_name[0],
  &_FindPath_GetResult_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t FindPath_GetResult_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_FindPath_GetResult_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace fc_msgs

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_C_EXPORT_fc_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, fc_msgs, action, FindPath_GetResult_Response)() {
  return &::fc_msgs::action::rosidl_typesupport_c::FindPath_GetResult_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "fc_msgs/msg/rosidl_typesupport_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace fc_msgs
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _FindPath_GetResult_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _FindPath_GetResult_type_support_ids_t;

static const _FindPath_GetResult_type_support_ids_t _FindPath_GetResult_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _FindPath_GetResult_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _FindPath_GetResult_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _FindPath_GetResult_type_support_symbol_names_t _FindPath_GetResult_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, fc_msgs, action, FindPath_GetResult)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fc_msgs, action, FindPath_GetResult)),
  }
};

typedef struct _FindPath_GetResult_type_support_data_t
{
  void * data[2];
} _FindPath_GetResult_type_support_data_t;

static _FindPath_GetResult_type_support_data_t _FindPath_GetResult_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _FindPath_GetResult_service_typesupport_map = {
  2,
  "fc_msgs",
  &_FindPath_GetResult_service_typesupport_ids.typesupport_identifier[0],
  &_FindPath_GetResult_service_typesupport_symbol_names.symbol_name[0],
  &_FindPath_GetResult_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t FindPath_GetResult_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_FindPath_GetResult_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace fc_msgs

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_C_EXPORT_fc_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, fc_msgs, action, FindPath_GetResult)() {
  return &::fc_msgs::action::rosidl_typesupport_c::FindPath_GetResult_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "fc_msgs/msg/rosidl_typesupport_c__visibility_control.h"
// already included above
// #include "fc_msgs/action/detail/find_path__struct.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace fc_msgs
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _FindPath_FeedbackMessage_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _FindPath_FeedbackMessage_type_support_ids_t;

static const _FindPath_FeedbackMessage_type_support_ids_t _FindPath_FeedbackMessage_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _FindPath_FeedbackMessage_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _FindPath_FeedbackMessage_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _FindPath_FeedbackMessage_type_support_symbol_names_t _FindPath_FeedbackMessage_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, fc_msgs, action, FindPath_FeedbackMessage)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fc_msgs, action, FindPath_FeedbackMessage)),
  }
};

typedef struct _FindPath_FeedbackMessage_type_support_data_t
{
  void * data[2];
} _FindPath_FeedbackMessage_type_support_data_t;

static _FindPath_FeedbackMessage_type_support_data_t _FindPath_FeedbackMessage_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _FindPath_FeedbackMessage_message_typesupport_map = {
  2,
  "fc_msgs",
  &_FindPath_FeedbackMessage_message_typesupport_ids.typesupport_identifier[0],
  &_FindPath_FeedbackMessage_message_typesupport_symbol_names.symbol_name[0],
  &_FindPath_FeedbackMessage_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t FindPath_FeedbackMessage_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_FindPath_FeedbackMessage_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace fc_msgs

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_C_EXPORT_fc_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, fc_msgs, action, FindPath_FeedbackMessage)() {
  return &::fc_msgs::action::rosidl_typesupport_c::FindPath_FeedbackMessage_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

#include "action_msgs/msg/goal_status_array.h"
#include "action_msgs/srv/cancel_goal.h"
#include "fc_msgs/action/find_path.h"
#include "fc_msgs/action/detail/find_path__type_support.h"

static rosidl_action_type_support_t _fc_msgs__action__FindPath__typesupport_c;

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_C_EXPORT_fc_msgs
const rosidl_action_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__ACTION_SYMBOL_NAME(
  rosidl_typesupport_c, fc_msgs, action, FindPath)()
{
  // Thread-safe by always writing the same values to the static struct
  _fc_msgs__action__FindPath__typesupport_c.goal_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, fc_msgs, action, FindPath_SendGoal)();
  _fc_msgs__action__FindPath__typesupport_c.result_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, fc_msgs, action, FindPath_GetResult)();
  _fc_msgs__action__FindPath__typesupport_c.cancel_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, action_msgs, srv, CancelGoal)();
  _fc_msgs__action__FindPath__typesupport_c.feedback_message_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c, fc_msgs, action, FindPath_FeedbackMessage)();
  _fc_msgs__action__FindPath__typesupport_c.status_message_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c, action_msgs, msg, GoalStatusArray)();

  return &_fc_msgs__action__FindPath__typesupport_c;
}

#ifdef __cplusplus
}
#endif
