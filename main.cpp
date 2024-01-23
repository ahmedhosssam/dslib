#include <iostream>
#include "dynamicArray.h"
#include "sortedDynamicArray.h"
using namespace std;

int main() {
    SortedDynamicArray<int> arr;
    arr.insert(6);
    arr.insert(5);
    arr.insert(1);
    arr.insert(69);
    arr.insert(7);
    arr.insert(4);
    arr.print();
    return 0;
}
