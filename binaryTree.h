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

    Node* get_node(T key) {
        Node* ptr = root;
        while (ptr != nullptr) {
            if (key < ptr->key) {
                ptr = ptr->left;
            } else  if (ptr->key == key) {
                break;
            } else {
                ptr = ptr->right;
            }
        }
        if (ptr->key != key || ptr == nullptr) {
            cout << "Not found\n";
            return nullptr;
        }
        return ptr;
    }

    // print all the keys
    void traverse(Node* ptr) {
        if (ptr == nullptr) { return; }
        traverse (ptr->left);
        cout << ptr->key << endl;
        traverse (ptr->right);
    }

public:
    T get_root() {
        if (n == 0) {
            cout << "Tree is empty\n";
            return nullptr;
        }
        return root->key;
    }

    void print() {
        traverse(root);
    }

    void print_leaves() {
    }

    void insert(T key) {
        Node* newNode = new Node;
        newNode->key = key;
        if (root == nullptr) {
            root = newNode;
            n++;
            return;
        }
        Node* ptr = root;
        while (true) {
            if (key < ptr->key) {
                if (ptr->left == nullptr) {
                    break;
                } else {
                    ptr = ptr->left;
                }
            } else {
                if (ptr->right == nullptr) {
                    break;
                } else {
                    ptr = ptr->right;
                }
            }
        }
        newNode->parent = ptr;
        ptr->left == nullptr ? ptr->left = newNode : ptr->right = newNode;
        n++;
    }

    void remove(T key) {
    }

    int get_size() const {
        return n;
    }
};

#endif
