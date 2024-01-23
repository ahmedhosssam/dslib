#ifndef SORTEDDYNAMICARRAY_H
#define SORTEDDYNAMICARRAY_H

#include "dynamicArray.h"

template <typename T>
class SortedDynamicArray: public dynamicArray<T> {
    private:
        T binarySearch(T target, size_t i, size_t j) {      // O(log n)
            if (i >= j) return i;
            size_t m = (i + j) / 2;
            T x = this.getAt(m);
            if (x > target) return binarySearch(target, i, m-1);
            if (x < target) return binarySearch(target, m+1, j);
            return m;
        }
};

#endif
