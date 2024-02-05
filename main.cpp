#include <iostream>
#include "dynamicArray.h"
#include "sortedDynamicArray.h"
#include "binaryTree.h"
using namespace std;

int main() {
    BinaryTree<int>* t = new BinaryTree<int>;
    t->insert(5);
    t->insert(3);
    t->insert(66);
    t->insert(1);
    t->print();
    return 0;
}
