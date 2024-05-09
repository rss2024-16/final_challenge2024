// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from fc_msgs:action/NavigateToPose.idl
// generated code does not contain a copyright notice
#include "fc_msgs/action/detail/navigate_to_pose__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `trajectory`
#include "geometry_msgs/msg/detail/pose_array__functions.h"

bool
fc_msgs__action__NavigateToPose_Goal__init(fc_msgs__action__NavigateToPose_Goal * msg)
{
  if (!msg) {
    return false;
  }
  // trajectory
  if (!geometry_msgs__msg__PoseArray__init(&msg->trajectory)) {
    fc_msgs__action__NavigateToPose_Goal__fini(msg);
    return false;
  }
  // follow_lane
  return true;
}

void
fc_msgs__action__NavigateToPose_Goal__fini(fc_msgs__action__NavigateToPose_Goal * msg)
{
  if (!msg) {
    return;
  }
  // trajectory
  geometry_msgs__msg__PoseArray__fini(&msg->trajectory);
  // follow_lane
}

bool
fc_msgs__action__NavigateToPose_Goal__are_equal(const fc_msgs__action__NavigateToPose_Goal * lhs, const fc_msgs__action__NavigateToPose_Goal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // trajectory
  if (!geometry_msgs__msg__PoseArray__are_equal(
      &(lhs->trajectory), &(rhs->trajectory)))
  {
    return false;
  }
  // follow_lane
  if (lhs->follow_lane != rhs->follow_lane) {
    return false;
  }
  return true;
}

bool
fc_msgs__action__NavigateToPose_Goal__copy(
  const fc_msgs__action__NavigateToPose_Goal * input,
  fc_msgs__action__NavigateToPose_Goal * output)
{
  if (!input || !output) {
    return false;
  }
  // trajectory
  if (!geometry_msgs__msg__PoseArray__copy(
      &(input->trajectory), &(output->trajectory)))
  {
    return false;
  }
  // follow_lane
  output->follow_lane = input->follow_lane;
  return true;
}

fc_msgs__action__NavigateToPose_Goal *
fc_msgs__action__NavigateToPose_Goal__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fc_msgs__action__NavigateToPose_Goal * msg = (fc_msgs__action__NavigateToPose_Goal *)allocator.allocate(sizeof(fc_msgs__action__NavigateToPose_Goal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(fc_msgs__action__NavigateToPose_Goal));
  bool success = fc_msgs__action__NavigateToPose_Goal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
fc_msgs__action__NavigateToPose_Goal__destroy(fc_msgs__action__NavigateToPose_Goal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    fc_msgs__action__NavigateToPose_Goal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
fc_msgs__action__NavigateToPose_Goal__Sequence__init(fc_msgs__action__NavigateToPose_Goal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fc_msgs__action__NavigateToPose_Goal * data = NULL;

  if (size) {
    data = (fc_msgs__action__NavigateToPose_Goal *)allocator.zero_allocate(size, sizeof(fc_msgs__action__NavigateToPose_Goal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = fc_msgs__action__NavigateToPose_Goal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        fc_msgs__action__NavigateToPose_Goal__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
fc_msgs__action__NavigateToPose_Goal__Sequence__fini(fc_msgs__action__NavigateToPose_Goal__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      fc_msgs__action__NavigateToPose_Goal__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

fc_msgs__action__NavigateToPose_Goal__Sequence *
fc_msgs__action__NavigateToPose_Goal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fc_msgs__action__NavigateToPose_Goal__Sequence * array = (fc_msgs__action__NavigateToPose_Goal__Sequence *)allocator.allocate(sizeof(fc_msgs__action__NavigateToPose_Goal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = fc_msgs__action__NavigateToPose_Goal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
fc_msgs__action__NavigateToPose_Goal__Sequence__destroy(fc_msgs__action__NavigateToPose_Goal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    fc_msgs__action__NavigateToPose_Goal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
fc_msgs__action__NavigateToPose_Goal__Sequence__are_equal(const fc_msgs__action__NavigateToPose_Goal__Sequence * lhs, const fc_msgs__action__NavigateToPose_Goal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!fc_msgs__action__NavigateToPose_Goal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
fc_msgs__action__NavigateToPose_Goal__Sequence__copy(
  const fc_msgs__action__NavigateToPose_Goal__Sequence * input,
  fc_msgs__action__NavigateToPose_Goal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(fc_msgs__action__NavigateToPose_Goal);
    fc_msgs__action__NavigateToPose_Goal * data =
      (fc_msgs__action__NavigateToPose_Goal *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!fc_msgs__action__NavigateToPose_Goal__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          fc_msgs__action__NavigateToPose_Goal__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!fc_msgs__action__NavigateToPose_Goal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `car_position`
#include "geometry_msgs/msg/detail/pose__functions.h"

bool
fc_msgs__action__NavigateToPose_Result__init(fc_msgs__action__NavigateToPose_Result * msg)
{
  if (!msg) {
    return false;
  }
  // car_position
  if (!geometry_msgs__msg__Pose__init(&msg->car_position)) {
    fc_msgs__action__NavigateToPose_Result__fini(msg);
    return false;
  }
  return true;
}

void
fc_msgs__action__NavigateToPose_Result__fini(fc_msgs__action__NavigateToPose_Result * msg)
{
  if (!msg) {
    return;
  }
  // car_position
  geometry_msgs__msg__Pose__fini(&msg->car_position);
}

bool
fc_msgs__action__NavigateToPose_Result__are_equal(const fc_msgs__action__NavigateToPose_Result * lhs, const fc_msgs__action__NavigateToPose_Result * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // car_position
  if (!geometry_msgs__msg__Pose__are_equal(
      &(lhs->car_position), &(rhs->car_position)))
  {
    return false;
  }
  return true;
}

bool
fc_msgs__action__NavigateToPose_Result__copy(
  const fc_msgs__action__NavigateToPose_Result * input,
  fc_msgs__action__NavigateToPose_Result * output)
{
  if (!input || !output) {
    return false;
  }
  // car_position
  if (!geometry_msgs__msg__Pose__copy(
      &(input->car_position), &(output->car_position)))
  {
    return false;
  }
  return true;
}

fc_msgs__action__NavigateToPose_Result *
fc_msgs__action__NavigateToPose_Result__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fc_msgs__action__NavigateToPose_Result * msg = (fc_msgs__action__NavigateToPose_Result *)allocator.allocate(sizeof(fc_msgs__action__NavigateToPose_Result), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(fc_msgs__action__NavigateToPose_Result));
  bool success = fc_msgs__action__NavigateToPose_Result__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
fc_msgs__action__NavigateToPose_Result__destroy(fc_msgs__action__NavigateToPose_Result * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    fc_msgs__action__NavigateToPose_Result__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
fc_msgs__action__NavigateToPose_Result__Sequence__init(fc_msgs__action__NavigateToPose_Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fc_msgs__action__NavigateToPose_Result * data = NULL;

  if (size) {
    data = (fc_msgs__action__NavigateToPose_Result *)allocator.zero_allocate(size, sizeof(fc_msgs__action__NavigateToPose_Result), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = fc_msgs__action__NavigateToPose_Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        fc_msgs__action__NavigateToPose_Result__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
fc_msgs__action__NavigateToPose_Result__Sequence__fini(fc_msgs__action__NavigateToPose_Result__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      fc_msgs__action__NavigateToPose_Result__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

fc_msgs__action__NavigateToPose_Result__Sequence *
fc_msgs__action__NavigateToPose_Result__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fc_msgs__action__NavigateToPose_Result__Sequence * array = (fc_msgs__action__NavigateToPose_Result__Sequence *)allocator.allocate(sizeof(fc_msgs__action__NavigateToPose_Result__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = fc_msgs__action__NavigateToPose_Result__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
fc_msgs__action__NavigateToPose_Result__Sequence__destroy(fc_msgs__action__NavigateToPose_Result__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    fc_msgs__action__NavigateToPose_Result__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
fc_msgs__action__NavigateToPose_Result__Sequence__are_equal(const fc_msgs__action__NavigateToPose_Result__Sequence * lhs, const fc_msgs__action__NavigateToPose_Result__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!fc_msgs__action__NavigateToPose_Result__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
fc_msgs__action__NavigateToPose_Result__Sequence__copy(
  const fc_msgs__action__NavigateToPose_Result__Sequence * input,
  fc_msgs__action__NavigateToPose_Result__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(fc_msgs__action__NavigateToPose_Result);
    fc_msgs__action__NavigateToPose_Result * data =
      (fc_msgs__action__NavigateToPose_Result *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!fc_msgs__action__NavigateToPose_Result__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          fc_msgs__action__NavigateToPose_Result__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!fc_msgs__action__NavigateToPose_Result__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `outcome`
#include "rosidl_runtime_c/string_functions.h"

bool
fc_msgs__action__NavigateToPose_Feedback__init(fc_msgs__action__NavigateToPose_Feedback * msg)
{
  if (!msg) {
    return false;
  }
  // outcome
  if (!rosidl_runtime_c__String__init(&msg->outcome)) {
    fc_msgs__action__NavigateToPose_Feedback__fini(msg);
    return false;
  }
  return true;
}

void
fc_msgs__action__NavigateToPose_Feedback__fini(fc_msgs__action__NavigateToPose_Feedback * msg)
{
  if (!msg) {
    return;
  }
  // outcome
  rosidl_runtime_c__String__fini(&msg->outcome);
}

bool
fc_msgs__action__NavigateToPose_Feedback__are_equal(const fc_msgs__action__NavigateToPose_Feedback * lhs, const fc_msgs__action__NavigateToPose_Feedback * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // outcome
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->outcome), &(rhs->outcome)))
  {
    return false;
  }
  return true;
}

bool
fc_msgs__action__NavigateToPose_Feedback__copy(
  const fc_msgs__action__NavigateToPose_Feedback * input,
  fc_msgs__action__NavigateToPose_Feedback * output)
{
  if (!input || !output) {
    return false;
  }
  // outcome
  if (!rosidl_runtime_c__String__copy(
      &(input->outcome), &(output->outcome)))
  {
    return false;
  }
  return true;
}

fc_msgs__action__NavigateToPose_Feedback *
fc_msgs__action__NavigateToPose_Feedback__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fc_msgs__action__NavigateToPose_Feedback * msg = (fc_msgs__action__NavigateToPose_Feedback *)allocator.allocate(sizeof(fc_msgs__action__NavigateToPose_Feedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(fc_msgs__action__NavigateToPose_Feedback));
  bool success = fc_msgs__action__NavigateToPose_Feedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
fc_msgs__action__NavigateToPose_Feedback__destroy(fc_msgs__action__NavigateToPose_Feedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    fc_msgs__action__NavigateToPose_Feedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
fc_msgs__action__NavigateToPose_Feedback__Sequence__init(fc_msgs__action__NavigateToPose_Feedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fc_msgs__action__NavigateToPose_Feedback * data = NULL;

  if (size) {
    data = (fc_msgs__action__NavigateToPose_Feedback *)allocator.zero_allocate(size, sizeof(fc_msgs__action__NavigateToPose_Feedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = fc_msgs__action__NavigateToPose_Feedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        fc_msgs__action__NavigateToPose_Feedback__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
fc_msgs__action__NavigateToPose_Feedback__Sequence__fini(fc_msgs__action__NavigateToPose_Feedback__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      fc_msgs__action__NavigateToPose_Feedback__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

fc_msgs__action__NavigateToPose_Feedback__Sequence *
fc_msgs__action__NavigateToPose_Feedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fc_msgs__action__NavigateToPose_Feedback__Sequence * array = (fc_msgs__action__NavigateToPose_Feedback__Sequence *)allocator.allocate(sizeof(fc_msgs__action__NavigateToPose_Feedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = fc_msgs__action__NavigateToPose_Feedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
fc_msgs__action__NavigateToPose_Feedback__Sequence__destroy(fc_msgs__action__NavigateToPose_Feedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    fc_msgs__action__NavigateToPose_Feedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
fc_msgs__action__NavigateToPose_Feedback__Sequence__are_equal(const fc_msgs__action__NavigateToPose_Feedback__Sequence * lhs, const fc_msgs__action__NavigateToPose_Feedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!fc_msgs__action__NavigateToPose_Feedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
fc_msgs__action__NavigateToPose_Feedback__Sequence__copy(
  const fc_msgs__action__NavigateToPose_Feedback__Sequence * input,
  fc_msgs__action__NavigateToPose_Feedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(fc_msgs__action__NavigateToPose_Feedback);
    fc_msgs__action__NavigateToPose_Feedback * data =
      (fc_msgs__action__NavigateToPose_Feedback *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!fc_msgs__action__NavigateToPose_Feedback__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          fc_msgs__action__NavigateToPose_Feedback__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!fc_msgs__action__NavigateToPose_Feedback__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `goal`
// already included above
// #include "fc_msgs/action/detail/navigate_to_pose__functions.h"

bool
fc_msgs__action__NavigateToPose_SendGoal_Request__init(fc_msgs__action__NavigateToPose_SendGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    fc_msgs__action__NavigateToPose_SendGoal_Request__fini(msg);
    return false;
  }
  // goal
  if (!fc_msgs__action__NavigateToPose_Goal__init(&msg->goal)) {
    fc_msgs__action__NavigateToPose_SendGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
fc_msgs__action__NavigateToPose_SendGoal_Request__fini(fc_msgs__action__NavigateToPose_SendGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // goal
  fc_msgs__action__NavigateToPose_Goal__fini(&msg->goal);
}

bool
fc_msgs__action__NavigateToPose_SendGoal_Request__are_equal(const fc_msgs__action__NavigateToPose_SendGoal_Request * lhs, const fc_msgs__action__NavigateToPose_SendGoal_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // goal
  if (!fc_msgs__action__NavigateToPose_Goal__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  return true;
}

bool
fc_msgs__action__NavigateToPose_SendGoal_Request__copy(
  const fc_msgs__action__NavigateToPose_SendGoal_Request * input,
  fc_msgs__action__NavigateToPose_SendGoal_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // goal
  if (!fc_msgs__action__NavigateToPose_Goal__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  return true;
}

fc_msgs__action__NavigateToPose_SendGoal_Request *
fc_msgs__action__NavigateToPose_SendGoal_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fc_msgs__action__NavigateToPose_SendGoal_Request * msg = (fc_msgs__action__NavigateToPose_SendGoal_Request *)allocator.allocate(sizeof(fc_msgs__action__NavigateToPose_SendGoal_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(fc_msgs__action__NavigateToPose_SendGoal_Request));
  bool success = fc_msgs__action__NavigateToPose_SendGoal_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
fc_msgs__action__NavigateToPose_SendGoal_Request__destroy(fc_msgs__action__NavigateToPose_SendGoal_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    fc_msgs__action__NavigateToPose_SendGoal_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
fc_msgs__action__NavigateToPose_SendGoal_Request__Sequence__init(fc_msgs__action__NavigateToPose_SendGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fc_msgs__action__NavigateToPose_SendGoal_Request * data = NULL;

  if (size) {
    data = (fc_msgs__action__NavigateToPose_SendGoal_Request *)allocator.zero_allocate(size, sizeof(fc_msgs__action__NavigateToPose_SendGoal_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = fc_msgs__action__NavigateToPose_SendGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        fc_msgs__action__NavigateToPose_SendGoal_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
fc_msgs__action__NavigateToPose_SendGoal_Request__Sequence__fini(fc_msgs__action__NavigateToPose_SendGoal_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      fc_msgs__action__NavigateToPose_SendGoal_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

fc_msgs__action__NavigateToPose_SendGoal_Request__Sequence *
fc_msgs__action__NavigateToPose_SendGoal_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fc_msgs__action__NavigateToPose_SendGoal_Request__Sequence * array = (fc_msgs__action__NavigateToPose_SendGoal_Request__Sequence *)allocator.allocate(sizeof(fc_msgs__action__NavigateToPose_SendGoal_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = fc_msgs__action__NavigateToPose_SendGoal_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
fc_msgs__action__NavigateToPose_SendGoal_Request__Sequence__destroy(fc_msgs__action__NavigateToPose_SendGoal_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    fc_msgs__action__NavigateToPose_SendGoal_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
fc_msgs__action__NavigateToPose_SendGoal_Request__Sequence__are_equal(const fc_msgs__action__NavigateToPose_SendGoal_Request__Sequence * lhs, const fc_msgs__action__NavigateToPose_SendGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!fc_msgs__action__NavigateToPose_SendGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
fc_msgs__action__NavigateToPose_SendGoal_Request__Sequence__copy(
  const fc_msgs__action__NavigateToPose_SendGoal_Request__Sequence * input,
  fc_msgs__action__NavigateToPose_SendGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(fc_msgs__action__NavigateToPose_SendGoal_Request);
    fc_msgs__action__NavigateToPose_SendGoal_Request * data =
      (fc_msgs__action__NavigateToPose_SendGoal_Request *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!fc_msgs__action__NavigateToPose_SendGoal_Request__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          fc_msgs__action__NavigateToPose_SendGoal_Request__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!fc_msgs__action__NavigateToPose_SendGoal_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
fc_msgs__action__NavigateToPose_SendGoal_Response__init(fc_msgs__action__NavigateToPose_SendGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    fc_msgs__action__NavigateToPose_SendGoal_Response__fini(msg);
    return false;
  }
  return true;
}

void
fc_msgs__action__NavigateToPose_SendGoal_Response__fini(fc_msgs__action__NavigateToPose_SendGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
fc_msgs__action__NavigateToPose_SendGoal_Response__are_equal(const fc_msgs__action__NavigateToPose_SendGoal_Response * lhs, const fc_msgs__action__NavigateToPose_SendGoal_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // accepted
  if (lhs->accepted != rhs->accepted) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  return true;
}

bool
fc_msgs__action__NavigateToPose_SendGoal_Response__copy(
  const fc_msgs__action__NavigateToPose_SendGoal_Response * input,
  fc_msgs__action__NavigateToPose_SendGoal_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // accepted
  output->accepted = input->accepted;
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  return true;
}

fc_msgs__action__NavigateToPose_SendGoal_Response *
fc_msgs__action__NavigateToPose_SendGoal_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fc_msgs__action__NavigateToPose_SendGoal_Response * msg = (fc_msgs__action__NavigateToPose_SendGoal_Response *)allocator.allocate(sizeof(fc_msgs__action__NavigateToPose_SendGoal_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(fc_msgs__action__NavigateToPose_SendGoal_Response));
  bool success = fc_msgs__action__NavigateToPose_SendGoal_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
fc_msgs__action__NavigateToPose_SendGoal_Response__destroy(fc_msgs__action__NavigateToPose_SendGoal_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    fc_msgs__action__NavigateToPose_SendGoal_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
fc_msgs__action__NavigateToPose_SendGoal_Response__Sequence__init(fc_msgs__action__NavigateToPose_SendGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fc_msgs__action__NavigateToPose_SendGoal_Response * data = NULL;

  if (size) {
    data = (fc_msgs__action__NavigateToPose_SendGoal_Response *)allocator.zero_allocate(size, sizeof(fc_msgs__action__NavigateToPose_SendGoal_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = fc_msgs__action__NavigateToPose_SendGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        fc_msgs__action__NavigateToPose_SendGoal_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
fc_msgs__action__NavigateToPose_SendGoal_Response__Sequence__fini(fc_msgs__action__NavigateToPose_SendGoal_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      fc_msgs__action__NavigateToPose_SendGoal_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

fc_msgs__action__NavigateToPose_SendGoal_Response__Sequence *
fc_msgs__action__NavigateToPose_SendGoal_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fc_msgs__action__NavigateToPose_SendGoal_Response__Sequence * array = (fc_msgs__action__NavigateToPose_SendGoal_Response__Sequence *)allocator.allocate(sizeof(fc_msgs__action__NavigateToPose_SendGoal_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = fc_msgs__action__NavigateToPose_SendGoal_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
fc_msgs__action__NavigateToPose_SendGoal_Response__Sequence__destroy(fc_msgs__action__NavigateToPose_SendGoal_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    fc_msgs__action__NavigateToPose_SendGoal_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
fc_msgs__action__NavigateToPose_SendGoal_Response__Sequence__are_equal(const fc_msgs__action__NavigateToPose_SendGoal_Response__Sequence * lhs, const fc_msgs__action__NavigateToPose_SendGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!fc_msgs__action__NavigateToPose_SendGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
fc_msgs__action__NavigateToPose_SendGoal_Response__Sequence__copy(
  const fc_msgs__action__NavigateToPose_SendGoal_Response__Sequence * input,
  fc_msgs__action__NavigateToPose_SendGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(fc_msgs__action__NavigateToPose_SendGoal_Response);
    fc_msgs__action__NavigateToPose_SendGoal_Response * data =
      (fc_msgs__action__NavigateToPose_SendGoal_Response *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!fc_msgs__action__NavigateToPose_SendGoal_Response__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          fc_msgs__action__NavigateToPose_SendGoal_Response__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!fc_msgs__action__NavigateToPose_SendGoal_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"

bool
fc_msgs__action__NavigateToPose_GetResult_Request__init(fc_msgs__action__NavigateToPose_GetResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    fc_msgs__action__NavigateToPose_GetResult_Request__fini(msg);
    return false;
  }
  return true;
}

void
fc_msgs__action__NavigateToPose_GetResult_Request__fini(fc_msgs__action__NavigateToPose_GetResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
}

bool
fc_msgs__action__NavigateToPose_GetResult_Request__are_equal(const fc_msgs__action__NavigateToPose_GetResult_Request * lhs, const fc_msgs__action__NavigateToPose_GetResult_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  return true;
}

bool
fc_msgs__action__NavigateToPose_GetResult_Request__copy(
  const fc_msgs__action__NavigateToPose_GetResult_Request * input,
  fc_msgs__action__NavigateToPose_GetResult_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  return true;
}

fc_msgs__action__NavigateToPose_GetResult_Request *
fc_msgs__action__NavigateToPose_GetResult_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fc_msgs__action__NavigateToPose_GetResult_Request * msg = (fc_msgs__action__NavigateToPose_GetResult_Request *)allocator.allocate(sizeof(fc_msgs__action__NavigateToPose_GetResult_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(fc_msgs__action__NavigateToPose_GetResult_Request));
  bool success = fc_msgs__action__NavigateToPose_GetResult_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
fc_msgs__action__NavigateToPose_GetResult_Request__destroy(fc_msgs__action__NavigateToPose_GetResult_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    fc_msgs__action__NavigateToPose_GetResult_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
fc_msgs__action__NavigateToPose_GetResult_Request__Sequence__init(fc_msgs__action__NavigateToPose_GetResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fc_msgs__action__NavigateToPose_GetResult_Request * data = NULL;

  if (size) {
    data = (fc_msgs__action__NavigateToPose_GetResult_Request *)allocator.zero_allocate(size, sizeof(fc_msgs__action__NavigateToPose_GetResult_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = fc_msgs__action__NavigateToPose_GetResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        fc_msgs__action__NavigateToPose_GetResult_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
fc_msgs__action__NavigateToPose_GetResult_Request__Sequence__fini(fc_msgs__action__NavigateToPose_GetResult_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      fc_msgs__action__NavigateToPose_GetResult_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

fc_msgs__action__NavigateToPose_GetResult_Request__Sequence *
fc_msgs__action__NavigateToPose_GetResult_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fc_msgs__action__NavigateToPose_GetResult_Request__Sequence * array = (fc_msgs__action__NavigateToPose_GetResult_Request__Sequence *)allocator.allocate(sizeof(fc_msgs__action__NavigateToPose_GetResult_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = fc_msgs__action__NavigateToPose_GetResult_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
fc_msgs__action__NavigateToPose_GetResult_Request__Sequence__destroy(fc_msgs__action__NavigateToPose_GetResult_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    fc_msgs__action__NavigateToPose_GetResult_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
fc_msgs__action__NavigateToPose_GetResult_Request__Sequence__are_equal(const fc_msgs__action__NavigateToPose_GetResult_Request__Sequence * lhs, const fc_msgs__action__NavigateToPose_GetResult_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!fc_msgs__action__NavigateToPose_GetResult_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
fc_msgs__action__NavigateToPose_GetResult_Request__Sequence__copy(
  const fc_msgs__action__NavigateToPose_GetResult_Request__Sequence * input,
  fc_msgs__action__NavigateToPose_GetResult_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(fc_msgs__action__NavigateToPose_GetResult_Request);
    fc_msgs__action__NavigateToPose_GetResult_Request * data =
      (fc_msgs__action__NavigateToPose_GetResult_Request *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!fc_msgs__action__NavigateToPose_GetResult_Request__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          fc_msgs__action__NavigateToPose_GetResult_Request__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!fc_msgs__action__NavigateToPose_GetResult_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
// already included above
// #include "fc_msgs/action/detail/navigate_to_pose__functions.h"

bool
fc_msgs__action__NavigateToPose_GetResult_Response__init(fc_msgs__action__NavigateToPose_GetResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // result
  if (!fc_msgs__action__NavigateToPose_Result__init(&msg->result)) {
    fc_msgs__action__NavigateToPose_GetResult_Response__fini(msg);
    return false;
  }
  return true;
}

void
fc_msgs__action__NavigateToPose_GetResult_Response__fini(fc_msgs__action__NavigateToPose_GetResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // result
  fc_msgs__action__NavigateToPose_Result__fini(&msg->result);
}

bool
fc_msgs__action__NavigateToPose_GetResult_Response__are_equal(const fc_msgs__action__NavigateToPose_GetResult_Response * lhs, const fc_msgs__action__NavigateToPose_GetResult_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // result
  if (!fc_msgs__action__NavigateToPose_Result__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
fc_msgs__action__NavigateToPose_GetResult_Response__copy(
  const fc_msgs__action__NavigateToPose_GetResult_Response * input,
  fc_msgs__action__NavigateToPose_GetResult_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // result
  if (!fc_msgs__action__NavigateToPose_Result__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

fc_msgs__action__NavigateToPose_GetResult_Response *
fc_msgs__action__NavigateToPose_GetResult_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fc_msgs__action__NavigateToPose_GetResult_Response * msg = (fc_msgs__action__NavigateToPose_GetResult_Response *)allocator.allocate(sizeof(fc_msgs__action__NavigateToPose_GetResult_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(fc_msgs__action__NavigateToPose_GetResult_Response));
  bool success = fc_msgs__action__NavigateToPose_GetResult_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
fc_msgs__action__NavigateToPose_GetResult_Response__destroy(fc_msgs__action__NavigateToPose_GetResult_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    fc_msgs__action__NavigateToPose_GetResult_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
fc_msgs__action__NavigateToPose_GetResult_Response__Sequence__init(fc_msgs__action__NavigateToPose_GetResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fc_msgs__action__NavigateToPose_GetResult_Response * data = NULL;

  if (size) {
    data = (fc_msgs__action__NavigateToPose_GetResult_Response *)allocator.zero_allocate(size, sizeof(fc_msgs__action__NavigateToPose_GetResult_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = fc_msgs__action__NavigateToPose_GetResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        fc_msgs__action__NavigateToPose_GetResult_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
fc_msgs__action__NavigateToPose_GetResult_Response__Sequence__fini(fc_msgs__action__NavigateToPose_GetResult_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      fc_msgs__action__NavigateToPose_GetResult_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

fc_msgs__action__NavigateToPose_GetResult_Response__Sequence *
fc_msgs__action__NavigateToPose_GetResult_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fc_msgs__action__NavigateToPose_GetResult_Response__Sequence * array = (fc_msgs__action__NavigateToPose_GetResult_Response__Sequence *)allocator.allocate(sizeof(fc_msgs__action__NavigateToPose_GetResult_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = fc_msgs__action__NavigateToPose_GetResult_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
fc_msgs__action__NavigateToPose_GetResult_Response__Sequence__destroy(fc_msgs__action__NavigateToPose_GetResult_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    fc_msgs__action__NavigateToPose_GetResult_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
fc_msgs__action__NavigateToPose_GetResult_Response__Sequence__are_equal(const fc_msgs__action__NavigateToPose_GetResult_Response__Sequence * lhs, const fc_msgs__action__NavigateToPose_GetResult_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!fc_msgs__action__NavigateToPose_GetResult_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
fc_msgs__action__NavigateToPose_GetResult_Response__Sequence__copy(
  const fc_msgs__action__NavigateToPose_GetResult_Response__Sequence * input,
  fc_msgs__action__NavigateToPose_GetResult_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(fc_msgs__action__NavigateToPose_GetResult_Response);
    fc_msgs__action__NavigateToPose_GetResult_Response * data =
      (fc_msgs__action__NavigateToPose_GetResult_Response *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!fc_msgs__action__NavigateToPose_GetResult_Response__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          fc_msgs__action__NavigateToPose_GetResult_Response__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!fc_msgs__action__NavigateToPose_GetResult_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `feedback`
// already included above
// #include "fc_msgs/action/detail/navigate_to_pose__functions.h"

bool
fc_msgs__action__NavigateToPose_FeedbackMessage__init(fc_msgs__action__NavigateToPose_FeedbackMessage * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    fc_msgs__action__NavigateToPose_FeedbackMessage__fini(msg);
    return false;
  }
  // feedback
  if (!fc_msgs__action__NavigateToPose_Feedback__init(&msg->feedback)) {
    fc_msgs__action__NavigateToPose_FeedbackMessage__fini(msg);
    return false;
  }
  return true;
}

void
fc_msgs__action__NavigateToPose_FeedbackMessage__fini(fc_msgs__action__NavigateToPose_FeedbackMessage * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // feedback
  fc_msgs__action__NavigateToPose_Feedback__fini(&msg->feedback);
}

bool
fc_msgs__action__NavigateToPose_FeedbackMessage__are_equal(const fc_msgs__action__NavigateToPose_FeedbackMessage * lhs, const fc_msgs__action__NavigateToPose_FeedbackMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // feedback
  if (!fc_msgs__action__NavigateToPose_Feedback__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  return true;
}

bool
fc_msgs__action__NavigateToPose_FeedbackMessage__copy(
  const fc_msgs__action__NavigateToPose_FeedbackMessage * input,
  fc_msgs__action__NavigateToPose_FeedbackMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // feedback
  if (!fc_msgs__action__NavigateToPose_Feedback__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  return true;
}

fc_msgs__action__NavigateToPose_FeedbackMessage *
fc_msgs__action__NavigateToPose_FeedbackMessage__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fc_msgs__action__NavigateToPose_FeedbackMessage * msg = (fc_msgs__action__NavigateToPose_FeedbackMessage *)allocator.allocate(sizeof(fc_msgs__action__NavigateToPose_FeedbackMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(fc_msgs__action__NavigateToPose_FeedbackMessage));
  bool success = fc_msgs__action__NavigateToPose_FeedbackMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
fc_msgs__action__NavigateToPose_FeedbackMessage__destroy(fc_msgs__action__NavigateToPose_FeedbackMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    fc_msgs__action__NavigateToPose_FeedbackMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
fc_msgs__action__NavigateToPose_FeedbackMessage__Sequence__init(fc_msgs__action__NavigateToPose_FeedbackMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fc_msgs__action__NavigateToPose_FeedbackMessage * data = NULL;

  if (size) {
    data = (fc_msgs__action__NavigateToPose_FeedbackMessage *)allocator.zero_allocate(size, sizeof(fc_msgs__action__NavigateToPose_FeedbackMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = fc_msgs__action__NavigateToPose_FeedbackMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        fc_msgs__action__NavigateToPose_FeedbackMessage__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
fc_msgs__action__NavigateToPose_FeedbackMessage__Sequence__fini(fc_msgs__action__NavigateToPose_FeedbackMessage__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      fc_msgs__action__NavigateToPose_FeedbackMessage__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

fc_msgs__action__NavigateToPose_FeedbackMessage__Sequence *
fc_msgs__action__NavigateToPose_FeedbackMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fc_msgs__action__NavigateToPose_FeedbackMessage__Sequence * array = (fc_msgs__action__NavigateToPose_FeedbackMessage__Sequence *)allocator.allocate(sizeof(fc_msgs__action__NavigateToPose_FeedbackMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = fc_msgs__action__NavigateToPose_FeedbackMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
fc_msgs__action__NavigateToPose_FeedbackMessage__Sequence__destroy(fc_msgs__action__NavigateToPose_FeedbackMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    fc_msgs__action__NavigateToPose_FeedbackMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
fc_msgs__action__NavigateToPose_FeedbackMessage__Sequence__are_equal(const fc_msgs__action__NavigateToPose_FeedbackMessage__Sequence * lhs, const fc_msgs__action__NavigateToPose_FeedbackMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!fc_msgs__action__NavigateToPose_FeedbackMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
fc_msgs__action__NavigateToPose_FeedbackMessage__Sequence__copy(
  const fc_msgs__action__NavigateToPose_FeedbackMessage__Sequence * input,
  fc_msgs__action__NavigateToPose_FeedbackMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(fc_msgs__action__NavigateToPose_FeedbackMessage);
    fc_msgs__action__NavigateToPose_FeedbackMessage * data =
      (fc_msgs__action__NavigateToPose_FeedbackMessage *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!fc_msgs__action__NavigateToPose_FeedbackMessage__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          fc_msgs__action__NavigateToPose_FeedbackMessage__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!fc_msgs__action__NavigateToPose_FeedbackMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
