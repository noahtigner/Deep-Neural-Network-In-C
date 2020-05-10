/* File: neuron.i */
%module neuron
%{
   %define SWIG_FILE_WITH_INIT
   #include "neuron.h"
   #include "vectord.h"
   #include "utilities.h"
%}
%include "neuron.h"
%include "vectord.h"
%include "utilities.h"