#include <stdio.h>
#include <stdlib.h>

#include "vectord.h"
#include "utilities.h"

void vector_init(vector *v) {
    v->capacity = VECTOR_INIT_CAPACITY;
    v->total = 0;
    v->items = malloc(sizeof(double) * v->capacity);
}

int vector_total(vector *v) {
    return v->total;
}

void vector_print(vector *v) {
    printf("v->total: %d\n", v->total);
    for(int i = 0; i < v->total; i++) {
        printf("%f, ", (double) v->items[i]);
    }
    printf("\n");
}

void vector_resize(vector *v, int capacity) {

    double *items = realloc(v->items, sizeof(double) * capacity);

    if (items) {
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
    if (index >= 0 && index < v->total) {
        v->items[index] = item;
    }
    else {
        printf("%sWarning: index %d cannot be set%s\n", YELLOW, index, RESET);
    }
}

double vector_get(vector *v, int index) {
    if (index >= 0 && index < v->total) {
        return v->items[index];
    }
    printf("%sWarning: index %d is empty%s\n", YELLOW, index, RESET);
    return ERROR_CODE;
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