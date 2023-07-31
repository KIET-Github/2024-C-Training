#include <iostream>
using namespace std;

#define MAX_SIZE 100

class Stack {
    int top;
    int arr[MAX_SIZE];

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == MAX_SIZE - 1);
    }

    void push(int data) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push element " << data << endl;
            return;
        }

        arr[++top] = data;
        cout << "Pushed element " << data << " into the stack." << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop element." << endl;
            return;
        }

        int poppedElement = arr[top--];
        cout << "Popped element " << poppedElement << " from the stack." << endl;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }

        return arr[top];
    }
};

int main() {
    Stack stack;

    stack.push(50);
    stack.push(60);
    stack.push(70);
    stack.push(80);

    cout << "Top element: " << stack.peek() << endl;

    stack.pop();
    stack.pop();

    cout << "Top element: " << stack.peek() << endl;

    stack.pop();

    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
