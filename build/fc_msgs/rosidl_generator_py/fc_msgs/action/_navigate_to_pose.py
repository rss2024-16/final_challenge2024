# generated from rosidl_generator_py/resource/_idl.py.em
# with input from fc_msgs:action/NavigateToPose.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_NavigateToPose_Goal(type):
    """Metaclass of message 'NavigateToPose_Goal'."""

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
                'fc_msgs.action.NavigateToPose_Goal')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__navigate_to_pose__goal
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__navigate_to_pose__goal
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__navigate_to_pose__goal
            cls._TYPE_SUPPORT = module.type_support_msg__action__navigate_to_pose__goal
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__navigate_to_pose__goal

            from geometry_msgs.msg import PoseArray
            if PoseArray.__class__._TYPE_SUPPORT is None:
                PoseArray.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class NavigateToPose_Goal(metaclass=Metaclass_NavigateToPose_Goal):
    """Message class 'NavigateToPose_Goal'."""

    __slots__ = [
        '_trajectory',
        '_follow_lane',
    ]

    _fields_and_field_types = {
        'trajectory': 'geometry_msgs/PoseArray',
        'follow_lane': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'PoseArray'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from geometry_msgs.msg import PoseArray
        self.trajectory = kwargs.get('trajectory', PoseArray())
        self.follow_lane = kwargs.get('follow_lane', bool())

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
        if self.trajectory != other.trajectory:
            return False
        if self.follow_lane != other.follow_lane:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def trajectory(self):
        """Message field 'trajectory'."""
        return self._trajectory

    @trajectory.setter
    def trajectory(self, value):
        if __debug__:
            from geometry_msgs.msg import PoseArray
            assert \
                isinstance(value, PoseArray), \
                "The 'trajectory' field must be a sub message of type 'PoseArray'"
        self._trajectory = value

    @property
    def follow_lane(self):
        """Message field 'follow_lane'."""
        return self._follow_lane

    @follow_lane.setter
    def follow_lane(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'follow_lane' field must be of type 'bool'"
        self._follow_lane = value


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_NavigateToPose_Result(type):
    """Metaclass of message 'NavigateToPose_Result'."""

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
                'fc_msgs.action.NavigateToPose_Result')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__navigate_to_pose__result
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__navigate_to_pose__result
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__navigate_to_pose__result
            cls._TYPE_SUPPORT = module.type_support_msg__action__navigate_to_pose__result
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__navigate_to_pose__result

            from geometry_msgs.msg import Pose
            if Pose.__class__._TYPE_SUPPORT is None:
                Pose.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class NavigateToPose_Result(metaclass=Metaclass_NavigateToPose_Result):
    """Message class 'NavigateToPose_Result'."""

    __slots__ = [
        '_car_position',
    ]

    _fields_and_field_types = {
        'car_position': 'geometry_msgs/Pose',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Pose'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from geometry_msgs.msg import Pose
        self.car_position = kwargs.get('car_position', Pose())

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
        if self.car_position != other.car_position:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def car_position(self):
        """Message field 'car_position'."""
        return self._car_position

    @car_position.setter
    def car_position(self, value):
        if __debug__:
            from geometry_msgs.msg import Pose
            assert \
                isinstance(value, Pose), \
                "The 'car_position' field must be a sub message of type 'Pose'"
        self._car_position = value


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_NavigateToPose_Feedback(type):
    """Metaclass of message 'NavigateToPose_Feedback'."""

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
                'fc_msgs.action.NavigateToPose_Feedback')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__navigate_to_pose__feedback
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__navigate_to_pose__feedback
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__navigate_to_pose__feedback
            cls._TYPE_SUPPORT = module.type_support_msg__action__navigate_to_pose__feedback
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__navigate_to_pose__feedback

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class NavigateToPose_Feedback(metaclass=Metaclass_NavigateToPose_Feedback):
    """Message class 'NavigateToPose_Feedback'."""

    __slots__ = [
        '_outcome',
    ]

    _fields_and_field_types = {
        'outcome': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.outcome = kwargs.get('outcome', str())

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
        if self.outcome != other.outcome:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def outcome(self):
        """Message field 'outcome'."""
        return self._outcome

    @outcome.setter
    def outcome(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'outcome' field must be of type 'str'"
        self._outcome = value


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_NavigateToPose_SendGoal_Request(type):
    """Metaclass of message 'NavigateToPose_SendGoal_Request'."""

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
                'fc_msgs.action.NavigateToPose_SendGoal_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__navigate_to_pose__send_goal__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__navigate_to_pose__send_goal__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__navigate_to_pose__send_goal__request
            cls._TYPE_SUPPORT = module.type_support_msg__action__navigate_to_pose__send_goal__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__navigate_to_pose__send_goal__request

            from fc_msgs.action import NavigateToPose
            if NavigateToPose.Goal.__class__._TYPE_SUPPORT is None:
                NavigateToPose.Goal.__class__.__import_type_support__()

            from unique_identifier_msgs.msg import UUID
            if UUID.__class__._TYPE_SUPPORT is None:
                UUID.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class NavigateToPose_SendGoal_Request(metaclass=Metaclass_NavigateToPose_SendGoal_Request):
    """Message class 'NavigateToPose_SendGoal_Request'."""

    __slots__ = [
        '_goal_id',
        '_goal',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
        'goal': 'fc_msgs/NavigateToPose_Goal',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['fc_msgs', 'action'], 'NavigateToPose_Goal'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())
        from fc_msgs.action._navigate_to_pose import NavigateToPose_Goal
        self.goal = kwargs.get('goal', NavigateToPose_Goal())

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
        if self.goal_id != other.goal_id:
            return False
        if self.goal != other.goal:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def goal_id(self):
        """Message field 'goal_id'."""
        return self._goal_id

    @goal_id.setter
    def goal_id(self, value):
        if __debug__:
            from unique_identifier_msgs.msg import UUID
            assert \
                isinstance(value, UUID), \
                "The 'goal_id' field must be a sub message of type 'UUID'"
        self._goal_id = value

    @property
    def goal(self):
        """Message field 'goal'."""
        return self._goal

    @goal.setter
    def goal(self, value):
        if __debug__:
            from fc_msgs.action._navigate_to_pose import NavigateToPose_Goal
            assert \
                isinstance(value, NavigateToPose_Goal), \
                "The 'goal' field must be a sub message of type 'NavigateToPose_Goal'"
        self._goal = value


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_NavigateToPose_SendGoal_Response(type):
    """Metaclass of message 'NavigateToPose_SendGoal_Response'."""

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
                'fc_msgs.action.NavigateToPose_SendGoal_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__navigate_to_pose__send_goal__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__navigate_to_pose__send_goal__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__navigate_to_pose__send_goal__response
            cls._TYPE_SUPPORT = module.type_support_msg__action__navigate_to_pose__send_goal__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__navigate_to_pose__send_goal__response

            from builtin_interfaces.msg import Time
            if Time.__class__._TYPE_SUPPORT is None:
                Time.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class NavigateToPose_SendGoal_Response(metaclass=Metaclass_NavigateToPose_SendGoal_Response):
    """Message class 'NavigateToPose_SendGoal_Response'."""

    __slots__ = [
        '_accepted',
        '_stamp',
    ]

    _fields_and_field_types = {
        'accepted': 'boolean',
        'stamp': 'builtin_interfaces/Time',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['builtin_interfaces', 'msg'], 'Time'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.accepted = kwargs.get('accepted', bool())
        from builtin_interfaces.msg import Time
        self.stamp = kwargs.get('stamp', Time())

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
        if self.accepted != other.accepted:
            return False
        if self.stamp != other.stamp:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def accepted(self):
        """Message field 'accepted'."""
        return self._accepted

    @accepted.setter
    def accepted(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'accepted' field must be of type 'bool'"
        self._accepted = value

    @property
    def stamp(self):
        """Message field 'stamp'."""
        return self._stamp

    @stamp.setter
    def stamp(self, value):
        if __debug__:
            from builtin_interfaces.msg import Time
            assert \
                isinstance(value, Time), \
                "The 'stamp' field must be a sub message of type 'Time'"
        self._stamp = value


class Metaclass_NavigateToPose_SendGoal(type):
    """Metaclass of service 'NavigateToPose_SendGoal'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('fc_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'fc_msgs.action.NavigateToPose_SendGoal')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__action__navigate_to_pose__send_goal

            from fc_msgs.action import _navigate_to_pose
            if _navigate_to_pose.Metaclass_NavigateToPose_SendGoal_Request._TYPE_SUPPORT is None:
                _navigate_to_pose.Metaclass_NavigateToPose_SendGoal_Request.__import_type_support__()
            if _navigate_to_pose.Metaclass_NavigateToPose_SendGoal_Response._TYPE_SUPPORT is None:
                _navigate_to_pose.Metaclass_NavigateToPose_SendGoal_Response.__import_type_support__()


class NavigateToPose_SendGoal(metaclass=Metaclass_NavigateToPose_SendGoal):
    from fc_msgs.action._navigate_to_pose import NavigateToPose_SendGoal_Request as Request
    from fc_msgs.action._navigate_to_pose import NavigateToPose_SendGoal_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_NavigateToPose_GetResult_Request(type):
    """Metaclass of message 'NavigateToPose_GetResult_Request'."""

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
                'fc_msgs.action.NavigateToPose_GetResult_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__navigate_to_pose__get_result__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__navigate_to_pose__get_result__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__navigate_to_pose__get_result__request
            cls._TYPE_SUPPORT = module.type_support_msg__action__navigate_to_pose__get_result__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__navigate_to_pose__get_result__request

            from unique_identifier_msgs.msg import UUID
            if UUID.__class__._TYPE_SUPPORT is None:
                UUID.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class NavigateToPose_GetResult_Request(metaclass=Metaclass_NavigateToPose_GetResult_Request):
    """Message class 'NavigateToPose_GetResult_Request'."""

    __slots__ = [
        '_goal_id',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())

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
        if self.goal_id != other.goal_id:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def goal_id(self):
        """Message field 'goal_id'."""
        return self._goal_id

    @goal_id.setter
    def goal_id(self, value):
        if __debug__:
            from unique_identifier_msgs.msg import UUID
            assert \
                isinstance(value, UUID), \
                "The 'goal_id' field must be a sub message of type 'UUID'"
        self._goal_id = value


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_NavigateToPose_GetResult_Response(type):
    """Metaclass of message 'NavigateToPose_GetResult_Response'."""

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
                'fc_msgs.action.NavigateToPose_GetResult_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__navigate_to_pose__get_result__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__navigate_to_pose__get_result__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__navigate_to_pose__get_result__response
            cls._TYPE_SUPPORT = module.type_support_msg__action__navigate_to_pose__get_result__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__navigate_to_pose__get_result__response

            from fc_msgs.action import NavigateToPose
            if NavigateToPose.Result.__class__._TYPE_SUPPORT is None:
                NavigateToPose.Result.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class NavigateToPose_GetResult_Response(metaclass=Metaclass_NavigateToPose_GetResult_Response):
    """Message class 'NavigateToPose_GetResult_Response'."""

    __slots__ = [
        '_status',
        '_result',
    ]

    _fields_and_field_types = {
        'status': 'int8',
        'result': 'fc_msgs/NavigateToPose_Result',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['fc_msgs', 'action'], 'NavigateToPose_Result'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.status = kwargs.get('status', int())
        from fc_msgs.action._navigate_to_pose import NavigateToPose_Result
        self.result = kwargs.get('result', NavigateToPose_Result())

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
        if self.status != other.status:
            return False
        if self.result != other.result:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def status(self):
        """Message field 'status'."""
        return self._status

    @status.setter
    def status(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'status' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'status' field must be an integer in [-128, 127]"
        self._status = value

    @property
    def result(self):
        """Message field 'result'."""
        return self._result

    @result.setter
    def result(self, value):
        if __debug__:
            from fc_msgs.action._navigate_to_pose import NavigateToPose_Result
            assert \
                isinstance(value, NavigateToPose_Result), \
                "The 'result' field must be a sub message of type 'NavigateToPose_Result'"
        self._result = value


class Metaclass_NavigateToPose_GetResult(type):
    """Metaclass of service 'NavigateToPose_GetResult'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('fc_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'fc_msgs.action.NavigateToPose_GetResult')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__action__navigate_to_pose__get_result

            from fc_msgs.action import _navigate_to_pose
            if _navigate_to_pose.Metaclass_NavigateToPose_GetResult_Request._TYPE_SUPPORT is None:
                _navigate_to_pose.Metaclass_NavigateToPose_GetResult_Request.__import_type_support__()
            if _navigate_to_pose.Metaclass_NavigateToPose_GetResult_Response._TYPE_SUPPORT is None:
                _navigate_to_pose.Metaclass_NavigateToPose_GetResult_Response.__import_type_support__()


class NavigateToPose_GetResult(metaclass=Metaclass_NavigateToPose_GetResult):
    from fc_msgs.action._navigate_to_pose import NavigateToPose_GetResult_Request as Request
    from fc_msgs.action._navigate_to_pose import NavigateToPose_GetResult_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_NavigateToPose_FeedbackMessage(type):
    """Metaclass of message 'NavigateToPose_FeedbackMessage'."""

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
                'fc_msgs.action.NavigateToPose_FeedbackMessage')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__navigate_to_pose__feedback_message
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__navigate_to_pose__feedback_message
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__navigate_to_pose__feedback_message
            cls._TYPE_SUPPORT = module.type_support_msg__action__navigate_to_pose__feedback_message
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__navigate_to_pose__feedback_message

            from fc_msgs.action import NavigateToPose
            if NavigateToPose.Feedback.__class__._TYPE_SUPPORT is None:
                NavigateToPose.Feedback.__class__.__import_type_support__()

            from unique_identifier_msgs.msg import UUID
            if UUID.__class__._TYPE_SUPPORT is None:
                UUID.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class NavigateToPose_FeedbackMessage(metaclass=Metaclass_NavigateToPose_FeedbackMessage):
    """Message class 'NavigateToPose_FeedbackMessage'."""

    __slots__ = [
        '_goal_id',
        '_feedback',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
        'feedback': 'fc_msgs/NavigateToPose_Feedback',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['fc_msgs', 'action'], 'NavigateToPose_Feedback'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())
        from fc_msgs.action._navigate_to_pose import NavigateToPose_Feedback
        self.feedback = kwargs.get('feedback', NavigateToPose_Feedback())

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
        if self.goal_id != other.goal_id:
            return False
        if self.feedback != other.feedback:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def goal_id(self):
        """Message field 'goal_id'."""
        return self._goal_id

    @goal_id.setter
    def goal_id(self, value):
        if __debug__:
            from unique_identifier_msgs.msg import UUID
            assert \
                isinstance(value, UUID), \
                "The 'goal_id' field must be a sub message of type 'UUID'"
        self._goal_id = value

    @property
    def feedback(self):
        """Message field 'feedback'."""
        return self._feedback

    @feedback.setter
    def feedback(self, value):
        if __debug__:
            from fc_msgs.action._navigate_to_pose import NavigateToPose_Feedback
            assert \
                isinstance(value, NavigateToPose_Feedback), \
                "The 'feedback' field must be a sub message of type 'NavigateToPose_Feedback'"
        self._feedback = value


class Metaclass_NavigateToPose(type):
    """Metaclass of action 'NavigateToPose'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('fc_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'fc_msgs.action.NavigateToPose')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_action__action__navigate_to_pose

            from action_msgs.msg import _goal_status_array
            if _goal_status_array.Metaclass_GoalStatusArray._TYPE_SUPPORT is None:
                _goal_status_array.Metaclass_GoalStatusArray.__import_type_support__()
            from action_msgs.srv import _cancel_goal
            if _cancel_goal.Metaclass_CancelGoal._TYPE_SUPPORT is None:
                _cancel_goal.Metaclass_CancelGoal.__import_type_support__()

            from fc_msgs.action import _navigate_to_pose
            if _navigate_to_pose.Metaclass_NavigateToPose_SendGoal._TYPE_SUPPORT is None:
                _navigate_to_pose.Metaclass_NavigateToPose_SendGoal.__import_type_support__()
            if _navigate_to_pose.Metaclass_NavigateToPose_GetResult._TYPE_SUPPORT is None:
                _navigate_to_pose.Metaclass_NavigateToPose_GetResult.__import_type_support__()
            if _navigate_to_pose.Metaclass_NavigateToPose_FeedbackMessage._TYPE_SUPPORT is None:
                _navigate_to_pose.Metaclass_NavigateToPose_FeedbackMessage.__import_type_support__()


class NavigateToPose(metaclass=Metaclass_NavigateToPose):

    # The goal message defined in the action definition.
    from fc_msgs.action._navigate_to_pose import NavigateToPose_Goal as Goal
    # The result message defined in the action definition.
    from fc_msgs.action._navigate_to_pose import NavigateToPose_Result as Result
    # The feedback message defined in the action definition.
    from fc_msgs.action._navigate_to_pose import NavigateToPose_Feedback as Feedback

    class Impl:

        # The send_goal service using a wrapped version of the goal message as a request.
        from fc_msgs.action._navigate_to_pose import NavigateToPose_SendGoal as SendGoalService
        # The get_result service using a wrapped version of the result message as a response.
        from fc_msgs.action._navigate_to_pose import NavigateToPose_GetResult as GetResultService
        # The feedback message with generic fields which wraps the feedback message.
        from fc_msgs.action._navigate_to_pose import NavigateToPose_FeedbackMessage as FeedbackMessage

        # The generic service to cancel a goal.
        from action_msgs.srv._cancel_goal import CancelGoal as CancelGoalService
        # The generic message for get the status of a goal.
        from action_msgs.msg._goal_status_array import GoalStatusArray as GoalStatusMessage

    def __init__(self):
        raise NotImplementedError('Action classes can not be instantiated')
