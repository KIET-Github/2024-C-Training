#SHIVANSHU SINGH 2000290120152
#1. STACK IMPLEMENTATION

class Stack:
    def __init__(self, size):
        self.stack = list()
        self.maxSize = size
        self.top = 0
        
    def push(self,data):
        if len(self.stack)>=self.maxSize:
            print("Stack Overflow!!")
            return 
        self.stack.append(data)
        self.top += 1
        
    def pop(self):
        if len(self.stack)==0:
            return ("Stack is Empty!!")
        item = self.stack.pop()
        self.top -= 1
        return item
        
    def display(self):
        if len(self.stack)==0:
            print("Empty Stack!!")
            return
        print(self.stack)
        

s = Stack(4)

s.push(1)
s.push(2)
s.push(3)
s.push(4)
s.push(5)
s.display()
print(s.pop()) 
print(s.pop()) 
print(s.pop()) 
print(s.pop()) 
print(s.pop()) 
print(s.pop()) 
s.display()

#--------------------------------2. QUEUE IMPLEMENTATION--------------

class Queue:
    def __init__(self):
        self.items = []
 
    def is_empty(self):
        return self.items == []
 
    def enqueue(self, data):
        self.items.append(data)
 
    def dequeue(self):
        return self.items.pop(0)
    
    def display(self):
        print(self.items)
        
        
        
q = Queue()

q.enqueue(1)
q.enqueue(2)
q.enqueue(3)
q.enqueue(4)
q.enqueue(5)

q.display()

q.dequeue()
q.dequeue()
q.dequeue()

q.display()

print(q.is_empty())
