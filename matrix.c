#include <stdio.h>
#include <stdlib.h>

#include "vector.h"
#include "matrix.h"
#include "utilities.h"

void matrix_init(matrix *m) {
    m->capacity = VECTOR_INIT_CAPACITY;
    m->total = 0;
    m->vectors = malloc(sizeof(vector) * m->capacity);
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
    if (m->capacity == m->total)
        matrix_resize(m, m->capacity * 2);

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
        printf("%sWarning: index %d cannot be set%s\n", YELLOW, index, RESET);
    }
}

vector matrix_get(matrix *m, int index) {
    if (index >= 0 && index < m->total) {
        return m->vectors[index];
    }
    printf("%sWarning: index %d is empty%s\n", YELLOW, index, RESET);
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
    // VECTOR_PRINT(m1->vectors[0]);
    // VECTOR_PRINT(m2->vectors[0]);
    // double d = VECTOR_DOT_PRODUCT(MATRIX_GET(m1, 0), MATRIX_GET(m2, 0));
    // printf("m1xm2: %f\n", d);
    // TODO: error checking
    int r = matrix_total(m1);
    int c = VECTOR_TOTAL(m1->vectors[0]);

    printf("r*c: %d*%d\n", r, c);

    MATRIX_INIT(m3);

    for(int i = 0; i < r; i++) {
        VECTOR_INIT(v);
        for(int j = 0; j < r; j++) {
            VECTOR_PRINT(m1->vectors[i]);
            printf("x\n");
            VECTOR_PRINT(m2->vectors[j]);
            double dp = VECTOR_DOT_PRODUCT(m1->vectors[i], m2->vectors[j]);
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
