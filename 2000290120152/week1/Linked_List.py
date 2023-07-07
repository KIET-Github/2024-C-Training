# SHIVANSHU SINGH
# Linked List implementation

class node:
    def __init__(self,data=None):
        self.data=data
        self.next=None
        
class linkedlist:
    def __init__(self):
        self.head=None
    def display(self):
        p=self.head
        while(p is not None):
            print(p.data,end=" ")
            p=p.next
        print()
    def addatbeg(self,val):
        newnode=node(val)
        p=self.head
        newnode.next=p
        self.head=newnode
    def addatend(self,val):
        newnode=node(val)
        p=self.head
        while(p.next is not None):
            p=p.next
        p.next=newnode
    def addatkth(self,val,pos):
        newnode=node(val)
        p=self.head
        idx=0
        while(idx<pos-1):
            p=p.next
            idx+=1
        newnode.next=p.next
        p.next=newnode
        
    def delete(self,pos):
        p=self.head
        q=self.head
        if(pos==0):
            p=p.next
        idx=0
        while(idx<pos):
            p=p.next
            if(idx<pos-1):
                q=q.next
            idx+=1
        if(p.next is None):
            q.next=None
        else:
            q.next=p.next
    def reverse(self):
        cur=self.head
        nxt=None
        prev=None
        while(cur is not None):
            nxt=cur.next
            cur.next=prev
            prev=cur
            cur=nxt
        self.head=prev
    def pairswap(self):
        p=self.head
        while(p is not None and p.next is not None):
            p.data,p.next.data=p.next.data,p.data
            p=p.next.next
            
      
first=node('a')
second=node('b')
third=node('c')

l1=linkedlist()
l1.head=first
first.next=second
second.next=third

l1.addatbeg('x')
l1.addatend('y')
l1.addatkth('f',3)
l1.delete(2)

l1.display()
l1.reverse()
l1.display()
l1.pairswap()
l1.display()

# print(l1.head.data)


