#include "vector.h"

#ifndef MATRIX
#define MATRIX

#define MATRIX_INIT_CAPACITY 4

#define MATRIX_INIT(mat) matrix mat; matrix_init(&mat)
#define MATRIX_INIT_ZEROS(mat, rows, cols) matrix mat; matrix_init(&mat); matrix_fill_zeros(&mat, (int) rows, (int) cols)
#define MATRIX_INIT_RANDS(mat, rows, cols) matrix mat; matrix_init(&mat); matrix_fill_rands(&mat, (int) rows, (int) cols)
#define MATRIX_TOTAL(mat) matrix_total(&mat)
#define MATRIX_PRINT(mat) matrix_print(&mat)
#define MATRIX_ADD(mat, vec) matrix_add(&mat, (vector) vec)
#define MATRIX_ADD_MANY(mat, vectors) matrix_add_many(&mat, vectors, sizeof(vectors)/sizeof(vector))
#define MATRIX_SET(mat, id, vec) matrix_set(&mat, id, (vector) vec)
#define MATRIX_GET(mat, id)  matrix_get(&mat, id)
#define MATRIX_TRANSPOSE(mat, trans) matrix trans; matrix_init(&trans); matrix_transpose(&mat, &trans)
#define MATRIX_MULTIPLICATION(m1, m2) matrix_multiplication(&m1, &m2)
#define MATRIX_SCALE_BY_VECTOR(mat, vec) matrix_scale_by_vector(&mat, (vector) vec)
#define MATRIX_ADDITION(m1, m2) matrix_addition(&m1, &m2)
#define MATRIX_ACTIVATION_STEP(mat) matrix_activation_step(&mat)
#define MATRIX_ACTIVATION_SIGMOID(mat) matrix_activation_sigmoid(&mat)
#define MATRIX_ACTIVATION_RELU(mat) matrix_activation_relu(&mat)
#define MATRIX_DELETE(mat, id) matrix_delete(&mat, id)
#define MATRIX_FREE(mat) matrix_free(&mat)

typedef struct matrix {
    vector *vectors;
    int capacity;
    int total;
} matrix;

void matrix_init(matrix *);
void matrix_fill_zeros(matrix *, int, int);
void matrix_fill_rands(matrix *, int, int);
int matrix_total(matrix *);
void matrix_print(matrix *);
void matrix_resize(matrix *, int);
void matrix_add(matrix *, vector);
void matrix_add_many(matrix *, vector[], int);
void matrix_set(matrix *, int, vector);
vector matrix_get(matrix *, int);
void matrix_transpose(matrix *, matrix *);
matrix matrix_multiplication(matrix *, matrix *);
void matrix_scale_by_vector(matrix *, vector);
void matrix_addition(matrix *, matrix *);
void matrix_activation_step(matrix *);
void matrix_activation_sigmoid(matrix *);
void matrix_activation_relu(matrix *);
void matrix_delete(matrix *, int);
void matrix_free(matrix *);

#endif