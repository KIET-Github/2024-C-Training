#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
  
   stack<int> st;

    // Pushing elements onto the stack
    st.push(10);
    st.push(20);
    st.push(30);

    // Pop and print elements from the stack
     cout << "Top element of stack is : " << st.top()<<endl;
     
    while (!st.empty()) {
      cout << "After pooping the top element of stack is : " << st.top() <<endl;
        st.pop();
    }
    cout << endl;

    // Queue implementation
    queue<int> q;

    // Pushing elements into the queue
    q.push(100);
    q.push(200);
    q.push(300);

    // Accessing  elements of the queue
    cout << "Front of the queue: " << q.front()<<endl;
    cout << "Back of the queue: " << q.back() << endl;
    cout <<endl;

    // Pop and print elements from the queue
    while (!q.empty()) {
      cout << "Queue element is: " << q.front() << endl;
        q.pop();
    }
    cout << endl;

    // Check if the stack and queue are empty
    cout << "Is stack empty? " << (q.empty() ? "Yes" : "No") << endl;
    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl;

    return 0;
}
