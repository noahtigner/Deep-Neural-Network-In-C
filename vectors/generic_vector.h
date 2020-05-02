#ifndef VECTOR_H
#define VECTOR_H

#define VECTOR_INIT_CAPACITY 4

#define VECTOR_INIT(vec) vector vec; vector_init(&vec)
#define VECTOR_TOTAL(vec) vector_total(&vec)
#define VECTOR_PRINT(vec) vector_print(&vec)
#define VECTOR_ADD(vec, item, type) vector_add(&vec, (void *) item, type)
#define VECTOR_ADD_DOUBLE(vec, item) vector_add_double(&vec, (double) item)
#define VECTOR_SET(vec, id, item, type) vector_set(&vec, id, (void *) item, type)
#define VECTOR_SET_DOUBLE(vec, id, item) vector_set_double(&vec, id, (double) item)
#define VECTOR_GET(vec, id)  vector_get(&vec, id)
#define VECTOR_DELETE(vec, id) vector_delete(&vec, id)
#define VECTOR_FREE(vec) vector_free(&vec)

typedef struct vector {
    void **items;
    enum type *types;
    int capacity;
    int total;
} vector;

enum type {
    INT,
    // FLOAT,
    DOUBLE,
    CHAR,
    STR,
    NONE
};

void vector_init(vector *);
int vector_total(vector *);
int vector_print(vector *);
static void vector_resize(vector *, int);
void vector_add(vector *, void *, enum type);
void vector_add_double(vector *, double);
void vector_set(vector *, int, void *, enum type);
void vector_set_double(vector *, int, double);
void *vector_get(vector *, int);
void vector_delete(vector *, int);
void vector_free(vector *);


#endif