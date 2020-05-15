#ifndef VECTOR
#define VECTOR

#define ERROR_CODE -999.00
#define VECTOR_INIT_CAPACITY 4

#define VECTOR_INIT(vec) vector vec; vector_init(&vec)
#define VECTOR_INIT_ZEROS(vec, n_neurons) vector vec; vector_init(&vec); vector_fill_zeros(&vec, n_neurons)
#define VECTOR_TOTAL(vec) vector_total(&vec)
#define VECTOR_PRINT(vec) vector_print(&vec)
#define VECTOR_ADD(vec, item) vector_add(&vec, (double) item)
#define VECTOR_ADD_MANY(vec, items) vector_add_many(&vec, items, sizeof(items)/sizeof(double))
#define VECTOR_SET(vec, id, item) vector_set(&vec, id, (double) item)
#define VECTOR_GET(vec, id)  vector_get(&vec, id)
#define VECTOR_DOT_PRODUCT(v1, v2) vector_dot_product(v1, v2)
#define VECTOR_DELETE(vec, id) vector_delete(&vec, id)
#define VECTOR_FREE(vec) vector_free(&vec)

typedef struct vector {
    double *items;
    int capacity;
    int total;
} vector;

// double nulldoub[0] = {}; 
vector nullvec;

void vector_init(vector *);
void vector_fill_zeros(vector *, int);
int vector_total(vector *);
void vector_print(vector *);
void vector_resize(vector *, int);
void vector_add(vector *, double);
void vector_add_many(vector *, double[], int);
void vector_set(vector *, int, double);
double vector_get(vector *, int);
double vector_dot_product(vector, vector);
void vector_delete(vector *, int);
void vector_free(vector *);

#endif