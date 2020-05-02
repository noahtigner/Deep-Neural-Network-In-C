#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
// #include "vc_vector.h"
#include "neuron.h"

// #include "vector.h"
#include "vectord.h"

int neuron(void) {

    // double integer, value = 237.3455, fraction = modf(value, &integer);
    // printf("value = %g, integer = %g, fraction = %g\n",
    //        value, integer, fraction);

    // double d = 3.1415;
    // double whole;
    // double decimal;
    // decimal = modf(d, &whole);
    // int w = whole;
    // printf("whole: %d, decimal: %f, sum: %f",  (int) whole, decimal, (double) whole + decimal);
    


    // FIXME: floats and doubles ??
    VECTOR_INIT(v);
    VECTOR_ADD(v, 3.1415);
    VECTOR_ADD(v, 9.1415);
    VECTOR_ADD(v, -77.1415);
    VECTOR_ADD(v, -7.1415);
    VECTOR_ADD(v, -0.1415);
    // VECTOR_DELETE(v, 0);
    // VECTOR_ADD(v, 5);
    // VECTOR_ADD(v, &7.99, FLOAT);
    // VECTOR_ADD(v, "\n", STR);
    // VECTOR_SET(v, 0, 4);
    VECTOR_PRINT(v);
    // for (int i = 0; i < VECTOR_TOTAL(v); i++)
    //     printf("%f ", strtod(VECTOR_GET(v, i), NULL));
    // printf("\n");
    printf("get+1: %f ", VECTOR_GET(v, 0) + 1.0);
    VECTOR_SET(v, 0, VECTOR_GET(v, 0) + 1.0);
    VECTOR_FREE(v);


    // enum type {
    //     INT,
    //     BOOL,
    //     FLOAT,
    //     DOUBLE,
    //     CHAR,
    //     STR,
    
    // };

    // typedef struct {
    //     enum type type;
    //     union {
    //         int i;
    //         bool b;
    //         float f;
    //         double d;
    //         char c;
    //         char* s;
    //     } val;
    // } value;

    // // value val1 = {INT, 3};
    // value val1;
    // val1.type = INT;
    // val1.val.i = 2;
    // // value val2;
    // // val2.type = STR;
    // // val2.val.s = "hey";
    // value val2 = {.type=STR, .val.s="hey"};

    // // printf("%d ", val1.val);

    // int i;

    // // VECTOR_INIT(v);
    // // VECTOR_ADD(v, "Bonjour");
    // // for (i = 0; i < VECTOR_TOTAL(v); i++)
    // //     printf("%s ", VECTOR_GET(v, char*, i));
    // // VECTOR_DELETE(v, 3);
    // // VECTOR_SET(v, 0, "Hello");
    // // VECTOR_FREE(v);

    // VECTOR_INIT(v);

    // VECTOR_ADD(v, &val1);
    // VECTOR_ADD(v, &val2);

    // // value v3 = *((value*) VECTOR_GET(v, 0));
    // // printf("%d ", v3.val);

    // // printf("%d ", (*((value*) VECTOR_GET(v, 0))).val.i);

    // // printf("%d ", (*((value*) VECTOR_GET(v, 0))).val);


    // // for (i = 0; i < VECTOR_TOTAL(v); i++) {
    // //     switch((*((value*) VECTOR_GET(v, i))).type) {
    // //         case INT: printf("%d ", (*((value*) VECTOR_GET(v, i))).val.i);
    // //         case CHAR: printf("%c ", (*((value*) VECTOR_GET(v, i))).val.c);
    // //         case BOOL: break;
    // //         case FLOAT: break;
    // //         case DOUBLE: break;
    // //         case STR: printf("%s ", (*((value*) VECTOR_GET(v, i))).val.s);
    // //         break;
    // //     }
    // // }
    // printf("\n");

    // // // VECTOR_DELETE(v, 3);
    // // // VECTOR_DELETE(v, 2);
    // VECTOR_DELETE(v, 0);
    // VECTOR_DELETE(v, 0);
    // VECTOR_DELETE(v, 0);
    // VECTOR_DELETE(v, 0);

    // // // VECTOR_SET(v, 0, "Hello");
    // // // VECTOR_ADD(v, "World");

    // // for (i = 0; i < VECTOR_TOTAL(v); i++)
    // //     printf("%d ", VECTOR_GET(v, int, i));
    // // printf("\n");

    // VECTOR_FREE(v);

    float inputs[4] = {1, 2, 3, 2.5};

    float weights1[4] = {0.2, 0.8, -0.5, 1.0};
    float weights2[4] = {0.5, -0.91, 0.26, -0.5};
    float weights3[4] = {-0.26, -0.27, 0.17, 0.87};

    float bias1 = 2.0;
    float bias2 = 3.0;
    float bias3 = 0.5;

    float output[3] = {
        inputs[0]*weights1[0] + inputs[1]*weights1[1] + inputs[2]*weights1[2] + inputs[3]*weights1[3] + bias1,
        inputs[0]*weights2[0] + inputs[1]*weights2[1] + inputs[2]*weights2[2] + inputs[3]*weights2[3] + bias2,
        inputs[0]*weights3[0] + inputs[1]*weights3[1] + inputs[2]*weights3[2] + inputs[3]*weights3[3] + bias3,
    };
    printf("%f, %f, %f\n", output[0], output[1], output[2]);

    return 0;
}

int main() {
    neuron();
    return 0;
}
