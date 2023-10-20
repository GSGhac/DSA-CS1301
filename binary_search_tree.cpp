#include <iostream>

class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int data) : key(data), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    Node* insertRec(Node* root, int key) {
        if (root == nullptr)
            return new Node(key);

        if (key < root->key)
            root->left = insertRec(root->left, key);
        else if (key > root->key)
            root->right = insertRec(root->right, key);

        return root;
    }

    void inorderRec(Node* root) {
        if (root != nullptr) {
            inorderRec(root->left);
            std::cout << root->key << " ";
            inorderRec(root->right);
        }
    }

public:
    BST() : root(nullptr) {}

    void insert(int key) {
        root = insertRec(root, key);
    }

    void inorder() {
        inorderRec(root);
        std::cout << std::endl;
    }
};

int main() {
    BST bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    std::cout << "Inorder traversal of the BST: ";
    bst.inorder();

    return 0;
}


