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
    t->insert(5);
    t->insert(7);
    t->insert(6);
    //t->remove(66);
    t->remove(7);
    t->print();
    return 0;
}
