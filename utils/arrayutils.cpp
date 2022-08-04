#include "arrayutils.h"

template <typename T>
int length(void *arr) {
    return sizeof(arr) / sizeof(T);
}