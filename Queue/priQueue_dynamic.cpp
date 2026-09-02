  #include <iostream>
using namespace std;

struct Node {
    int data;
    int priority;
    Node* next;

    Node(int d, int p) {
        data = d;
        priority = p;
        next = NULL;
    }
};

class PriorityQueue {
    Node* front;

public:
    PriorityQueue() {
        front = NULL;
    }

    void enqueue(int data, int priority) {
        Node* newNode = new Node(data, priority);

        if (front == NULL || priority < front->priority) {
            newNode->next = front;
            front = newNode;
            return;
        }

        Node* temp = front;

        while (temp->next != NULL &&
               temp->next->priority <= priority) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void dequeue() {
        if (front == NULL) {
            cout << "Priority Queue is Empty\n";
            return;
        }

        Node* temp = front;
        cout << "Deleted: " << temp->data << endl;
        front = front->next;
        delete temp;
    }

    void display() {
        if (front == NULL) {
            cout << "Priority Queue is Empty\n";
            return;
        }

        Node* temp = front;

        while (temp != NULL) {
            cout << "Data: " << temp->data
                 << " Priority: " << temp->priority << endl;
            temp = temp->next;
        }
    }
};

int main() {
    PriorityQueue pq;

    pq.enqueue(10, 3);
    pq.enqueue(20, 1);
    pq.enqueue(30, 2);
    pq.enqueue(40, 1);

    cout << "Priority Queue:\n";
    pq.display();

    cout << "\n";
    pq.dequeue();

    cout << "\nAfter Deletion:\n";
    pq.display();

    return 0;
}