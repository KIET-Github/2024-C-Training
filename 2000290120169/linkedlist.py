#creating linked list 
class node:
    def __init__(self,data):

        self.data=data
        self.next= None 
        
class Linkedlist:
    def __init__(self):
        self.head= None
    
    def listpr(self):
        printval=self.head
        while printval is not None:
            print(printval.data)
            printval=printval.next
    
    def addnode(self,newdata):

        newnode=node(newdata)
        newnode.next=self.head
        self.head=newnode

    def addlast(self,newdata):
        newnode=node(newdata)

        if self.head is None:
            self.head=newnode
            return
        last=self.head 
        while(last.next):
           last= last.next
        last.next=newnode

    def addspecific(self,prev_node,newdata):
        if prev_node is None:
            print('node does not exist')
            return
        newnode=node(newdata)
        newnode.next=prev_node.next
        prev_node.next=newnode

    def deleteNode(self, key):
 
        
        temp = self.head
 
    
        if (temp is not None):
            if (temp.data == key):
                self.head = temp.next
                temp = None
                return
 
        
        
        while(temp is not None):
            if temp.data == key:
                break
            prev = temp
            temp = temp.next
 
    
        if(temp == None):
            return
 
    
        prev.next = temp.next
 
        temp = None
              
l=Linkedlist()
l.head=node(int(input()))
a=node(int(input()))
b=node(int(input()))
c=node(int(input()))
d=node(int(input()))

l.head.next=a
a.next=b
b.next=c
c.next=d 
'''
print(a.next.data)
print(a.data)
print(l.head.data)
print(l.head.next.next.data)
'''
#adding node at beginning
l.addnode(int(input()))
l.addnode(int(input()))


#adding node at last
l.addlast(int(input()))
l.addlast(int(input()))

l.addspecific(a,int(input()))
l.addspecific(b,int(input()))
l.addspecific(c,int(input()))
l.deleteNode(int(input()))

l.listpr()