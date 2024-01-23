#ifndef SORTEDDYNAMICARRAY_H
#define SORTEDDYNAMICARRAY_H
#include "dynamicArray.h"

template <typename T>
class SortedDynamicArray: public dynamicArray<T> {
    private:
        int binary_search(T target, int i, int j) {      // O(log n)
            if (i >= j) { return i; }
            int m = (i + j) / 2;
            T x = this->getAt(m);
            if (x > target) return binary_search(target, i, m-1);
            if (x < target) return binary_search(target, m+1, j);
            return m;
        }

        void sort() {
            // ??
        }

    public:
        void insert(T x) {
            if (this->size == 0) {
                this->append(x);
            } else {
                size_t i = binary_search(x, 0, this->size-1);
                T k = this->getAt(i);
                if (k == x) { this->insertAt(x, i); }
                if (k > x) { this->insertAt(x, i); }
                else { this->insertAt(x, i+1); }
            }
        }
};

#endif
