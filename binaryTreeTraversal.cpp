#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

void preorder(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int leafcount(Node* p) {
    if (p == NULL) {
        return 0;
    }
    else if (p->left == NULL && p->right == NULL) {
        return 1;
    }
    else {
        return leafcount(p->left) + leafcount(p->right);
    }
}

int internalCount(Node* p) {
    if (p == NULL)
        return 0;

    if (p->left != NULL || p->right != NULL)
        return 1 + internalCount(p->left) + internalCount(p->right);

    return 0;
}

int TotalNodes(Node* p) {
    if (p == NULL)
        return 0;

    return 1 + TotalNodes(p->left) + TotalNodes(p->right);
}

Node* create() {
    int x;
    cin >> x;

    if (x == -1)
        return NULL;

    Node* newNode = new Node();
    newNode->data = x;

    newNode->left = create();
    newNode->right = create();

    return newNode;
}

int main() {
    cout << "Enter tree data: ";
    Node* root = create();

    cout << "Preorder: ";
    preorder(root);

    cout << "\nInorder: ";
    inorder(root);

    cout << "\nPostorder: ";
    postorder(root);

    cout << "\nLeaf count: " << leafcount(root);
    cout << "\nInternal count: " << internalCount(root);
    cout << "\nTotal nodes: " << TotalNodes(root);

    return 0;
}