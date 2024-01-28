#include <iostream>

using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        data = value;
        left = right = nullptr;
    }
};

class BinarySearchTree {
private:
    TreeNode* root;

    TreeNode* insertNodeRecursive(TreeNode* current, int key) {
        if (current == nullptr) {
            return new TreeNode(key);
        }

        if (key < current->data) {
            current->left = insertNodeRecursive(current->left, key);
        } else if (key > current->data) {
            current->right = insertNodeRecursive(current->right, key);
        }

        return current;
    }

    void inorderTraversalRecursive(TreeNode* current) {
        if (current != nullptr) {
            inorderTraversalRecursive(current->left);
            cout << current->data << " ";
            inorderTraversalRecursive(current->right);
        }
    }

public:
    BinarySearchTree() {
        root = nullptr;
    }

    void insertNode(int key) {
        root = insertNodeRecursive(root, key);
    }

    void inorderTraversal() {
        inorderTraversalRecursive(root);
        cout << endl;
    }
};

int main() {
    BinarySearchTree bst;

    int numNodes;
    cout << "Enter the number of nodes to insert: ";
    cin >> numNodes;

    for (int i = 0; i < numNodes; ++i) {
        int key;
        cout << "Enter key for node " << i + 1 << ": ";
        cin >> key;
        bst.insertNode(key);
    }

    cout << "Inorder Traversal: ";
    bst.inorderTraversal();

    return 0;
}
