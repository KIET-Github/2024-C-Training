//Stack Implementation
#include<iostream>
using namespace std;
#define MAX 1000 
  
class Stack
{
   int top;
   public:
   int myStack[MAX]; 
  
   Stack() { top = -1; }
   bool push(int x);
   int pop();
   bool isEmpty();
};
   bool Stack::push(int item)
   {
      if (top >= (MAX-1)) {
      cout << "Stack Overflow!!!";
      return false;
   }
else {
   myStack[++top] = item;
   cout<<item<<endl;
   return true;
   }
}
int Stack::pop()
{
   if (top < 0) {
      cout << "Stack Underflow!!";
      return 0;
   }
else {
       int item = myStack[top--];
      return item;
   }
}
bool Stack::isEmpty()
{
   return (top < 0);
}
int main()
{
   class Stack stack;
   cout<<"The Stack Push "<<endl;
   stack.push(5);
   stack.push(7);
   stack.push(8);
   cout<<"The Stack Pop : "<<endl;
   while(!stack.isEmpty())
      {
      cout<<stack.pop()<<endl;
      }
   return 0;
}

//Queue Implemantation
#include <iostream>
using namespace std;
int queue[50];
int n = 50;
int front = - 1;
int rear = - 1;
void Queue_insertion() {
   int val;
   if (rear == n - 1)
      cout<<"Queue Overflow"<<endl;
   else {
    
      front = 0;
      cout<<" insert value in the queue : "<<endl;
      cin>>val;
      rear++;
      queue[rear] = val;
   }
}
void Delete() {
   if (front == - 1) {
      cout<<"Queue Underflow ";
   return ;
   } else {
      cout<<"Element deleted from queue is : "<< queue[front] <<endl;
      front++;;
   }
}
void Display_Queue () {
   if (front == - 1 )
   cout<<"Queue is empty"<<endl;
   else {
      cout<<"Queue elements are : ";
      for (int i = front; i <= rear; i++)
         cout<<queue[i]<<" ";
      cout<<endl;
   }
}
int main() {
   int ch;
   cout<<"1) insertion element to the queue"<<endl;
   cout<<"2) Delete element from queue"<<endl;
   cout<<"3) Display all the elements of queue"<<endl;
   cout<<"4) Exit"<<endl;
do {
   cout<<"Enter your choice : "<<endl;
   cin>>ch;
   switch (ch) {
      case 1: Queue_insertion();
         break;
      case 2: Delete();
         break;
      case 3: Display_Queue ();
         break;
      case 4: cout<<"Exit"<<endl;
         break;
      default: cout<<"Invalid choice"<<endl;
   }
} while(ch!=4);
   return 0;
}
