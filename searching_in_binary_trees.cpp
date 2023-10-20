#include <iostream>

// Define a structure for a binary tree node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to search for a key in the binary tree
bool search(TreeNode* root, int key) {
    if (root == nullptr) {
        return false; // The tree is empty, or the key is not found
    }

    if (root->data == key) {
        return true; // Key found in the current node
    }

    if (key < root->data) {
        return search(root->left, key); // Search in the left subtree
    } else {
        return search(root->right, key); // Search in the right subtree
    }
}

int main() {
    TreeNode* root = new TreeNode(50);
    root->left = new TreeNode(30);
    root->right = new TreeNode(70);
    root->left->left = new TreeNode(20);
    root->left->right = new TreeNode(40);
    root->right->left = new TreeNode(60);
    root->right->right = new TreeNode(80);

    int keyToSearch = 30;

    if (search(root, keyToSearch)) {
        std::cout << keyToSearch << " found in the binary tree." << std::endl;
    } else {
        std::cout << keyToSearch << " not found in the binary tree." << std::endl;
    }

    return 0;
}
