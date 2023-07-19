#Implement Stack using Array

public class Solution {

    public static void main(String[] args) {

        stack s = new stack();
        s.push(6);
        s.push(3);
        s.push(7);
        System.out.println("Top of the stack before deleting any element " + s.top());
        System.out.println("Size of the stack before deleting any element " + s.size());
        System.out.println("The element deleted is " + s.pop());
        System.out.println("Size of the stack after deleting an element " + s.size());
        System.out.println("Top of the stack after deleting an element " + s.top());
    }
}
class stack {
    int size = 10000;
    int arr[] = new int[size];
    int top = -1;
    void push(int x) {
        top++;
        arr[top] = x;
    }
    int pop() {
        int x = arr[top];
        top--;
        return x;
    }
    int top() {
        return arr[top];
    }
    int size() {
        return top + 1;
    }
}




#Implement Queue using Arrays

class Queue {

    private int arr[];
    private int start, end, currSize, maxSize;
    public Queue() {
        arr = new int[16];
        start = -1;
        end = -1;
        currSize = 0;
    }

    public Queue(int maxSize) {
        this.maxSize = maxSize;
        arr = new int[maxSize];
        start = -1;
        end = -1;
        currSize = 0;
    }
    public void push(int newElement) {
        if (currSize == maxSize) {
            System.out.println("Queue is full\nExiting...");
            System.exit(1);
        }
        if (end == -1) {
            start = 0;
            end = 0;
        } else
            end = (end + 1) % maxSize;
        arr[end] = newElement;
        System.out.println("The element pushed is " + newElement);
        currSize++;
    }
    public int pop() {
        if (start == -1) {
            System.out.println("Queue Empty\nExiting...");
            System.exit(1);
        }
        int popped = arr[start];
        if (currSize == 1) {
            start = -1;
            end = -1;
        } else
            start = (start + 1) % maxSize;
        currSize--;
        return popped;
    }
    public int top() {
        if (start == -1) {
            System.out.println("Queue is Empty");
            System.exit(1);
        }
        return arr[start];
    }
    public int size() {
        return currSize;
    }

}


public class Solution {
    public static void main(String args[]) {
        Queue q = new Queue(6);
        q.push(4);
        q.push(14);
        q.push(24);
        q.push(34);
        System.out.println("The peek of the queue before deleting any element " + q.top());
        System.out.println("The size of the queue before deletion " + q.size());
        System.out.println("The first element to be deleted " + q.pop());
        System.out.println("The peek of the queue after deleting an element " + q.top());
        System.out.println("The size of the queue after deleting an element " + q.size());
    }
}


#Implement Stack using Queue

public class Solution {

    public static void main(String[] args) {
        stack s = new stack();
        s.push(3);
        s.push(2);
        s.push(4);
        s.push(1);
        System.out.println("Top of the stack: " + s.top());
        System.out.println("Size of the stack before removing element: " + s.size());
        System.out.println("The deleted element is: " + s.pop());
        System.out.println("Top of the stack after removing element: " + s.top());
        System.out.println("Size of the stack after removing element: " + s.size());
    }

}
class stack {
    Queue < Integer > q = new LinkedList < > ();
    void push(int x) {
        q.add(x);
        for (int i = 0; i < q.size() - 1; i++) {
            q.add(q.remove());
        }
    }
    int pop() {
        return q.remove();
    }
    int top() {
        return q.peek();
    }
    int size() {
        return q.size();
    }
}


#Implement Queue using Stack

  class MyQueue {
    Stack < Integer > input = new Stack < > ();
    Stack < Integer > output = new Stack < > ();
    /** Initialize your data structure here. */
    public MyQueue() {

    }

    /** Push element x to the back of queue. */
    public void push(int x) {
        while (input.empty() == false) {
            output.push(input.peek());
            input.pop();
        }
        // Insert the desired element in the stack input
        System.out.println("The element pushed is " + x);
        input.push(x);
        // Pop out elements from the stack output and push them into the stack input
        while (output.empty() == false) {
            input.push(output.peek());
            output.pop();
        }

    }

    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
        // shift input to output 
        if (input.empty()) {
            System.out.println("Stack is empty");

        }
        int val = input.peek();
        input.pop();
        return val;

    }

    /** Get the front element. */
    public int peek() {
        // shift input to output 
        if (input.empty()) {
            System.out.println("Stack is empty");

        }
        return input.peek();
    }


    int size() {
        return input.size();
    }
}
class Solution {
    public static void main(String args[]) {
        MyQueue q = new MyQueue();
        q.push(3);
        q.push(4);
        System.out.println("The element poped is " + q.pop());
        q.push(5);
        System.out.println("The top element is " + q.peek());
        System.out.println("The size of the queue is " + q.size());

    }
}

#Implement stack using Linkedlist

  class stack {
  private class stackNode {
    int data;
    stackNode next;
    stackNode(int d) {
      data = d;
      next = null;
    }
  }
  stackNode top;
  int size;
  stack() {
    this.top = null;
    this.size = 0;
  }
  public void stackPush(int x) {
    stackNode element = new stackNode(x);
    element.next = top;
    top = element;
    System.out.println("Element pushed");
    size++;
  }
  public int stackPop() {
    if (top == null) return -1;
    int topData = top.data;
    stackNode temp = top;
    top = top.next;
    return topData;
  }
  public int stackSize() {
    return size;
  }
  public boolean stackIsEmpty() {
    return top == null;
  }
  public void printStack() {
    stackNode current = top;
    while (current != null) {
      System.out.print(current.data + " ");
      current = current.next;
    }
    System.out.println();
  }
}
class Main {
  public static void main(String args[]) {
    stack s = new stack();
    s.stackPush(10);
    s.stackPush(20);
    s.printStack();
    System.out.println("Element popped " + s.stackPop());
    System.out.println("Stack size: " + s.stackSize());
    System.out.println("Stack is empty or not: " + s.stackIsEmpty());

  }
}


#Implement queue using Linkedlist

  class QueueNode
{
    int val;
    QueueNode next;
    QueueNode(int data)
    {
       val = data;
       next = null;
    }
}  


class Queue
{
    QueueNode Front = null, Rear = null;
    int size = 0;

boolean Empty()
{
    return Front == null;
}  
int Peek()
{
    if(Empty())  
     {  System.out.println("Queue is Empty");
        return -1;
     } 
    else 
      return Front.val;
}   
void Enqueue(int value)
{
    QueueNode Temp;
    Temp = new QueueNode(value); 
    if (Temp == null)  //When heap exhausted 
        System.out.println("Queue is Full");
    else
    {
        if (Front == null)
        {
            Front = Temp;
            Rear = Temp;
        } 
        else
        {
            Rear.next = Temp;
            Rear = Temp;
        }
        System.out.println(value+" Inserted into Queue ");
        size++;
    } 
}      
void Dequeue() 
{
    if (Front == null) 
        System.out.println("Queue is Empty");
    else
    { 
        System.out.println(Front.val+" Removed From Queue");
        QueueNode Temp = Front;
        Front = Front.next;
        size--;
    }  
}  
public static void main(String args[])

{
    Queue Q=new Queue();
    Q.Enqueue(10);
    Q.Enqueue(20);
    Q.Enqueue(30);
    Q.Enqueue(40);
    Q.Enqueue(50);
    Q.Dequeue();
    System.out.println("The size of the Queue is "+Q.size);
    System.out.println("The Peek element of the Queue is "+Q.Peek());
}
}   

