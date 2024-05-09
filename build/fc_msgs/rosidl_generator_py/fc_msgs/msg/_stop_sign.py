# generated from rosidl_generator_py/resource/_idl.py.em
# with input from fc_msgs:msg/StopSign.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_StopSign(type):
    """Metaclass of message 'StopSign'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('fc_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'fc_msgs.msg.StopSign')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__stop_sign
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__stop_sign
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__stop_sign
            cls._TYPE_SUPPORT = module.type_support_msg__msg__stop_sign
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__stop_sign

            from sensor_msgs.msg import Image
            if Image.__class__._TYPE_SUPPORT is None:
                Image.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class StopSign(metaclass=Metaclass_StopSign):
    """Message class 'StopSign'."""

    __slots__ = [
        '_is_stop',
        '_bounding_box',
    ]

    _fields_and_field_types = {
        'is_stop': 'boolean',
        'bounding_box': 'sensor_msgs/Image',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['sensor_msgs', 'msg'], 'Image'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.is_stop = kwargs.get('is_stop', bool())
        from sensor_msgs.msg import Image
        self.bounding_box = kwargs.get('bounding_box', Image())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.is_stop != other.is_stop:
            return False
        if self.bounding_box != other.bounding_box:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def is_stop(self):
        """Message field 'is_stop'."""
        return self._is_stop

    @is_stop.setter
    def is_stop(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'is_stop' field must be of type 'bool'"
        self._is_stop = value

    @property
    def bounding_box(self):
        """Message field 'bounding_box'."""
        return self._bounding_box

    @bounding_box.setter
    def bounding_box(self, value):
        if __debug__:
            from sensor_msgs.msg import Image
            assert \
                isinstance(value, Image), \
                "The 'bounding_box' field must be a sub message of type 'Image'"
        self._bounding_box = value
