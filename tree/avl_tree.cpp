#include <iostream>

struct Node {
    Node(int val) : val(val), height(1), left(nullptr), right(nullptr) {}
    int val;
    int height;
    Node* left;
    Node* right;
};

class AVLTree {
public:
    AVLTree() : root_(nullptr) {}
    void insert(int val) {
        root_ = insertHelper(val);
    }

    void remove(int val) {
        root_ = removeHelper(val);
    }

    Node* search(int val) {
        Node* p = root_;
        while (p && p->val != val) {
            if (p->val > val) {
                p = p->left;
            } else {
                p = p->right;
            }
        }
        return p;
    }

    void inorder() {
        inorderHelper(root_);
    }

private:
    Node* insertHelper(int val) {
    }

    Node* removeHelper(int val) {
    }

    void inorderHelper(Node* root) {
        if (root == nullptr) {
            return;
        }
        inorderHelper(root->left);
        std::cout << root->val << " ";
        inorderHelper(root->right);
    }

    int height(Node* node) {
        return node ? node->height : 0;
    }

    int getBalance(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        return height(node->left) - height(node->right);
    }

private:
    Node* root_;
};

void test() {
    AVLTree tree;
    tree.insert(10); 
    tree.insert(20); 
    tree.insert(30); 
    tree.insert(40); 
    tree.insert(50); 
    tree.insert(25); 
    tree.inorder();

    tree.remove(25);
    tree.inorder();

    tree.remove(20);
    tree.inorder();

    Node* p = tree.search(40);
    if (p != nullptr) {
        std::cout << p->val << std::endl;
    }
}

int main() {
    test();
    return 0;
}