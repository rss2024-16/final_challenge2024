// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from fc_msgs:srv/LaneProject.idl
// generated code does not contain a copyright notice

#ifndef FC_MSGS__SRV__DETAIL__LANE_PROJECT__STRUCT_H_
#define FC_MSGS__SRV__DETAIL__LANE_PROJECT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'location'
#include "geometry_msgs/msg/detail/point_stamped__struct.h"

// Struct defined in srv/LaneProject in the package fc_msgs.
typedef struct fc_msgs__srv__LaneProject_Request
{
  geometry_msgs__msg__PointStamped location;
  bool right;
} fc_msgs__srv__LaneProject_Request;

// Struct for a sequence of fc_msgs__srv__LaneProject_Request.
typedef struct fc_msgs__srv__LaneProject_Request__Sequence
{
  fc_msgs__srv__LaneProject_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} fc_msgs__srv__LaneProject_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'projection'
#include "geometry_msgs/msg/detail/pose__struct.h"

// Struct defined in srv/LaneProject in the package fc_msgs.
typedef struct fc_msgs__srv__LaneProject_Response
{
  geometry_msgs__msg__Pose projection;
} fc_msgs__srv__LaneProject_Response;

// Struct for a sequence of fc_msgs__srv__LaneProject_Response.
typedef struct fc_msgs__srv__LaneProject_Response__Sequence
{
  fc_msgs__srv__LaneProject_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} fc_msgs__srv__LaneProject_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FC_MSGS__SRV__DETAIL__LANE_PROJECT__STRUCT_H_
