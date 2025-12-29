/**
 * arrays.h - Заголовочный файл для работы с массивами
 * Содержит прототипы функций для Лабораторных работ 11, 14, 16
 */

#ifndef ARRAYS_H
#define ARRAYS_H

 /* === Общие вспомогательные функции === */

 /**
  * Генерация случайного вещественного числа в диапазоне [min, max]
  */
double random_double(double min, double max);

/**
 * Печать массива int (для Лаб 11)
 */
void print_int_array(const char* name, int* arr, int n);

/**
 * Печать массива double (для Лаб 14, 16)
 */
void print_double_array(const char* name, double* arr, int n);


/* === Функции для Лабораторной работы 11 === */

/**
 * Подсчет количества элементов до минимального элемента
 * @param arr указатель на целочисленный массив
 * @param n размер массива
 * @return количество элементов (индекс минимума)
 */
int count_before_min(int* arr, int n);


/* === Функции для Лабораторной работы 14 === */

/**
 * Заполнение массива случайными числами (аналог full_elements из примера)
 */
void fill_random_array(double* arr, int n, double min, double max);

/**
 * Поиск минимального значения в интервале (A, B)
 * @param arr указатель на массив
 * @param n размер массива
 * @param A левая граница (строго >)
 * @param B правая граница (строго <)
 * @param isFound указатель на флаг (1 если найдено, 0 если нет)
 * @return найденное минимальное значение
 */
double find_min_in_interval(double* arr, int n, double A, double B, int* isFound);


/* === Функции для Лабораторной работы 16 === */

/**
 * Создание результирующего массива D по правилу:
 * A -> B (reverse) -> Sum(C)
 * @param A массив A
 * @param n размер A
 * @param B массив B
 * @param m размер B
 * @param C массив C
 * @param l размер C
 * @param sizeD указатель для записи размера нового массива
 * @return указатель на новый массив D
 */
double* create_merged_array(double* A, int n, double* B, int m, double* C, int l, int* sizeD);

#endif
