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
            cout << " gg " << ptr->key << endl;
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
        Node* p = ptr;
        while (ptr != nullptr) {
            ptr = ptr->left;
        }
        return p;
    }

    Node* find_successor(Node* ptr) {
        Node* p = ptr;
        if (ptr->right != nullptr) {
            p = find_first(ptr->right);
        } else {
            if (p->parent->parent != nullptr) {
                p = p->parent->parent;
            } else if (p->parent != nullptr) {
                p = p->parent;
            }
        }
        return p;
    }

    Node* find_predecessor(Node *ptr) {
        if (ptr->left != nullptr) {
            return ptr->left;
        }
        return nullptr;
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
        Node* ptr = get_node(key);
        if (ptr == nullptr) {
            cout << "[ " << key << " ] Not Found :/\n";
            return;
        }

        // if node is a leaf
        if (ptr->left == nullptr && ptr->right == nullptr) {
            ptr = ptr->parent;
            if (ptr->left->key == key) {
                ptr->left = nullptr;
            } else {
                ptr->right = nullptr;
            }
        // so, it has a child
        } else {
            if (ptr->left != nullptr) {
                Node* pp = ptr;
                Node* pp1 = ptr;
                while (find_predecessor(pp) != nullptr) {
                    pp1 = pp;
                    pp = find_predecessor(pp);
                    T temp = pp1->key;
                    pp1->key = pp->key;
                    pp->key = temp;
                }
                T temp = pp->key;
                pp = pp->parent;
                if (pp->left->key == temp) {
                    pp->left = nullptr;
                } else {
                    pp->right = nullptr;
                }
            }
        }
    }

    int get_size() const {
        return n;
    }
};

#endif
