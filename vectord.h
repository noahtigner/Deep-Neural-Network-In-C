#ifndef VECTOR_H
#define VECTOR_H

#define ERROR_CODE -999,999,999
#define VECTOR_INIT_CAPACITY 4

#define VECTOR_INIT(vec) vector vec; vector_init(&vec)
#define VECTOR_TOTAL(vec) vector_total(&vec)
#define VECTOR_PRINT(vec) vector_print(&vec)
#define VECTOR_ADD(vec, item) vector_add(&vec, (double) item)
#define VECTOR_ADD_MANY(vec, items) vector_add_many(&vec, items, sizeof(items)/sizeof(double))
#define VECTOR_SET(vec, id, item) vector_set(&vec, id, (double) item)
#define VECTOR_GET(vec, id)  vector_get(&vec, id)
#define VECTOR_DELETE(vec, id) vector_delete(&vec, id)
#define VECTOR_FREE(vec) vector_free(&vec)

typedef struct vector {
    double *items;
    int capacity;
    int total;
} vector;

void vector_init(vector *);
int vector_total(vector *);
void vector_print(vector *);
void vector_resize(vector *, int);
void vector_add(vector *, double);
void vector_add_many(vector *, double[], int);
void vector_set(vector *, int, double);
double vector_get(vector *, int);
void vector_delete(vector *, int);
void vector_free(vector *);

#endif