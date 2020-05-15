#include "vector.h"
#include "matrix.h"

#ifndef LAYER
#define LAYER

#define LAYER_INIT(lay, n_inputs, n_neurons, activation_fn) layer lay; layer_init(&lay, n_inputs, n_neurons, activation_fn)
#define LAYER_FORWARD(lay, inputs) layer_forward(&lay, inputs)
#define LAYER_FREE(lay) layer_free(&lay)

typedef enum {STEP, SIGMOID, RELU} activation;

typedef struct {
    matrix weights;
    matrix biases;
    matrix output;
    activation activation_fn;
} layer;

void layer_init(layer *, int, int, activation);
void layer_forward(layer *, matrix);
void layer_free(layer *);

#endif