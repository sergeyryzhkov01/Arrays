#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "arrays.h"

// Прототипы функций
void run_task11();
void run_task14();
void run_task16();
void run_task17();

int main() {
    setlocale(LC_ALL, "Rus");
    srand(time(NULL)); 

    int choice;
    do {
        printf("\n=== МЕНЮ ЛАБОРАТОРНЫХ РАБОТ ===\n");
        printf("1. Лабораторная №11 (Кол-во до минимума)\n");
        printf("2. Лабораторная №14 (Минимум в интервале)\n");
        printf("3. Лабораторная №16 (Объединение массивов)\n");
        printf("4. Лабораторная №17 (Сравнение сортировок)\n");
        printf("0. Выход\n");
        printf("Ваш выбор: ");
        
        if (scanf("%d", &choice) != 1) {
            while(getchar() != '\n'); 
            choice = -1;
        }

        switch (choice) {
            case 1: run_task11(); break;
            case 2: run_task14(); break;
            case 3: run_task16(); break;
            case 4: run_task17(); break;
            case 0: printf("Выход.\n"); break;
            default: printf("Неверный выбор.\n");
        }
    } while (choice != 0);

    return 0;
}

/* --- Лаб 11 --- */
void run_task11() {
    printf("\n--- Запуск Лаб 11 ---\n");
    int n;
    printf("Введите размер массива: ");
    if (scanf("%d", &n) != 1 || n <= 0) return;

    int* arr = (int*)malloc(n * sizeof(int));
    printf("Введите %d целых чисел:\n", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    int result = count_before_min(arr, n);
    printf("Количество элементов до минимума: %d\n", result);
    free(arr);
}

/* --- Лаб 14 --- */
void run_task14() {
    printf("\n--- Запуск Лаб 14 ---\n");
    int size;
    printf("Введите размер массива: ");
    if (scanf("%d", &size) != 1 || size <= 0) return;

    double* arr = (double*)malloc(size * sizeof(double));
    fill_random_array(arr, size, -50.0, 50.0);
    print_double_array("Массив", arr, size);

    double A, B;
    printf("Введите интервал A B: ");
    scanf("%lf %lf", &A, &B);
    if (A > B) { double t = A; A = B; B = t; }

    int found = 0;
    double minVal = find_min_in_interval(arr, size, A, B, &found);

    if (found) printf("Минимум в (%0.2f, %0.2f): %0.2f\n", A, B, minVal);
    else printf("Нет элементов в интервале.\n");

    free(arr);
}

/* --- Сценарий Лаб 16 --- */
void run_task16() {
    printf("\n--- Запуск Лаб 16 ---\n");
    int n = 10 + rand() % 41;
    int m = 10 + rand() % 41;
    int l = 10 + rand() % 41;

    double *A = (double*)malloc(n * sizeof(double));
    double *B = (double*)malloc(m * sizeof(double));
    double *C = (double*)malloc(l * sizeof(double));

    fill_random_array(A, n, -100, 100);
    fill_random_array(B, m, -100, 100);
    fill_random_array(C, l, -100, 100);

    print_double_array("A", A, n);
    print_double_array("B", B, m);
    print_double_array("C", C, l);

    int sizeD;
    double* D = create_merged_array(A, n, B, m, C, l, &sizeD);
    
    printf("Результат:\n");
    print_double_array("D", D, sizeD);

    free(A); free(B); free(C); free(D);
}

/* --- Лаб 17 --- */
void run_task17() {
    printf("\n--- Запуск Лаб 17 (Эксперимент) ---\n");
    int size;
    printf("Введите размер массива: ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        printf("Некорректный размер.\n");
        return;
    }

    // Создаем два массива: источник (эталон) и рабочий (который будем сортировать)
    int* source = (int*)malloc(size * sizeof(int));
    int* work = (int*)malloc(size * sizeof(int));

    if (!source || !work) {
        printf("Ошибка памяти.\n");
        return;
    }

    // Заполнение эталонного массива
    full_array(source, size);
    printf("Исходный массив (первые элементы): ");
    put_array(source, size);
    printf("\n--- Результаты замеров ---\n");

    clock_t t;
    double time_taken;

    // 1. Пузырьковая
    copy_int_array(source, work, size); // Сброс данных
    t = clock();
    sort_bubble(work, size);
    time_taken = (double)(clock() - t) / CLOCKS_PER_SEC;
    printf("Bubble Sort: %.6f сек.\n", time_taken);

    // 2. Шейкерная
    copy_int_array(source, work, size); // Сброс данных
    t = clock();
    sort_kokteil(work, size);
    time_taken = (double)(clock() - t) / CLOCKS_PER_SEC;
    printf("Shaker Sort: %.6f сек.\n", time_taken);

    // 3. Выбором
    copy_int_array(source, work, size); // Сброс данных
    t = clock();
    sort_select(work, size);
    time_taken = (double)(clock() - t) / CLOCKS_PER_SEC;
    printf("Select Sort: %.6f сек.\n", time_taken);

    // 4. Вставками
    copy_int_array(source, work, size); // Сброс данных
    t = clock();
    sort_insert(work, size);
    time_taken = (double)(clock() - t) / CLOCKS_PER_SEC;
    printf("Insert Sort: %.6f сек.\n", time_taken);

    free(source);
    free(work);
}
