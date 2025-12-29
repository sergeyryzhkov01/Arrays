#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <float.h> // Для DBL_MAX
#include "array.h"

/* === Реализация вспомогательных функций === */

double random_double(double min, double max) {
    return min + ((double)rand() / RAND_MAX) * (max - min);
}

void print_int_array(const char* name, int* arr, int n) {
    printf("%s: [ ", name);
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("]\n");
}

void print_double_array(const char* name, double* arr, int n) {
    printf("%s: [ ", name);
    for (int i = 0; i < n; i++) printf("%.2f ", arr[i]);
    printf("]\n");
}


/* === Реализация Лабораторной работы 11 === */

int count_before_min(int* arr, int n) {
    if (n <= 0) return 0;

    int min_val = arr[0];
    int min_idx = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i] < min_val) {
            min_val = arr[i];
            min_idx = i;
        }
    }
    // Индекс элемента равен количеству элементов, стоящих перед ним
    return min_idx;
}


/* === Реализация Лабораторной работы 14 === */

void fill_random_array(double* arr, int n, double min, double max) {
    for (int i = 0; i < n; i++) {
        arr[i] = random_double(min, max);
    }
}

double find_min_in_interval(double* arr, int n, double A, double B, int* isFound) {
    double minVal = DBL_MAX;
    *isFound = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > A && arr[i] < B) {
            if (*isFound == 0 || arr[i] < minVal) {
                minVal = arr[i];
                *isFound = 1;
            }
        }
    }
    return minVal;
}


/* === Реализация Лабораторной работы 16 === */

double* create_merged_array(double* A, int n, double* B, int m, double* C, int l, int* sizeD) {
    *sizeD = n + m + 1; // Размер: A + B + 1 элемент (сумма C)

    double* D = (double*)malloc(*sizeD * sizeof(double));
    if (D == NULL) return NULL;

    int current = 0;

    // 1. Копируем A
    for (int i = 0; i < n; i++) {
        D[current++] = A[i];
    }

    // 2. Копируем B в обратном порядке
    for (int i = m - 1; i >= 0; i--) {
        D[current++] = B[i];
    }

    // 3. Сумма элементов C
    double sumC = 0.0;
    for (int i = 0; i < l; i++) {
        sumC += C[i];
    }
    D[current] = sumC;

    return D;
}
