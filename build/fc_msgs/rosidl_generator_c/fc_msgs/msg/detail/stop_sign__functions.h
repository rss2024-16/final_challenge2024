// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from fc_msgs:msg/StopSign.idl
// generated code does not contain a copyright notice

#ifndef FC_MSGS__MSG__DETAIL__STOP_SIGN__FUNCTIONS_H_
#define FC_MSGS__MSG__DETAIL__STOP_SIGN__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "fc_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "fc_msgs/msg/detail/stop_sign__struct.h"

/// Initialize msg/StopSign message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * fc_msgs__msg__StopSign
 * )) before or use
 * fc_msgs__msg__StopSign__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_fc_msgs
bool
fc_msgs__msg__StopSign__init(fc_msgs__msg__StopSign * msg);

/// Finalize msg/StopSign message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_fc_msgs
void
fc_msgs__msg__StopSign__fini(fc_msgs__msg__StopSign * msg);

/// Create msg/StopSign message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * fc_msgs__msg__StopSign__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_fc_msgs
fc_msgs__msg__StopSign *
fc_msgs__msg__StopSign__create();

/// Destroy msg/StopSign message.
/**
 * It calls
 * fc_msgs__msg__StopSign__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_fc_msgs
void
fc_msgs__msg__StopSign__destroy(fc_msgs__msg__StopSign * msg);

/// Check for msg/StopSign message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_fc_msgs
bool
fc_msgs__msg__StopSign__are_equal(const fc_msgs__msg__StopSign * lhs, const fc_msgs__msg__StopSign * rhs);

/// Copy a msg/StopSign message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_fc_msgs
bool
fc_msgs__msg__StopSign__copy(
  const fc_msgs__msg__StopSign * input,
  fc_msgs__msg__StopSign * output);

/// Initialize array of msg/StopSign messages.
/**
 * It allocates the memory for the number of elements and calls
 * fc_msgs__msg__StopSign__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_fc_msgs
bool
fc_msgs__msg__StopSign__Sequence__init(fc_msgs__msg__StopSign__Sequence * array, size_t size);

/// Finalize array of msg/StopSign messages.
/**
 * It calls
 * fc_msgs__msg__StopSign__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_fc_msgs
void
fc_msgs__msg__StopSign__Sequence__fini(fc_msgs__msg__StopSign__Sequence * array);

/// Create array of msg/StopSign messages.
/**
 * It allocates the memory for the array and calls
 * fc_msgs__msg__StopSign__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_fc_msgs
fc_msgs__msg__StopSign__Sequence *
fc_msgs__msg__StopSign__Sequence__create(size_t size);

/// Destroy array of msg/StopSign messages.
/**
 * It calls
 * fc_msgs__msg__StopSign__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_fc_msgs
void
fc_msgs__msg__StopSign__Sequence__destroy(fc_msgs__msg__StopSign__Sequence * array);

/// Check for msg/StopSign message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_fc_msgs
bool
fc_msgs__msg__StopSign__Sequence__are_equal(const fc_msgs__msg__StopSign__Sequence * lhs, const fc_msgs__msg__StopSign__Sequence * rhs);

/// Copy an array of msg/StopSign messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_fc_msgs
bool
fc_msgs__msg__StopSign__Sequence__copy(
  const fc_msgs__msg__StopSign__Sequence * input,
  fc_msgs__msg__StopSign__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // FC_MSGS__MSG__DETAIL__STOP_SIGN__FUNCTIONS_H_
