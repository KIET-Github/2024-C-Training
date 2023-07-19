Stack implementation using array:

class Stack {
    int top_ele;
    int size;
    int * arr;
    
public:
    
    Stack(int capacity) {
        top_ele=-1;
        size=capacity;
        arr = new int[capacity];
    }

    void push(int num) {
      if (top_ele < size - 1) {
        top_ele++;
        arr[top_ele] = num;
      }
    }

    int pop() {
        if(top_ele<=-1){
            return -1;
        }
        int x=arr[top_ele];
        top_ele--;
        return x;
    }
    
    int top() {
        if(top_ele>=0)
        return arr[top_ele];
        else
        return -1;
    }
    
    int isEmpty() {
        if(top_ele==-1){
            return 1;
        }
        else{
            return 0;
        }
    }
    
    int isFull() {
        if(top_ele==size-1){
            return 1;
        }
        else{
            return 0;
        }
    }
    
};


Queue implementation using array:

class Queue {

	int front, rear;
	vector<int> arr;
	int size;

public:
	Queue()
	{
		front = 0;
		rear = 0;
		arr.resize(100001);
		size=0;
	}

	// Enqueue (add) element 'e' at the end of the queue.
        void enqueue(int e) 
		{
			arr[rear++]=e;
		}

        // Dequeue (retrieve) the element from the front of the queue.
	int dequeue()
	{
		if(front==rear)
		return -1;

		
			int x=arr[front];
			arr[front]=-1;
			front++;
			if(front==rear)
			front=rear=0;
			return x;
		
	}
};


Stack implementation using queue:

class MyStack {
    queue<int>q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
      int size=q.size();
      q.push(x);
      while(--size>=0){
          q.push(q.front());
          q.pop();
      }  
    }
    
    int pop() {
        int x=q.front();
        q.pop();
        return x;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};


Queue implementation using stack:

class MyQueue {
    stack<int>st1;
    stack<int>st2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
        st1.push(x);
    }
    
    int pop() {
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        int x=st2.top();
        st2.pop();
        return x;
        
    }
    
    int peek() {
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        return st2.top();
    }
    
    bool empty() {
        return st1.empty() && st2.empty();
    }
};