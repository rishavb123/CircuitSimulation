#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H

#include <iostream>

template <typename T>
int length(T *arr) {
    return sizeof(arr) / sizeof(T);
}

template <typename T>
void printArray(T *arr) {
    int len = length(arr);
    for (int i = 0; i < len; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void print2DArray(T **arr) {
    int len = length(arr);
    for (int i = 0; i < len; i++) {
        printArray(arr[i]);
    }
}

#endif // !ARRAY_UTILS_H
