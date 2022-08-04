#include "arrayutils.h"

template <typename T>
int length(T *arr) {
    return sizeof(arr) / sizeof(T);
}