#include <stdio.h>
#include <stdlib.h>

#include "generic_vector.h"

void vector_init(vector *v) {
    v->capacity = VECTOR_INIT_CAPACITY;
    v->total = 0;
    v->items = malloc(sizeof(void *) * v->capacity);
    v->types = malloc(sizeof(enum type) * v->capacity);
}

int vector_total(vector *v) {
    return v->total;
}

int vector_print(vector *v) {
    printf("v->total: %d\n", v->total);
    for(int i = 0; i < v->total; i++) {
        
        switch(v->types[i]) {
            case INT:       printf("%d, ", (int) v->items[i]);   break;
            case DOUBLE:    printf("%f, ", (double) strtod(v->items[i], NULL)); break;  // will need to strtod later
            case CHAR:      printf("%c, ", (char) v->items[i]);  break;
            case STR:       printf("%s, ", (char*) v->items[i]); break;
            case NONE:      break;
            default:        break;
        }
        
    }
    printf("\n");
    // printf("here");
    return 1;
}

static void vector_resize(vector *v, int capacity) {
    #ifdef DEBUG_ON
    printf("vector_resize: %d to %d\n", v->capacity, capacity);
    #endif

    void **items = realloc(v->items, sizeof(void *) * capacity);
    void *types = realloc(v->types, sizeof(enum type) * capacity);

    if (items) {
        v->items = items;
        v->types = types;
        v->capacity = capacity;
    }
}

void vector_add(vector *v, void *item, enum type type) {
    if (v->capacity == v->total)
        vector_resize(v, v->capacity * 2);

    v->items[v->total] = item;
    v->types[v->total] = type;
    v->total++;
}

void vector_add_double(vector *v, double item) {
    if (v->capacity == v->total)
        vector_resize(v, v->capacity * 2);

    char *d_char = malloc(sizeof(char) * 50);
    snprintf(d_char, 50, "%f", item);
    // printf("d_char: %s\n", d_char);


    // printf("total: %d\n", v->total);
    v->items[v->total] = d_char;
    v->types[v->total] = DOUBLE;
    v->total++;
    // printf("total: %d\n", v->total);
}

void vector_set(vector *v, int index, void *item, enum type type) {
    if (index >= 0 && index < v->total) {
        v->items[index] = item;
        v->types[index] = type;
    }
}

void vector_set_double(vector *v, int index, double item) {
    if (index >= 0 && index < v->total) {
        char *d_char = malloc(sizeof(char) * 50);
        snprintf(d_char, 50, "%f", item);
        printf("d_char: %s\n", d_char);

        v->items[index] = d_char;
    }
}

void *vector_get(vector *v, int index) {
    if (index >= 0 && index < v->total) {
        return v->items[index];
    }
    return NULL;
}

void vector_delete(vector *v, int index) {
    if (index < 0 || index >= v->total) {
        return;
    }

    v->items[index] = NULL;
    v->types[index] = NONE;

    for (int i = index; i < v->total - 1; i++) {
        v->items[i] = v->items[i + 1];
        v->types[i] = v->types[i + 1];
        v->items[i + 1] = NULL;
        v->types[i + 1] = NONE;
    }

    v->total--;

    if (v->total > 0 && v->total == v->capacity / 4) {
        vector_resize(v, v->capacity / 2);
    }
}

void vector_free(vector *v) {
    free(v->items);
}