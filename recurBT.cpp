#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

// Node class definition
class Node {
public:
    char data;
    Node* left;
    Node* right;

    Node(char val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Binary tree class definition
class BinaryTree {
public:
    Node* root;

    BinaryTree() {
        root = nullptr;
    }

    // Function to construct binary tree from prefix expression
    Node* constructTree(string prefix) {
        stack<Node*> s;

        for (int i = prefix.length() - 1; i >= 0; --i) {
            if (isdigit(prefix[i]) || isalpha(prefix[i])) {
                Node* newNode = new Node(prefix[i]);
                s.push(newNode);
            } else {
                Node* newNode = new Node(prefix[i]);
                newNode->left = s.top();
                s.pop();
                newNode->right = s.top();
                s.pop();
                s.push(newNode);
            }
        }

        return s.top();
    }

    // Function to perform inorder traversal recursively
    void inorderTraversal(Node* root) {
        if (root == nullptr)
            return;

        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }

    // Function to perform postorder traversal recursively
    void postorderTraversal(Node* root) {
        if (root == nullptr)
            return;

        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->data << " ";
    }
};

int main() {
    // Create a binary tree
    BinaryTree tree;

    // Take user input for the prefix expression
    string prefix;
    cout << "Enter the prefix expression: ";
    getline(cin, prefix);

    // Construct binary tree from the prefix expression
    tree.root = tree.constructTree(prefix);

    // Perform inorder traversal
    cout << "Inorder Traversal: ";
    tree.inorderTraversal(tree.root);
    cout << endl;

    // Perform postorder traversal
    cout << "Postorder Traversal: ";
    tree.postorderTraversal(tree.root);
    cout << endl;

    return 0;
}
