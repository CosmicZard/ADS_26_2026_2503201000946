#include <iostream>
using namespace std;

#define MAXSIZE 5

class CircularQueue {
    int cq[MAXSIZE];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    // Enqueue
    void enqueue(int value) {
        if ((rear + 1) % MAXSIZE == front) {
            cout << "Queue Overflow\n";
            return;
        }

        if (front == -1)
            front = 0;

        rear = (rear + 1) % MAXSIZE;
        cq[rear] = value;

        cout << value << " inserted\n";
    }

    // Dequeue
    void dequeue() {
        if (front == -1) {
            cout << "Queue Underflow\n";
            return;
        }

        cout << cq[front] << " deleted\n";

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAXSIZE;
        }
    }

    // Display
    void display() {
        if (front == -1) {
            cout << "Queue is empty\n";
            return;
        }
        
        for (int i = front; i != rear; i = (i + 1) % MAXSIZE) {
            cout << cq[i] << " ";
        }
        cout << cq[rear] << " ";
        cout << endl;
    }
};

int main() {
    CircularQueue cq;

    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.enqueue(50);

    cq.display();

    cq.dequeue();
    cq.dequeue();

    cq.display();

    cq.enqueue(60);
    cq.enqueue(70);

    cq.display();

    return 0;
}