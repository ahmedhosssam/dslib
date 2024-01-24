#include <iostream>
#include "dynamicArray.h"
#include "sortedDynamicArray.h"
using namespace std;

int main() {
    dynamicArray<int>* arr = new dynamicArray<int>;
    arr->insertAt(6);
    arr->insertAt(5);
    arr->insertAt(1);
    arr->insertAt(69);
    arr->insertAt(7);
    arr->insertAt(4);
    arr->merge_sort(arr, 0, arr->getSize());
    arr->print();
    return 0;
}
