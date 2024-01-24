#include <iostream>
#include "dynamicArray.h"
#include "sortedDynamicArray.h"
using namespace std;

int main() {
    dynamicArray<int>* arr = new dynamicArray<int>;
    arr->insertAt(5);
    arr->insertAt(2);
    arr->insertAt(1);
    arr->insertAt(3);
    arr->insertAt(6);
    arr->insertAt(6);
    arr->insertAt(6);
    arr->insertAt(6);
    arr->insertAt(6);
    arr->insertAt(6);
    arr->insertAt(0);
    arr->insertAt(5);
    arr->insertAt(6);
    arr->insertAt(4);
    arr->merge_sort(arr, 0, arr->getSize());
    arr->print();
    return 0;
}
