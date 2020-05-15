#include <stdio.h>
#include <stdlib.h>

#include "vector.h"
#include "utilities.h"

void vector_init(vector *v) {
    v->capacity = VECTOR_INIT_CAPACITY;
    v->total = 0;
    v->items = malloc(sizeof(double) * v->capacity);
}

void vector_fill_zeros(vector *v, int n_neurons) {
    for(int i = 0; i < n_neurons; i++) {
        vector_add(v, 0.0);
    }
}

int vector_total(vector *v) {
    return v->total;
}

void vector_print(vector *v) {
    for(int i = 0; i < v->total; i++) {
        printf("%8.4lf\t", (double) v->items[i]);
    }
    printf("\n");
}

void vector_resize(vector *v, int capacity) {
    double *items = realloc(v->items, sizeof(double) * capacity);

    if(items) {
        v->items = items;
        v->capacity = capacity;
    }
}

void vector_add(vector *v, double item) {
    if (v->capacity == v->total)
        vector_resize(v, v->capacity * 2);

    v->items[v->total] = item;
    v->total++;
}

void vector_add_many(vector *v, double items[], int length) {
    for(int i = 0; i < length; i++) {
        if (v->capacity == v->total)
            vector_resize(v, v->capacity * 2);

        v->items[v->total] = items[i];
        v->total++;
    }
}

void vector_set(vector *v, int index, double item) {
    // printf("SET index: %d, double: %f\n", index, item);
    if (index >= 0 && index < v->total) {
        v->items[index] = item;
    }
    else {
        printf("%sWarning: index %d cannot be set%s\n", YELLOW, index, RESET);
    }
}

double vector_get(vector *v, int index) {
    // printf("GET index: %d\n", index);
    if (index >= 0 && index < v->total) {
        return v->items[index];
    }
    printf("%sWarning: index %d is empty%s\n", YELLOW, index, RESET);
    return ERROR_CODE;
}

double vector_dot_product(vector v1, vector v2) {
    int length1 = VECTOR_TOTAL(v1);
    int length2 = VECTOR_TOTAL(v2);
    if(length1 != length2) {
        printf("%sWarning: vector lengths don't match (%d != %d)%s\n", YELLOW, length1, length2, RESET);
        return ERROR_CODE;
    }

    double dp = 0.0;
    for(int i = 0; i < length2; i++) {
        dp += VECTOR_GET(v1, i) * VECTOR_GET(v2, i);
    }
    return dp;
}

void vector_delete(vector *v, int index) {
    if (index < 0 || index >= v->total) {
        return;
    }

    v->items[index] = 0;

    for (int i = index; i < v->total - 1; i++) {
        v->items[i] = v->items[i + 1];
        v->items[i + 1] = 0;
    }

    v->total--;

    if (v->total > 0 && v->total == v->capacity / 4) {
        vector_resize(v, v->capacity / 2);
    }
}

void vector_free(vector *v) {
    free(v->items);
}