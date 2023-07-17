// STACK IMPLEMENTATION 
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Stack {
private:
     vector<T> data;

public:
    void push(const T& element) {
        data.push_back(element);
    }

    void pop() {
        if (!isEmpty()) {
            data.pop_back();
        }
    }

    T top() const {
        if (!isEmpty()) {
            return data.back();
        }
        throw out_of_range("Stack is empty");
    }

    bool isEmpty() const {
        return data.empty();
    }
};

int main() {
    Stack<int> stack;

    int choice;
    int element;

    do {
        cout << "Stack Operations:" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Top" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the element to push: ";
                cin >> element;
                stack.push(element);
                cout << "Element pushed to the stack." << endl;
                break;
            case 2:
                if (!stack.isEmpty()) {
                    stack.pop();
                    cout << "Element popped from the stack." << endl;
                } else {
                     cout << "Stack is empty. Cannot perform pop operation." << endl;
                }
                break;
            case 3:
                if (!stack.isEmpty()) {
                   cout << "Top element: " << stack.top() << endl;
                } else {
                    cout << "Stack is empty." << endl;
                }
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

       cout << endl;
    } while (choice != 4);

    return 0;
}
