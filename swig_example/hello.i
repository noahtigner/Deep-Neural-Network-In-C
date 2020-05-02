/* File: hello.i */
%module hello
%{
   #define SWIG_FILE_WITH_INIT
   #include "hello.h"
%}
%include "hello.h"