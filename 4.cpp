#include <iostream>
#include<conio.h>
#include<clocale>
#include<cmath>
int main(int argc, char** argv) {
    setlocale(LC_CTYPE,"");
    double arr[20];
    int n;
    printf("Введите размер массива (0-20): ");
    scanf("%d", &n);
    if (n < 0 || n > 20) {
        printf("Ошибка! Размер должен быть от 0 до 20\n");
        return 1;
    }
    if (n == 0) {
        printf("Массив пуст\n");
        return 0;
    }
    printf("Введите %d чисел:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &arr[i]);
    }
    printf("\nИсходный массив: ");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
    double max = arr[0];
    int max_index = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] >= max) {
            max = arr[i];
            max_index = i;
        }
    }
    printf("Максимальный элемент: %.2f\n", max);
    printf("Индекс максимального: %d\n", max_index);
    double min = arr[0];
    int min_index = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
            min_index = i;
        }
    }
    printf("Минимальный элемент: %.2f\n", min);
    printf("Индекс минимального: %d\n", min_index);
    double positive[20];
    double negative[20];
    int count_positive = 0;
    int count_negative = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0) {
            positive[count_positive] = arr[i];
            count_positive++;
        } else {
            negative[count_negative] = arr[i];
            count_negative++;
        }
    }
    
    // Сортируем положительные числа по возрастанию (пузырьковая сортировка)
    for (int i = 0; i < count_positive - 1; i++) {
        for (int j = 0; j < count_positive - i - 1; j++) {
            if (positive[j] > positive[j + 1]) {
                double temp = positive[j];
                positive[j] = positive[j + 1];
                positive[j + 1] = temp;
            }
        }
    }
    
    // Сортируем отрицательные числа по возрастанию (пузырьковая сортировка)
    for (int i = 0; i < count_negative - 1; i++) {
        for (int j = 0; j < count_negative - i - 1; j++) {
            if (negative[j] > negative[j + 1]) {
                double temp = negative[j];
                negative[j] = negative[j + 1];
                negative[j + 1] = temp;
            }
        }
    }
    int index = 0;
    for (int i = 0; i < count_positive; i++) {
        arr[index] = positive[i];
        index++;
    }
    for (int i = 0; i < count_negative; i++) {
        arr[index] = negative[i];
        index++;
    }
    printf("\nОтсортированный массив: ");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
    return 0;
}

