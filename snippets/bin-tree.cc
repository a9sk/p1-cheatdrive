#include <stdio.h>

using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
};

void inorder(Node* root) {
    if (root == NULL) return;

    inorder(root->left);
    cout << root->value << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == NULL) return;

    cout << root->value << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->value << " ";
}

void inorder_iterative(Node* root) {
    Node* stack[100];
    int top = -1;

    Node* curr = root;

    while (curr != NULL || top >= 0) {
        while (curr != NULL) {
            top++;
            stack[top] = curr;
            curr = curr->left;
        }

        curr = stack[top];
        top--;

        cout << curr->value << " ";

        curr = curr->right;
    }
}

int height(Node* root) {
    if (root == NULL) return 0;

    int hl = height(root->left);
    int hr = height(root->right);

    return (hl > hr ? hl : hr) + 1;
}

int count_nodes(Node* root) {
    if (root == NULL) return 0;

    return 1 + count_nodes(root->left) + count_nodes(root->right);
}

bool is_leaf(Node* node) {
    if (node == NULL) return false;
    return (node->left == NULL && node->right == NULL);
}

Node* insert(Node* root, int val) {
    if (root == NULL) {
        Node* newNode = new Node;
        newNode->value = val;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    if (val < root->value)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}
