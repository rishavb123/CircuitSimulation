#include "arrayutils.h"

template <typename T>
int length(T *arr) {
    return sizeof(arr) / sizeof(T);
}

template <typename T>
void printArray(T *arr) {
    int len = length(arr);
    for (int i = 0; i < len; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}