#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "array.h" // Подключаем наш заголовочный файл

// Прототипы функций-сценариев (Task runners)
void run_task11();
void run_task14();
void run_task16();

int main() {
    setlocale(LC_ALL, "Rus");
    srand(time(NULL)); // Инициализация генератора случайных чисел один раз

    int choice;
    do {
        printf("\n=== МЕНЮ ЛАБОРАТОРНЫХ РАБОТ ===\n");
        printf("1. Лабораторная №11 (Кол-во элементов до минимума)\n");
        printf("2. Лабораторная №14 (Минимум в интервале)\n");
        printf("3. Лабораторная №16 (Объединение массивов)\n");
        printf("0. Выход\n");
        printf("Ваш выбор: ");

        if (scanf("%d", &choice) != 1) {
            // Очистка буфера при вводе буквы вместо цифры
            while (getchar() != '\n');
            choice = -1;
        }

        switch (choice) {
        case 1: run_task11(); break;
        case 2: run_task14(); break;
        case 3: run_task16(); break;
        case 0: printf("Выход из программы.\n"); break;
        default: printf("Неверный выбор. Попробуйте снова.\n");
        }
    } while (choice != 0);

    return 0;
}

// --- Сценарий для Лабораторной №11 ---
void run_task11() {
    printf("\n--- Запуск Лабораторной №11 ---\n");
    int n;
    printf("Введите количество элементов массива (целые числа): ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Размер должен быть > 0.\n");
        return;
    }

    int* arr = (int*)malloc(n * sizeof(int));
    printf("Введите %d целых чисел:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Вызов функции из arrays.c
    int result = count_before_min(arr, n);

    printf("Количество элементов до минимального: %d\n", result);
    free(arr);
}

// --- Сценарий для Лабораторной №14 ---
void run_task14() {
    printf("\n--- Запуск Лабораторной №14 ---\n");
    int size;
    printf("Введите размер массива: ");
    scanf("%d", &size);

    if (size <= 0) return;

    double* arr = (double*)malloc(size * sizeof(double));

    // Используем функцию заполнения из arrays.c
    fill_random_array(arr, size, -50.0, 50.0);
    print_double_array("Сгенерированный массив", arr, size);

    double A, B;
    printf("Введите границы интервала A и B: ");
    scanf("%lf %lf", &A, &B);

    if (A > B) { double t = A; A = B; B = t; } // Обмен если перепутаны

    int found = 0;
    // Вызов логики из arrays.c
    double minVal = find_min_in_interval(arr, size, A, B, &found);

    if (found) {
        printf("Минимальный элемент в (%0.2f, %0.2f): %0.2f\n", A, B, minVal);
    }
    else {
        printf("В интервале (%0.2f, %0.2f) нет элементов.\n", A, B);
    }

    free(arr);
}

// --- Сценарий для Лабораторной №16 ---
void run_task16() {
    printf("\n--- Запуск Лабораторной №16 ---\n");

    // Генерируем случайные размеры от 10 до 50
    int n = 10 + rand() % 41;
    int m = 10 + rand() % 41;
    int l = 10 + rand() % 41;

    double* A = (double*)malloc(n * sizeof(double));
    double* B = (double*)malloc(m * sizeof(double));
    double* C = (double*)malloc(l * sizeof(double));

    fill_random_array(A, n, -100, 100);
    fill_random_array(B, m, -100, 100);
    fill_random_array(C, l, -100, 100);

    print_double_array("Массив A", A, n);
    print_double_array("Массив B", B, m);
    print_double_array("Массив C", C, l);

    int sizeD;
    // Вызов логики из arrays.c
    double* D = create_merged_array(A, n, B, m, C, l, &sizeD);

    if (D != NULL) {
        printf("Результат (Массив D):\n");
        print_double_array("D", D, sizeD);
        free(D);
    }

    free(A); free(B); free(C);
}
