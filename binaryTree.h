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
            } else if (ptr->key == key) {
                break;
            } else {
                ptr = ptr->right;
            }
        }
        if (ptr == nullptr || ptr->key != key) {
            return nullptr;
        }
        return ptr;
    }

    // print all the keys
    void traverse(Node* ptr) {
        if (ptr == nullptr) { return; }
        traverse(ptr->left);
        cout << ptr->key << endl;
        traverse(ptr->right);
    }

    Node* find_first(Node* ptr) {
        if (ptr->left) { return find_first(ptr->left); }
        else { return ptr; }
    }

    Node* find_last(Node* ptr) {
        if (ptr->right) { return find_last(ptr->right); }
        else { return ptr; }
    }

    Node* find_successor(Node* ptr) {
        if (ptr->right) {
            return find_first(ptr);
        }

        Node* p = ptr;
        while (p->parent && p == p->parent->right) {
            p = p->parent;
        }
        return p;
    }

    Node* find_predecessor(Node *ptr) {
        if (ptr->left) {
            return find_last(ptr->left);
        }

        Node* p = ptr;
        while (p->parent && p == p->parent->left) {
            p = p->parent;
        }
        return p;
    }

    void insert_before(Node* b, Node* a) {
        if (a->left) {
            a = find_last(a);
            a->right = b;
            b->parent = a;
        } else {
            a->left = b;
            b->parent = a;
        }
    }

    void insert_after(Node* b, Node* a) {
        if (a->right) {
            a = find_first(a);
            a->left = b;
            b->parent = a;
        } else {
            a->right = b;
            b->parent = a;
        }
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
        } else {
            if (key > root->key) {
                insert_after(newNode, root);
            } else {
                insert_before(newNode, root);
            }
        }
    }

    void remove(T key) {
        Node* ptr = get_node(key);
        Node* p;
        if (ptr->left || ptr->right) {
            if (ptr->left) {
                p = find_predecessor(ptr);
            } else {
                p = find_successor(ptr);
            }
            T temp = p->key;
            p->key = ptr->key;
            ptr->key = temp;
            return remove(p->key);
        }
        if (ptr->parent) {
            if (ptr->parent->left == ptr) {
                ptr->parent->left = nullptr;
            } else {
                ptr->parent->right = nullptr;
            }
        }
    }

    int get_size() const {
        return n;
    }
};

#endif
