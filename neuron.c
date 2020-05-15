#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "neuron.h"
#include "vector.h"
#include "matrix.h"
#include "layer.h"
#include "utilities.h"

int main() {
    // double w1[4] = {0.2, 0.8, -0.5, 1.0};
    // VECTOR_INIT(weights1);
    // VECTOR_ADD_MANY(weights1, w1);

    // double w2[4] = {0.5, -0.91, 0.26, -0.5};
    // VECTOR_INIT(weights2);
    // VECTOR_ADD_MANY(weights2, w2);

    // double w3[4] = {-0.26, -0.27, 0.17, 0.87};
    // VECTOR_INIT(weights3);
    // VECTOR_ADD_MANY(weights3, w3);

    // double bs[3] = {2.0, 3.0, 0.5};
    // VECTOR_INIT(biases);
    // VECTOR_ADD_MANY(biases, bs);

    // // double output[3] = {
    // //     vector_dot_product(inputs, weights1) + VECTOR_GET(biases, 0),
    // //     vector_dot_product(inputs, weights2) + VECTOR_GET(biases, 1),
    // //     vector_dot_product(inputs, weights3) + VECTOR_GET(biases, 2),
    // // };
    // // printf("%f, %f, %f\n\n", output[0], output[1], output[2]);



    // MATRIX_INIT(weights);
    // MATRIX_ADD(weights, weights1);
    // MATRIX_ADD(weights, weights2);
    // MATRIX_ADD(weights, weights3);
    // // MATRIX_DELETE(m, 0);
    // MATRIX_PRINT(weights);
    // MATRIX_PRINT(inputs);

    // // VECTOR_FREE(inputs);
    // // VECTOR_FREE(weights1);
    // // VECTOR_FREE(weights2);
    // // VECTOR_FREE(weights3);
    

    // MATRIX_TRANSPOSE(inputs, t);
    // MATRIX_PRINT(t);

    // // matrix outputs = MATRIX_MULTIPLICATION(weights, inputs);
    // matrix outputs = MATRIX_MULTIPLICATION(inputs, weights);
    // MATRIX_PRINT(outputs);
    // MATRIX_SCALE_BY_VECTOR(outputs, biases);
    // MATRIX_PRINT(outputs);


    // MATRIX_FREE(weights);
    // MATRIX_FREE(inputs);
    // MATRIX_FREE(t);
    // VECTOR_FREE(biases);

    // MATRIX_INIT_ZEROS(z, 4, 3);
    // MATRIX_PRINT(z);
    // MATRIX_FREE(z);

    // Setup
    // ================================================================
    srand(time(NULL));  // seed random function

    // Initialize Input
    // ================================================================
    double in[3][4] = {{1.0, 2.0, 3.0, 2.5},
                       {2.0, 5.0, -1.0, 2.0},
                       {-1.5, 2.7, 3.3, -0.8}};
    VECTOR_INIT(inputs1);
    VECTOR_INIT(inputs2);
    VECTOR_INIT(inputs3);
    VECTOR_ADD_MANY(inputs1, in[0]);
    VECTOR_ADD_MANY(inputs2, in[1]);
    VECTOR_ADD_MANY(inputs3, in[2]);
    MATRIX_INIT(inputs);
    MATRIX_ADD(inputs, inputs1);
    MATRIX_ADD(inputs, inputs2);
    MATRIX_ADD(inputs, inputs3);

    // Initialize Layers
    // ================================================================
    LAYER_INIT(layer1, 4, 5, RELU);
    LAYER_INIT(layer2, 5, 2, RELU);

    // Forward Passes
    // ================================================================
    LAYER_FORWARD(layer1, inputs);
    LAYER_FORWARD(layer2, layer1.output);

    MATRIX_PRINT(layer1.output);
    MATRIX_PRINT(layer2.output);

    // Free Memory
    // ================================================================
    LAYER_FREE(layer1);
    LAYER_FREE(layer2);
    MATRIX_FREE(inputs);

    return 0;
}
