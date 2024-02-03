#include <iostream>
#include "dynamicArray.h"
#include "sortedDynamicArray.h"
using namespace std;

int main() {
    dynamicArray<int>* arr = new dynamicArray<int>;
    arr->append(5);
    arr->append(2);
    arr->append(1);
    arr->append(3);
    arr->append(6);
    arr->append(6);
    arr->append(6);
    arr->append(6);
    arr->append(6);
    arr->append(66);
    arr->append(0);
    arr->append(5);
    arr->append(6);
    arr->append(4);
    arr->direct_access_sort();
    arr->print();
    return 0;
}
