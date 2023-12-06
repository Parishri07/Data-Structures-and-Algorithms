#include <iostream>

// Define the structure for a binary tree node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to insert a new element into the binary tree
TreeNode* insert(TreeNode* root, int value) {
    if (root == nullptr) {
        return new TreeNode(value);
    }
    
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    
    return root;
}

// Function to find the minimum value node in a binary tree
TreeNode* findMin(TreeNode* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

// Function to delete a node with a given value from the binary tree
TreeNode* deleteNode(TreeNode* root, int value) {
    if (root == nullptr) {
        return root;
    }
    
    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        
        // Node with two children: Get the in-order successor (min value in the right subtree)
        TreeNode* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    
    return root;
}

// Function to perform an in-order traversal of the binary tree
void inOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    
    inOrderTraversal(root->left);
    std::cout << root->data << " ";
    inOrderTraversal(root->right);
}

int main() {
    TreeNode* root = nullptr;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    std::cout << "In-order traversal of the tree: ";
    inOrderTraversal(root);
    std::cout << std::endl;

    root = deleteNode(root, 30);

    std::cout << "In-order traversal after deleting 30: ";
    inOrderTraversal(root);
    std::cout << std::endl;

    return 0;
}
