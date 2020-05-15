#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "vector.h"
#include "matrix.h"
#include "utilities.h"



void matrix_init(matrix *m) {
    m->capacity = VECTOR_INIT_CAPACITY;
    m->total = 0;
    m->vectors = malloc(sizeof(vector) * m->capacity);
}

void matrix_fill_zeros(matrix *m, int rows, int cols) {
    
    for(int i = 0; i < rows; i++) {
        VECTOR_INIT(temp);
        for(int j = 0; j < cols; j++) {
            VECTOR_ADD(temp, 0.0);
        }
        matrix_add(m, temp);
    }
}

void matrix_fill_rands(matrix *m, int rows, int cols) {
    
    for(int i = 0; i < rows; i++) {
        VECTOR_INIT(temp);
        for(int j = 0; j < cols; j++) {
            double random = (double) rand() / RAND_MAX * 2.0 - 1.0;
            VECTOR_ADD(temp, random);
        }
        matrix_add(m, temp);
    }
}

int matrix_total(matrix *m) {
    return m->total;
}

void matrix_print(matrix *m) {
    // TODO:
    printf("Matrix Dimensions: %dx%d\n", m->total, VECTOR_TOTAL(m->vectors[0]));
    for(int i = 0; i < m->total; i++) {
    //     printf("%f, ", (vector) m->vectors[i]);
        VECTOR_PRINT(m->vectors[i]);
    }
    printf("\n");
}

void matrix_resize(matrix *m, int capacity) {
    vector *vectors = realloc(m->vectors, sizeof(vector) * capacity);

    if(vectors) {
        m->vectors = vectors;
        m->capacity = capacity;
    }
}

void matrix_add(matrix *m, vector v) {
    if (m->capacity == m->total) {
        matrix_resize(m, m->capacity * 2);
    }

    m->vectors[m->total] = v;
    m->total++;
}

void matrix_add_many(matrix *m, vector vectors[], int length) {
    for(int i = 0; i < length; i++) {
        if (m->capacity == m->total)
            matrix_resize(m, m->capacity * 2);

        m->vectors[m->total] = vectors[i];
        m->total++;
    }
}

void matrix_set(matrix *m, int index, vector v) {
    if (index >= 0 && index < m->total) {
        m->vectors[index] = v;
    }
    else {
        printf("%sMatrix Warning: index %d cannot be set%s\n", YELLOW, index, RESET);
    }
}

vector matrix_get(matrix *m, int index) {
    if (index >= 0 && index < m->total) {
        return m->vectors[index];
    }
    printf("%sMatrix Warning: index %d is empty%s\n", YELLOW, index, RESET);
    return nullvec;
}

void matrix_delete(matrix *m, int index) {
    if (index < 0 || index >= m->total) {
        return;
    }

    // m->vectors[index] = nullvec;
    VECTOR_FREE(m->vectors[index]);

    for (int i = index; i < m->total - 1; i++) {
        m->vectors[i] = m->vectors[i + 1];
        // m->vectors[i + 1] = nullvec;
        VECTOR_FREE(m->vectors[index+1]);
    }

    m->total--;

    if (m->total > 0 && m->total == m->capacity / 4) {
        matrix_resize(m, m->capacity / 2);
    }
}
void matrix_free(matrix *m) {
    // free(m->vectors);
    for (int i = 0; i < m->total; i++) {
        // m->vectors[i] = m->vectors[i + 1];
        // m->vectors[i + 1] = nullvec;
        VECTOR_FREE(m->vectors[i]);
    }
}

void matrix_transpose(matrix *m, matrix *t) {
    int r = matrix_total(m);
    int c = VECTOR_TOTAL(m->vectors[0]);

    for(int i = 0; i < c; i++) {
        VECTOR_INIT(temp);
        for(int j =0; j < r; j++) {
            VECTOR_ADD(temp, VECTOR_GET(m->vectors[j], i));
        }
        matrix_add(t, temp);
    }
}

matrix matrix_multiplication(matrix *m1, matrix *m2) {

    // TODO: error checking
    int r1 = matrix_total(m1);
    int c1 = VECTOR_TOTAL(m1->vectors[0]);
    int r2 = VECTOR_TOTAL(m2->vectors[0]);
    int c2 = matrix_total(m2);
    // Note: r2 and c2 are swapped here to skip transposition

    printf("MATRIX MULT: %dx%d * %dx%d => %dx%d\n", r1, c1, r2, c2, r1, c2);

    MATRIX_INIT(m3);

    for(int i = 0; i < r1; i++) {
        VECTOR_INIT(v);
        for(int j = 0; j < c2; j++) {
    
            double dp = VECTOR_DOT_PRODUCT(m1->vectors[i], m2->vectors[j]);
            // printf("\ti: %d\tj: %d\tdp: %f\n", i, j, dp);
            VECTOR_ADD(v, dp);

        }
        MATRIX_ADD(m3, v);
    }
 
    return m3;
}

void matrix_scale_by_vector(matrix *m, vector v) {
    int length  = VECTOR_TOTAL(m->vectors[0]);
    if(length != VECTOR_TOTAL(v)) {
        printf("%sWarning: matrix dimension 2 does not match vector length%s\n", YELLOW, RESET);
        return;
    }
    for(int r = 0; r < m->total; r++) {
        for(int c = 0; c < length; c++) {
            double init = VECTOR_GET(m->vectors[r], c);
            double bias = VECTOR_GET(v, c);
            VECTOR_SET(m->vectors[r], c, init + bias);
        }
    }
}

void matrix_addition(matrix *m1, matrix *m2) {
    int m2dim1  = matrix_total(m2);
    if(m2dim1 == 1) {

        for(int r = 0; r < m1->total; r++) {
            for(int c = 0; c < m2->total; c++) {
                double init = VECTOR_GET(m1->vectors[r], c);
                double bias = VECTOR_GET(m2->vectors[0], c);
                VECTOR_SET(m1->vectors[r], c, init + bias);
            }
        }

    }
    else {
        printf("DIM NOT 1, IDK WHAT TO DO\n");
    }
}

void matrix_activation_step(matrix *m) {
    int r = m->total;
    int c = VECTOR_TOTAL(m->vectors[0]);
    
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            double d = VECTOR_GET(m->vectors[i], j);
            if(d > 0.0) {
                d = 1.0;
            }
            else {
                d = 0.0;
            }
            VECTOR_SET(m->vectors[i], j, d);
        }
    }
}

void matrix_activation_sigmoid(matrix *m) {
    // Uses the Fast Sigmoid Function: f(x) = x / (1 + (abs(x)))
    int r = m->total;
    int c = VECTOR_TOTAL(m->vectors[0]);
    
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            double d = VECTOR_GET(m->vectors[i], j);
            d = d / (1 + (fabs(d)));
            VECTOR_SET(m->vectors[i], j, d);
        }
    }
}

void matrix_activation_relu(matrix *m) {
    // Uses the Fast Sigmoid Function: f(x) = x / (1 + (abs(x)))
    int r = m->total;
    int c = VECTOR_TOTAL(m->vectors[0]);
    
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            double d = VECTOR_GET(m->vectors[i], j);
            if(d <= 0.0) {
                d = 0.0;
            }
            VECTOR_SET(m->vectors[i], j, d);
        }
    }
}
