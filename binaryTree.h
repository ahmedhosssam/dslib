#ifndef BINARYTREE_H
#define BINARYTREE_H

template <typename T>
class BinaryTree {
private:
    struct Node {
        T key;
        Node* parent = nullptr;
        Node* left = nullptr;
        Node* right = nullptr;
    };
    int n = 0;
    Node* root = nullptr;
public:
    Node* get_root() {
        return root->key;
    }

    Node* get_node(T& key) {
    }

    void print_leaves() {
    }

    void print() {
    }

    void insert(T& key) {
    }

    void remove(T& key) {
    }
};

#endif
