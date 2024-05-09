// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from fc_msgs:srv/LaneProject.idl
// generated code does not contain a copyright notice
#include "fc_msgs/srv/detail/lane_project__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `location`
#include "geometry_msgs/msg/detail/point_stamped__functions.h"

bool
fc_msgs__srv__LaneProject_Request__init(fc_msgs__srv__LaneProject_Request * msg)
{
  if (!msg) {
    return false;
  }
  // location
  if (!geometry_msgs__msg__PointStamped__init(&msg->location)) {
    fc_msgs__srv__LaneProject_Request__fini(msg);
    return false;
  }
  // right
  return true;
}

void
fc_msgs__srv__LaneProject_Request__fini(fc_msgs__srv__LaneProject_Request * msg)
{
  if (!msg) {
    return;
  }
  // location
  geometry_msgs__msg__PointStamped__fini(&msg->location);
  // right
}

bool
fc_msgs__srv__LaneProject_Request__are_equal(const fc_msgs__srv__LaneProject_Request * lhs, const fc_msgs__srv__LaneProject_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // location
  if (!geometry_msgs__msg__PointStamped__are_equal(
      &(lhs->location), &(rhs->location)))
  {
    return false;
  }
  // right
  if (lhs->right != rhs->right) {
    return false;
  }
  return true;
}

bool
fc_msgs__srv__LaneProject_Request__copy(
  const fc_msgs__srv__LaneProject_Request * input,
  fc_msgs__srv__LaneProject_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // location
  if (!geometry_msgs__msg__PointStamped__copy(
      &(input->location), &(output->location)))
  {
    return false;
  }
  // right
  output->right = input->right;
  return true;
}

fc_msgs__srv__LaneProject_Request *
fc_msgs__srv__LaneProject_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fc_msgs__srv__LaneProject_Request * msg = (fc_msgs__srv__LaneProject_Request *)allocator.allocate(sizeof(fc_msgs__srv__LaneProject_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(fc_msgs__srv__LaneProject_Request));
  bool success = fc_msgs__srv__LaneProject_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
fc_msgs__srv__LaneProject_Request__destroy(fc_msgs__srv__LaneProject_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    fc_msgs__srv__LaneProject_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
fc_msgs__srv__LaneProject_Request__Sequence__init(fc_msgs__srv__LaneProject_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fc_msgs__srv__LaneProject_Request * data = NULL;

  if (size) {
    data = (fc_msgs__srv__LaneProject_Request *)allocator.zero_allocate(size, sizeof(fc_msgs__srv__LaneProject_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = fc_msgs__srv__LaneProject_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        fc_msgs__srv__LaneProject_Request__fini(&data[i - 1]);
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
fc_msgs__srv__LaneProject_Request__Sequence__fini(fc_msgs__srv__LaneProject_Request__Sequence * array)
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
      fc_msgs__srv__LaneProject_Request__fini(&array->data[i]);
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

fc_msgs__srv__LaneProject_Request__Sequence *
fc_msgs__srv__LaneProject_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fc_msgs__srv__LaneProject_Request__Sequence * array = (fc_msgs__srv__LaneProject_Request__Sequence *)allocator.allocate(sizeof(fc_msgs__srv__LaneProject_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = fc_msgs__srv__LaneProject_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
fc_msgs__srv__LaneProject_Request__Sequence__destroy(fc_msgs__srv__LaneProject_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    fc_msgs__srv__LaneProject_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
fc_msgs__srv__LaneProject_Request__Sequence__are_equal(const fc_msgs__srv__LaneProject_Request__Sequence * lhs, const fc_msgs__srv__LaneProject_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!fc_msgs__srv__LaneProject_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
fc_msgs__srv__LaneProject_Request__Sequence__copy(
  const fc_msgs__srv__LaneProject_Request__Sequence * input,
  fc_msgs__srv__LaneProject_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(fc_msgs__srv__LaneProject_Request);
    fc_msgs__srv__LaneProject_Request * data =
      (fc_msgs__srv__LaneProject_Request *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!fc_msgs__srv__LaneProject_Request__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          fc_msgs__srv__LaneProject_Request__fini(&data[i]);
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
    if (!fc_msgs__srv__LaneProject_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `projection`
#include "geometry_msgs/msg/detail/pose__functions.h"

bool
fc_msgs__srv__LaneProject_Response__init(fc_msgs__srv__LaneProject_Response * msg)
{
  if (!msg) {
    return false;
  }
  // projection
  if (!geometry_msgs__msg__Pose__init(&msg->projection)) {
    fc_msgs__srv__LaneProject_Response__fini(msg);
    return false;
  }
  return true;
}

void
fc_msgs__srv__LaneProject_Response__fini(fc_msgs__srv__LaneProject_Response * msg)
{
  if (!msg) {
    return;
  }
  // projection
  geometry_msgs__msg__Pose__fini(&msg->projection);
}

bool
fc_msgs__srv__LaneProject_Response__are_equal(const fc_msgs__srv__LaneProject_Response * lhs, const fc_msgs__srv__LaneProject_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // projection
  if (!geometry_msgs__msg__Pose__are_equal(
      &(lhs->projection), &(rhs->projection)))
  {
    return false;
  }
  return true;
}

bool
fc_msgs__srv__LaneProject_Response__copy(
  const fc_msgs__srv__LaneProject_Response * input,
  fc_msgs__srv__LaneProject_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // projection
  if (!geometry_msgs__msg__Pose__copy(
      &(input->projection), &(output->projection)))
  {
    return false;
  }
  return true;
}

fc_msgs__srv__LaneProject_Response *
fc_msgs__srv__LaneProject_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fc_msgs__srv__LaneProject_Response * msg = (fc_msgs__srv__LaneProject_Response *)allocator.allocate(sizeof(fc_msgs__srv__LaneProject_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(fc_msgs__srv__LaneProject_Response));
  bool success = fc_msgs__srv__LaneProject_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
fc_msgs__srv__LaneProject_Response__destroy(fc_msgs__srv__LaneProject_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    fc_msgs__srv__LaneProject_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
fc_msgs__srv__LaneProject_Response__Sequence__init(fc_msgs__srv__LaneProject_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fc_msgs__srv__LaneProject_Response * data = NULL;

  if (size) {
    data = (fc_msgs__srv__LaneProject_Response *)allocator.zero_allocate(size, sizeof(fc_msgs__srv__LaneProject_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = fc_msgs__srv__LaneProject_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        fc_msgs__srv__LaneProject_Response__fini(&data[i - 1]);
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
fc_msgs__srv__LaneProject_Response__Sequence__fini(fc_msgs__srv__LaneProject_Response__Sequence * array)
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
      fc_msgs__srv__LaneProject_Response__fini(&array->data[i]);
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

fc_msgs__srv__LaneProject_Response__Sequence *
fc_msgs__srv__LaneProject_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fc_msgs__srv__LaneProject_Response__Sequence * array = (fc_msgs__srv__LaneProject_Response__Sequence *)allocator.allocate(sizeof(fc_msgs__srv__LaneProject_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = fc_msgs__srv__LaneProject_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
fc_msgs__srv__LaneProject_Response__Sequence__destroy(fc_msgs__srv__LaneProject_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    fc_msgs__srv__LaneProject_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
fc_msgs__srv__LaneProject_Response__Sequence__are_equal(const fc_msgs__srv__LaneProject_Response__Sequence * lhs, const fc_msgs__srv__LaneProject_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!fc_msgs__srv__LaneProject_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
fc_msgs__srv__LaneProject_Response__Sequence__copy(
  const fc_msgs__srv__LaneProject_Response__Sequence * input,
  fc_msgs__srv__LaneProject_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(fc_msgs__srv__LaneProject_Response);
    fc_msgs__srv__LaneProject_Response * data =
      (fc_msgs__srv__LaneProject_Response *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!fc_msgs__srv__LaneProject_Response__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          fc_msgs__srv__LaneProject_Response__fini(&data[i]);
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
    if (!fc_msgs__srv__LaneProject_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
