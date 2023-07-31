#include <iostream>
using namespace std;

#define MAX_SIZE 100

class Queue {
    int front, rear;
    int arr[MAX_SIZE];

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    bool isFull() {
        return (rear == MAX_SIZE - 1);
    }

    void enqueue(int data) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot enqueue element " << data << endl;
            return;
        }

        if (isEmpty()) {
            front = 0;
            rear = 0;
        } else {
            rear++;
        }

        arr[rear] = data;
        cout << "Enqueued element " << data << " into the queue." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Cannot dequeue element." << endl;
            return;
        }

        int dequeuedElement = arr[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front++;
        }

        cout << "Dequeued element " << dequeuedElement << " from the queue." << endl;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }

        return arr[front];
    }
};

int main() {
    Queue queue;

    queue.enqueue(50);
    queue.enqueue(60);
    queue.enqueue(70);
    queue.enqueue(80);

    cout << "Front element: " << queue.peek() << endl;

    queue.dequeue();
    queue.dequeue();

    cout << "Front element: " << queue.peek() << endl;

    queue.dequeue();

    cout << "Is queue empty? " << (queue.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
