#include <iostream>
using namespace std;

class Stack
{
    public:
        int *arr;
        int size;
        int top;

    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    bool isEmpty()
    {
        if(top < 0)
            return true;
        else
            return false;
    }

    bool isFull()
    {
        if(top >= size - 1)
            return true;
        else
            return false;
    }

    void push(int data)
    {
        if(isFull())
            cout << "Stack Overflow" << endl;
        else{
            top++;
            arr[top] = data;
        }
    }

    void pop()
    {
        if(isEmpty())
            cout << "Stack Underflow" << endl;
        else{
            cout << "Popped Element is : " << arr[top] << endl;
            top--;
        }
    }

    void peek()
    {
        if(!isEmpty())
            cout << arr[top] << endl;
        else
            cout << "Cannot peek Stack is Empty" << endl;
    }

    void display()
    {
        if(!isEmpty())
        {   
            int temp = top;
            while(temp != -1)
            {
                cout << arr[temp] << endl;
                temp--;
            }
        }
        else
            cout << "Cannot display Stack is Empty" << endl;
    }
};

int main()
{   
    Stack s1(3);
    s1.display();

    s1.push(1);
    s1.push(2);
    s1.push(3);

    s1.pop();
    s1.display();

    s1.peek();

    return 0;
}