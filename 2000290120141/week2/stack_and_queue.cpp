#include <iostream>
#include <stack>
#include <queue>

int main() {
    // Stack implementation
    std::stack<int> myStack;

    // Pushing elements onto the stack
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    // Pop and print elements from the stack
    while (!myStack.empty()) {
        std::cout << "Stack top: " << myStack.top() << std::endl;
        myStack.pop();
    }
    std::cout << std::endl;

    // Queue implementation
    std::queue<int> myQueue;

    // Pushing elements into the queue
    myQueue.push(40);
    myQueue.push(50);
    myQueue.push(60);

    // Accessing the front and back elements of the queue
    std::cout << "Front of the queue: " << myQueue.front() << std::endl;
    std::cout << "Back of the queue: " << myQueue.back() << std::endl;
    std::cout << std::endl;

    // Pop and print elements from the queue
    while (!myQueue.empty()) {
        std::cout << "Queue front: " << myQueue.front() << std::endl;
        myQueue.pop();
    }
    std::cout << std::endl;

    // Check if the stack and queue are empty
    std::cout << "Is stack empty? " << (myStack.empty() ? "Yes" : "No") << std::endl;
    std::cout << "Is queue empty? " << (myQueue.empty() ? "Yes" : "No") << std::endl;

    return 0;
}
