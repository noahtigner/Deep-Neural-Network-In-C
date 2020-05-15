#include <stdio.h>
#include "vector.h"
#include "matrix.h"
#include "layer.h"
#include "utilities.h"

void layer_init(layer *l, int n_inputs, int n_neurons, activation activation_fn) {
    // MATRIX_INIT_RANDS(w, n_inputs, n_neurons);
    MATRIX_INIT_RANDS(w, n_neurons, n_inputs);  // Params are reversed to avoid transposition
    MATRIX_INIT_ZEROS(b, 1, n_neurons);
    l->weights = w;
    l->biases = b;
    l->activation_fn = activation_fn;
}

void layer_forward(layer *l, matrix inputs) {
    matrix outputs = MATRIX_MULTIPLICATION(inputs, l->weights);
    MATRIX_ADDITION(outputs, l->biases);
    switch (l->activation_fn) {
        case STEP:
            MATRIX_ACTIVATION_STEP(outputs);
            break;
        case SIGMOID:
            MATRIX_ACTIVATION_SIGMOID(outputs);
            break;
        case RELU:
            MATRIX_ACTIVATION_RELU(outputs);
            break;
        default:
            printf("%sWarning: no activation function specified%s\n", YELLOW, RESET);
            break;
    }
    l->output = outputs;
}

void layer_free(layer *l) {
    MATRIX_FREE(l->weights);
    MATRIX_FREE(l->biases);
}