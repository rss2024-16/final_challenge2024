// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from fc_msgs:msg/StopLightPixel.idl
// generated code does not contain a copyright notice
#include "fc_msgs/msg/detail/stop_light_pixel__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
fc_msgs__msg__StopLightPixel__init(fc_msgs__msg__StopLightPixel * msg)
{
  if (!msg) {
    return false;
  }
  // u
  // v
  return true;
}

void
fc_msgs__msg__StopLightPixel__fini(fc_msgs__msg__StopLightPixel * msg)
{
  if (!msg) {
    return;
  }
  // u
  // v
}

bool
fc_msgs__msg__StopLightPixel__are_equal(const fc_msgs__msg__StopLightPixel * lhs, const fc_msgs__msg__StopLightPixel * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // u
  if (lhs->u != rhs->u) {
    return false;
  }
  // v
  if (lhs->v != rhs->v) {
    return false;
  }
  return true;
}

bool
fc_msgs__msg__StopLightPixel__copy(
  const fc_msgs__msg__StopLightPixel * input,
  fc_msgs__msg__StopLightPixel * output)
{
  if (!input || !output) {
    return false;
  }
  // u
  output->u = input->u;
  // v
  output->v = input->v;
  return true;
}

fc_msgs__msg__StopLightPixel *
fc_msgs__msg__StopLightPixel__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fc_msgs__msg__StopLightPixel * msg = (fc_msgs__msg__StopLightPixel *)allocator.allocate(sizeof(fc_msgs__msg__StopLightPixel), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(fc_msgs__msg__StopLightPixel));
  bool success = fc_msgs__msg__StopLightPixel__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
fc_msgs__msg__StopLightPixel__destroy(fc_msgs__msg__StopLightPixel * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    fc_msgs__msg__StopLightPixel__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
fc_msgs__msg__StopLightPixel__Sequence__init(fc_msgs__msg__StopLightPixel__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fc_msgs__msg__StopLightPixel * data = NULL;

  if (size) {
    data = (fc_msgs__msg__StopLightPixel *)allocator.zero_allocate(size, sizeof(fc_msgs__msg__StopLightPixel), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = fc_msgs__msg__StopLightPixel__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        fc_msgs__msg__StopLightPixel__fini(&data[i - 1]);
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
fc_msgs__msg__StopLightPixel__Sequence__fini(fc_msgs__msg__StopLightPixel__Sequence * array)
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
      fc_msgs__msg__StopLightPixel__fini(&array->data[i]);
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

fc_msgs__msg__StopLightPixel__Sequence *
fc_msgs__msg__StopLightPixel__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fc_msgs__msg__StopLightPixel__Sequence * array = (fc_msgs__msg__StopLightPixel__Sequence *)allocator.allocate(sizeof(fc_msgs__msg__StopLightPixel__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = fc_msgs__msg__StopLightPixel__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
fc_msgs__msg__StopLightPixel__Sequence__destroy(fc_msgs__msg__StopLightPixel__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    fc_msgs__msg__StopLightPixel__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
fc_msgs__msg__StopLightPixel__Sequence__are_equal(const fc_msgs__msg__StopLightPixel__Sequence * lhs, const fc_msgs__msg__StopLightPixel__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!fc_msgs__msg__StopLightPixel__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
fc_msgs__msg__StopLightPixel__Sequence__copy(
  const fc_msgs__msg__StopLightPixel__Sequence * input,
  fc_msgs__msg__StopLightPixel__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(fc_msgs__msg__StopLightPixel);
    fc_msgs__msg__StopLightPixel * data =
      (fc_msgs__msg__StopLightPixel *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!fc_msgs__msg__StopLightPixel__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          fc_msgs__msg__StopLightPixel__fini(&data[i]);
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
    if (!fc_msgs__msg__StopLightPixel__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
