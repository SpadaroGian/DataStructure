#include <stdio.h>
#include "vector.h"

void test_vector_alloc_free() {
    size_t n = 5;
    p_s_vector p_vector = vector_alloc(n);
    if (p_vector != NULL) {
        printf("Vector allocated successfully with size: %zu\n", vector_size(p_vector));
        vector_free(p_vector);
        printf("Vector freed successfully\n");
    }
}

void test_vector_set_get() {
    size_t n = 5;
    p_s_vector p_vector = vector_alloc(n);
    if (p_vector != NULL) {
        vector_set(p_vector, 2, 3.14);
        double v;
        vector_get(p_vector, 2, &v);
        printf("Value at index 2: %f\n", v);
        vector_free(p_vector);
    }
}

void test_vector_insert_erase() {
    size_t n = 5;
    p_s_vector p_vector = vector_alloc(n);
    if (p_vector != NULL) {
        vector_insert(p_vector, 2, 3.14);
        printf("Inserted value at index 2: %f\n", p_vector->data[2]);
        vector_erase(p_vector, 2);
        printf("Value at index 2 after erase: %f\n", p_vector->data[2]);
        vector_free(p_vector);
    } 
}

void test_vector_push_pop() {
    p_s_vector p_vector = vector_alloc(0);
    if (p_vector != NULL) {
        vector_push_back(p_vector, 3.14);
        printf("Pushed value to vector: %f\n", p_vector->data[0]);
        vector_pop_back(p_vector);
        printf("Vector size after pop: %zu\n", vector_size(p_vector));
        vector_free(p_vector);
    }
}

void test_vector_clear_empty() {
    size_t n = 5;
    p_s_vector p_vector = vector_alloc(n);
    if (p_vector != NULL) {
        vector_clear(p_vector);
        printf("Vector size after clear: %zu\n", vector_size(p_vector));
        printf("Vector empty status: %d\n", vector_empty(p_vector));
        vector_free(p_vector);
    }
}

void test_vector_null_values() {
    printf("Testing vector functions with NULL values:\n");
    p_s_vector null_vector = NULL;
    printf("Attempting vector_alloc(NULL): ");
    p_s_vector p_vector_alloc = vector_alloc(0);

    printf("Attempting vector_free(NULL): ");
    vector_free(null_vector);
    printf("Passed\n");

    printf("Attempting vector_set(NULL, ...): ");
    vector_set(null_vector, 0, 3.14);
    printf("Passed\n");

    double v;
    printf("Attempting vector_get(NULL, ...): ");
    vector_get(null_vector, 0, &v);
    printf("Passed\n");

    printf("Attempting vector_insert(NULL, ...): ");
    vector_insert(null_vector, 0, 3.14);
    printf("Passed\n");

    printf("Attempting vector_erase(NULL, ...): ");
    vector_erase(null_vector, 0);
    printf("Passed\n");

    printf("Attempting vector_push_back(NULL, ...): ");
    vector_push_back(null_vector, 3.14);
    printf("Passed\n");

    printf("Attempting vector_pop_back(NULL): ");
    vector_pop_back(null_vector);
    printf("Passed\n");

    printf("Attempting vector_clear(NULL): ");
    vector_clear(null_vector);
    printf("Passed\n");

    printf("Attempting vector_empty(NULL): ");
    int is_empty = vector_empty(null_vector);
    if (is_empty) {
        printf("Passed\n");
    }

    printf("Attempting vector_size(NULL): ");
    size_t size = vector_size(null_vector);
    if (size == 0) {
        printf("Passed\n");
    }
}

void test_failed_allocation() {
    printf("Testing failed allocation:\n");
    printf("Attempting vector_alloc(0): ");
    p_s_vector p_vector_alloc = vector_alloc(0);
    if (p_vector_alloc != NULL) {
        printf("Vector allocated successfully\n");
        vector_free(p_vector_alloc);
    }
}

int main() {
    printf("Testing vector_alloc and vector_free:\n");
    test_vector_alloc_free();

    printf("\nTesting vector_set and vector_get:\n");
    test_vector_set_get();

    printf("\nTesting vector_insert and vector_erase:\n");
    test_vector_insert_erase();

    printf("\nTesting vector_push_back and vector_pop_back:\n");
    test_vector_push_pop();

    printf("\nTesting vector_clear and vector_empty:\n");
    test_vector_clear_empty();

    printf("\nTesting vector functions with NULL values:\n");
    test_vector_null_values();

    printf("\nTesting failed allocation:\n");
    test_failed_allocation();

    return 0;
}

