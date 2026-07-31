#include <iostream>
using namespace std;

#define SIZE 5

class Queue {
    int arr[SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int value) {
        if (rear == SIZE - 1) {
            cout << "Queue Overflow\n";
        }
        else {
            if (front == -1)
                front = 0;

            rear++;
            arr[rear] = value;
            cout << value << " inserted.\n";
        }
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow\n";
        }
        else {
            cout << arr[front] << " deleted.\n";
            front++;

            if (front > rear) {
                front = -1;
                rear = -1;
            }
        }
    }

    void peek() {
        if (front == -1)
            cout << "Queue is Empty\n";
        else
            cout << "Front Element: " << arr[front] << endl;
    }

    void display() {
        if (front == -1) {
            cout << "Queue is Empty\n";
        }
        else {
            cout << "Queue Elements: ";
            for (int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    q.dequeue();

    q.display();  

    q.peek();

    return 0;
}