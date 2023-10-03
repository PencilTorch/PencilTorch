// сортировка Шелла

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

// заполнение массива в заданном диапазоне
void fillArr(int** arr, int size) {
    srand(static_cast<unsigned int>(time(NULL)));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            arr[i][j] = GetRandomNumber(MIN, MAX);
        }
    }  
}

// печать массива
void printArr(int** arr, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << arr[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// сортировка одномерного массива
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
    int** arr = new int* [SIZE];
    for (int i = 0; i < SIZE; i++) {
        arr[i] = new int[SIZE];
    }

    fillArr(arr, SIZE);
    printArr(arr, SIZE);

    // создаем вспомогательный массив для сортировки последнего столбца
    int* aTemp = new int[SIZE];
    for (int i = 0; i < SIZE; ++i) {
        aTemp[i] = arr[i][SIZE - 1];
    }
    shellSort(aTemp, SIZE);
    std::cout << "Shell sort last column:\n";
    for (int i = 0; i < SIZE; ++i) {
        std::cout <<"\t \t \t" << aTemp[i] << std::endl;
    }

    // можно переписать в основной массив отсортированные значения
    for (int i = 0; i < SIZE; ++i) {
        arr[i][SIZE - 1] = aTemp[i];
    }
    std::cout << "\nShell sort last column in first array:\n";
    printArr(arr, SIZE);

    delete[] aTemp;
    delete[] arr;

    return 0;
}

