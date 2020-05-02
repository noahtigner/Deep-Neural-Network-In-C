#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "neuron.h"
#include "vectord.h"
#include "utilities.h"

double vectorDotProduct(vector v1, vector v2) {
    int length = VECTOR_TOTAL(v1);
    if(length != VECTOR_TOTAL(v2)) {
        printf("%sWarning: vector lengths match%s\n", YELLOW, RESET);
        return ERROR_CODE;
    }

    double dp = 0.0;
    for(int i = 0; i < length; i++) {
        dp += VECTOR_GET(v1, i) * VECTOR_GET(v2, i);
    }
    return dp;
}

// TODO: matrix (vector of vectors)
// TODO: transpose matrix funtion
// TODO: do product of matrices

int main() {

    double in[4] = {1, 2, 3, 2.5};
    VECTOR_INIT(inputs);
    VECTOR_ADD_MANY(inputs, in);

    double w1[4] = {0.2, 0.8, -0.5, 1.0};
    VECTOR_INIT(weights1);
    VECTOR_ADD_MANY(weights1, w1);

    double w2[4] = {0.5, -0.91, 0.26, -0.5};
    VECTOR_INIT(weights2);
    VECTOR_ADD_MANY(weights2, w2);

    double w3[4] = {-0.26, -0.27, 0.17, 0.87};
    VECTOR_INIT(weights3);
    VECTOR_ADD_MANY(weights3, w3);

    double bs[3] = {2.0, 3.0, 0.5};
    VECTOR_INIT(biases);
    VECTOR_ADD_MANY(biases, bs);

    double output[3] = {
        vectorDotProduct(inputs, weights1) + VECTOR_GET(biases, 0),
        vectorDotProduct(inputs, weights2) + VECTOR_GET(biases, 1),
        vectorDotProduct(inputs, weights3) + VECTOR_GET(biases, 2),
    };
    printf("\n%f, %f, %f\n", output[0], output[1], output[2]);

    VECTOR_FREE(inputs);
    VECTOR_FREE(weights1);
    VECTOR_FREE(weights2);
    VECTOR_FREE(weights3);
    
    return 0;
}
