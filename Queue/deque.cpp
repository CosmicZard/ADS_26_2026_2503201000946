#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
};

Node *front = NULL;
Node *rear = NULL;

// Insert at Front
void pushFront(int x) {
    Node *newNode = new Node;

    newNode->data = x;
    newNode->next = front;
    newNode->prev = NULL;

    if (front == NULL) {
        front = rear = newNode;
    }
    else {
        front->prev = newNode;
        front = newNode;
    }
}

// Insert at Back
void pushBack(int x) {
    Node *newNode = new Node;

    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = rear;

    if (rear == NULL) {
        front = rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }
}

// Delete from Front
void popFront() {
    if (front == NULL) {
        cout << "Deque is Empty" << endl;
        return;
    }

    Node *temp = front;

    cout << "Deleted: " << temp->data << endl;

    if (front == rear) {
        front = rear = NULL;
    }
    else {
        front = front->next;
        front->prev = NULL;
    }

    delete temp;
}

// Delete from Back
void popBack() {
    if (rear == NULL) {
        cout << "Deque is Empty" << endl;
        return;
    }

    Node *temp = rear;

    cout << "Deleted: " << temp->data << endl;

    if (front == rear) {
        front = rear = NULL;
    }
    else {
        rear = rear->prev;
        rear->next = NULL;
    }

    delete temp;
}

// Peek Front
void peekFront() {
    if (front == NULL) {
        cout << "Deque is Empty" << endl;
    }
    else {
        cout << "Front: " << front->data << endl;
    }
}

// Peek Back
void peekBack() {
    if (rear == NULL) {
        cout << "Deque is Empty" << endl;
    }
    else {
        cout << "Rear: " << rear->data << endl;
    }
}

// Display
void display() {
    if (front == NULL) {
        cout << "Deque is Empty" << endl;
        return;
    }

    Node *temp = front;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {

    pushBack(10);
    pushBack(20);
    pushFront(5);
    pushFront(2);

    cout << "Deque: ";
    display();

    peekFront();
    peekBack();

    popFront();

    cout << "After popFront: ";
    display();

    popBack();

    cout << "After popBack: ";
    display();

    peekFront();
    peekBack();

    return 0;
}