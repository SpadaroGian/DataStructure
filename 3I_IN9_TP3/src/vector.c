#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

// Alloue un vecteur avec n éléments initialisés à 0.0
p_s_vector vector_alloc(size_t n) {
    p_s_vector p_vector = (p_s_vector)malloc(sizeof(s_vector));
    
    if (p_vector != NULL) {
        p_vector->n = n;
        p_vector->data = (double*)malloc(n * sizeof(double));
        

        for (size_t i = 0; i < p_vector->n; i++) {
            p_vector->data[i] = 0.0;
        }
    }
    
    return p_vector;
}

// Libère la mémoire du vecteur
void vector_free(p_s_vector p_vector) {
    if (p_vector != NULL) {
        free(p_vector->data);
        p_vector->data = NULL;
        free(p_vector);
        p_vector = NULL;
    }
}

// Modifie la valeur à l'index i du vecteur
void vector_set(p_s_vector p_vector, size_t i, double v) {
    if (p_vector != NULL && i < p_vector->n) {
        p_vector->data[i] = v;
    }
}

// Récupère la valeur à l'index i du vecteur
void vector_get(p_s_vector p_vector, size_t i, double *pv) {
    if (p_vector != NULL && pv != NULL && i < p_vector->n) {
        *pv = p_vector->data[i];
    }
}

// Insère une valeur à l'index i du vecteur
void vector_insert(p_s_vector p_vector, size_t i, double v) {
    if (p_vector == NULL) {
        printf("Le pointeur est NULL.\n");
        return;
    }

    size_t orSize = p_vector->n;

    double *newData = (double*)realloc(p_vector->data, (orSize + 1) * sizeof(double));

    p_vector->data = newData;
    p_vector->n = orSize + 1;

    for (size_t j = orSize; j > i; --j) {
        p_vector->data[j] = p_vector->data[j - 1];
    }

    p_vector->data[i] = v;
}

// Supprime la valeur à l'index i du vecteur
void vector_erase(p_s_vector p_vector, size_t i) {
    if (p_vector == NULL) {
        printf("Le pointeur est NULL.\n");
        return;
    }

    size_t orSize = p_vector->n;


    for (size_t j = i; j < orSize - 1; j++) {
        p_vector->data[j] = p_vector->data[j + 1];
    }

    p_vector->n--;

    double *newData = (double*)realloc(p_vector->data, p_vector->n * sizeof(double));

    p_vector->data = newData;
}

// Ajoute une valeur à la fin du vecteur
void vector_push_back(p_s_vector p_vector, double v) {
    if (p_vector == NULL) {
        printf("Le pointeur fourni est NULL.\n");
        return;
    }

    double *newData = (double*)realloc(p_vector->data, (p_vector->n + 1) * sizeof(double));

    p_vector->data = newData;
    p_vector->data[p_vector->n] = v;
    p_vector->n++;
}

// Supprime la dernière valeur du vecteur
void vector_pop_back(p_s_vector p_vector) {
    if (p_vector == NULL) {
        printf("Le pointeur fourni est NULL.\n");
        return;
    }


    p_vector->n--;

    double *newData = (double*)realloc(p_vector->data, p_vector->n * sizeof(double));

    p_vector->data = newData;
}

// Supprime tous les éléments du vecteur
void vector_clear(p_s_vector p_vector) {
    if (p_vector == NULL) {
        printf("Le pointeur est NULL.\n");
        return;
    }

    free(p_vector->data);
    p_vector->data = NULL;
    p_vector->n = 0;
}

// Vérifie si le vecteur est vide
int vector_empty(p_s_vector p_vector) {
    if (p_vector == NULL) {
        printf("Le pointeur est NULL.\n");
        return 1;
    }

    return p_vector->n == 0;
}

// Retourne la taille du vecteur
size_t vector_size(p_s_vector p_vector) {
    if (p_vector == NULL) {
        printf("Le pointeur est NULL.\n");
        return 0;
    }

    return p_vector->n;
}
