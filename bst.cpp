#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};
Node *insert(Node *root, int key)
{

    if (root == nullptr)
        return new Node(key);

    if (key == root->data)
        return root;

    if (key < root->data)
        root->left = insert(root->left, key);

    else
        root->right = insert(root->right, key);

    return root;
}

int main()
{

    Node *root = new Node(2);
    root->left = new Node(1);
    root->right = new Node(3);
    root->right->right = new Node(6);

    int key = 4;

    root = insert(root, key);

    queue<Node *> q;
    q.push(root);

    cout << "[";

    bool first = true;

    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        if (!first)
            cout << ", ";
        first = false;

        if (curr)
        {
            cout << curr->data;
            q.push(curr->left);
            q.push(curr->right);
        }
        else
        {
            cout << "N";
        }
    }

    cout << "]";

    return 0;
}