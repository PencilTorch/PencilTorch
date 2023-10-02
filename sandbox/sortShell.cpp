// сортировка Шелла
// https://kwork.ru/projects/2207968/view
#include <iostream>
#include <stdlib.h>
#include <time.h>

int const SIZE = 10;
int const MIN = 4;
int const MAX = 67;

// получить случайное целое число
int GetRandomNumber(int min = 0, int max = 100) {
    int num = min + rand() % (max - min + 1);
    return num;
}

// заполнение массива
void fillArr(int** arr, const int size) {
    srand(time(NULL));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            arr[i][j] = GetRandomNumber(MIN, MAX);
        }
    }  
}

// печать массива
void printArr(const int* arr[], const int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << arr[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// сортировка
void shellSort(int arr[], int size) {
    int step = size / 2;
    while (step > 0) {
        for (int i = step; i < size; i++) {
            int temp = arr[i], j;
            for (j = i - step; (j >= 0) && (arr[j] > temp); j -= step)
                arr[j + step] = arr[j];
            arr[j + step] = temp;
        }
        step /= 2;
    }
}



int main() {
    int arr[SIZE][SIZE];
    fillArr(arr, SIZE);
    printArr(arr, SIZE);
    shellSort(arr, SIZE);
    printArr(arr, SIZE);

    return 0;
}

