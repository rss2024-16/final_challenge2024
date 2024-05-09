// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from fc_msgs:msg/StopSign.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "fc_msgs/msg/detail/stop_sign__struct.h"
#include "fc_msgs/msg/detail/stop_sign__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool sensor_msgs__msg__image__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * sensor_msgs__msg__image__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool fc_msgs__msg__stop_sign__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[32];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("fc_msgs.msg._stop_sign.StopSign", full_classname_dest, 31) == 0);
  }
  fc_msgs__msg__StopSign * ros_message = _ros_message;
  {  // is_stop
    PyObject * field = PyObject_GetAttrString(_pymsg, "is_stop");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->is_stop = (Py_True == field);
    Py_DECREF(field);
  }
  {  // bounding_box
    PyObject * field = PyObject_GetAttrString(_pymsg, "bounding_box");
    if (!field) {
      return false;
    }
    if (!sensor_msgs__msg__image__convert_from_py(field, &ros_message->bounding_box)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * fc_msgs__msg__stop_sign__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of StopSign */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("fc_msgs.msg._stop_sign");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "StopSign");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  fc_msgs__msg__StopSign * ros_message = (fc_msgs__msg__StopSign *)raw_ros_message;
  {  // is_stop
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->is_stop ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "is_stop", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // bounding_box
    PyObject * field = NULL;
    field = sensor_msgs__msg__image__convert_to_py(&ros_message->bounding_box);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "bounding_box", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
