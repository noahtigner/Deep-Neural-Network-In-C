# This file was automatically generated by SWIG (http://www.swig.org).
# Version 4.0.1
#
# Do not make changes to this file unless you know what you are doing--modify
# the SWIG interface file instead.

from sys import version_info as _swig_python_version_info
if _swig_python_version_info < (2, 7, 0):
    raise RuntimeError("Python 2.7 or later required")

# Import the low-level C/C++ module
if __package__ or "." in __name__:
    from . import _neuron
else:
    import _neuron

try:
    import builtins as __builtin__
except ImportError:
    import __builtin__

def _swig_repr(self):
    try:
        strthis = "proxy of " + self.this.__repr__()
    except __builtin__.Exception:
        strthis = ""
    return "<%s.%s; %s >" % (self.__class__.__module__, self.__class__.__name__, strthis,)


def _swig_setattr_nondynamic_instance_variable(set):
    def set_instance_attr(self, name, value):
        if name == "thisown":
            self.this.own(value)
        elif name == "this":
            set(self, name, value)
        elif hasattr(self, name) and isinstance(getattr(type(self), name), property):
            set(self, name, value)
        else:
            raise AttributeError("You cannot add instance attributes to %s" % self)
    return set_instance_attr


def _swig_setattr_nondynamic_class_variable(set):
    def set_class_attr(cls, name, value):
        if hasattr(cls, name) and not isinstance(getattr(cls, name), property):
            set(cls, name, value)
        else:
            raise AttributeError("You cannot add class attributes to %s" % cls)
    return set_class_attr


def _swig_add_metaclass(metaclass):
    """Class decorator for adding a metaclass to a SWIG wrapped class - a slimmed down version of six.add_metaclass"""
    def wrapper(cls):
        return metaclass(cls.__name__, cls.__bases__, cls.__dict__.copy())
    return wrapper


class _SwigNonDynamicMeta(type):
    """Meta class to enforce nondynamic attributes (no new attributes) for a class"""
    __setattr__ = _swig_setattr_nondynamic_class_variable(type.__setattr__)



def vectorDotProduct(v1: "vector", v2: "vector") -> "double":
    return _neuron.vectorDotProduct(v1, v2)

def main() -> "int":
    return _neuron.main()
VECTOR_INIT_CAPACITY = _neuron.VECTOR_INIT_CAPACITY
class vector(object):
    thisown = property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc="The membership flag")
    __repr__ = _swig_repr
    items = property(_neuron.vector_items_get, _neuron.vector_items_set)
    capacity = property(_neuron.vector_capacity_get, _neuron.vector_capacity_set)
    total = property(_neuron.vector_total_get, _neuron.vector_total_set)

    def __init__(self):
        _neuron.vector_swiginit(self, _neuron.new_vector())
    __swig_destroy__ = _neuron.delete_vector

# Register vector in _neuron:
_neuron.vector_swigregister(vector)


def vector_init(arg1: "vector") -> "void":
    return _neuron.vector_init(arg1)

def vector_total(arg1: "vector") -> "int":
    return _neuron.vector_total(arg1)

def vector_print(arg1: "vector") -> "void":
    return _neuron.vector_print(arg1)

def vector_resize(arg1: "vector", arg2: "int") -> "void":
    return _neuron.vector_resize(arg1, arg2)

def vector_add(arg1: "vector", arg2: "double") -> "void":
    return _neuron.vector_add(arg1, arg2)

def vector_add_many(arg1: "vector", arg2: "double []", arg3: "int") -> "void":
    return _neuron.vector_add_many(arg1, arg2, arg3)

def vector_set(arg1: "vector", arg2: "int", arg3: "double") -> "void":
    return _neuron.vector_set(arg1, arg2, arg3)

def vector_get(arg1: "vector", arg2: "int") -> "double":
    return _neuron.vector_get(arg1, arg2)

def vector_delete(arg1: "vector", arg2: "int") -> "void":
    return _neuron.vector_delete(arg1, arg2)

def vector_free(arg1: "vector") -> "void":
    return _neuron.vector_free(arg1)
RED = _neuron.RED
GREEN = _neuron.GREEN
YELLOW = _neuron.YELLOW
BLUE = _neuron.BLUE
MAGENTA = _neuron.MAGENTA
CYAN = _neuron.CYAN
RESET = _neuron.RESET


