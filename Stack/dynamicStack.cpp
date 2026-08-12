#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
}; 

Node* top = nullptr;

void push(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = top;
    top = newNode;
}

void pop() {
    if (top == nullptr) {
        cout << "Stack is empty. Cannot pop." << endl;
        return;
    }
    Node* temp = top;
    top = top->next;
    delete temp;
}

void peek() {
    if (top == nullptr) {
        cout << "Stack is empty." << endl;
        return;
    }
    cout << "Top element: " << top->data << endl;
}

void traverse() {
    if (top == nullptr) {
        cout << "Stack is empty." << endl;
        return;
    }
    Node* current = top;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}


int main() {
    int ch, value;
    do {
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Traverse" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                traverse();
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (ch != 5);  
    
    return 0;
}