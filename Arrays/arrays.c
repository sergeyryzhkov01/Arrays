#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <float.h> // Для DBL_MAX
#include "arrays.h"

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

void copy_int_array(int* src, int* dest, int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
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
    *sizeD = n + m + 1;
    
    double* D = (double*)malloc(*sizeD * sizeof(double));
    if (D == NULL) return NULL;

    int current = 0;

    // 1. Копируем A
    for (int i = 0; i < n; i++) D[current++] = A[i];

    // 2. Копируем B в обратном порядке
    for (int i = m - 1; i >= 0; i--) D[current++] = B[i];

    // 3. Сумма C
    double sumC = 0.0;
    for (int i = 0; i < l; i++) sumC += C[i];
    D[current] = sumC;

    return D;
}


/* === Реализация Лабораторной работы 17 === */

int* full_array(int* ptrarr, int n) {
    for (int i = 0; i < n; i++) {
        ptrarr[i] = rand() % 1001; // Числа от 0 до 1000
    }
    return ptrarr;
}

int put_array(int* ptrarr, int n) {
    // Выводим только первые 20 элементов, чтобы не засорять консоль
    int limit = (n > 20) ? 20 : n;
    printf("[ ");
    for (int i = 0; i < limit; i++) {
        printf("%d ", ptrarr[i]);
    }
    if (n > limit) printf("... еще %d эл. ", n - limit);
    printf("]\n");
    return 0;
}

// а) Пузырьковая сортировка
void sort_bubble(int* ptrarr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ptrarr[j] > ptrarr[j + 1]) {
                int temp = ptrarr[j];
                ptrarr[j] = ptrarr[j + 1];
                ptrarr[j + 1] = temp;
            }
        }
    }
}

// б) Шейкерная сортировка
void sort_kokteil(int* ptrarr, int n) {
    int left = 0;
    int right = n - 1;
    int flag = 1;
    while (left < right && flag > 0) {
        flag = 0;
        for (int i = left; i < right; i++) {
            if (ptrarr[i] > ptrarr[i + 1]) {
                int temp = ptrarr[i];
                ptrarr[i] = ptrarr[i + 1];
                ptrarr[i + 1] = temp;
                flag = 1;
            }
        }
        right--;
        for (int i = right; i > left; i--) {
            if (ptrarr[i - 1] > ptrarr[i]) {
                int temp = ptrarr[i];
                ptrarr[i] = ptrarr[i - 1];
                ptrarr[i - 1] = temp;
                flag = 1;
            }
        }
        left++;
    }
}

// в) Сортировка простым выбором
void sort_select(int* ptrarr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (ptrarr[j] < ptrarr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            int temp = ptrarr[i];
            ptrarr[i] = ptrarr[min_idx];
            ptrarr[min_idx] = temp;
        }
    }
}

// г) Сортировка вставками
void sort_insert(int* ptrarr, int n) {
    for (int i = 1; i < n; i++) {
        int key = ptrarr[i];
        int j = i - 1;
        while (j >= 0 && ptrarr[j] > key) {
            ptrarr[j + 1] = ptrarr[j];
            j = j - 1;
        }
        ptrarr[j + 1] = key;
    }
}
