#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;

        //constructor
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }

        //destructor
        ~Node()
        {
            int val = this->data;
            //memory free
            if(this->next != NULL) // checkiing the node we want to delete is pointing to NULL else we will point it to NULL
            {
                this->next = NULL;
                delete next;
            }
            cout << "Memory is free for node with data " << val << endl;
        }
};

void printLinkedList(Node* &head)
{   
    if(head == NULL)
    {
        cout << "Linked List is Empty" << endl;
        return;
    }

    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp->data <<"->";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtStart(Node* &head, Node* &tail, int data)
{   
    if(head == NULL) // if head is NULL creating new node
    {
        Node* temp = new Node(data);
        temp->next = NULL;
        head = temp;
        tail = temp;
    }
    else
    {
        Node* temp = new Node(data); // creating new node
        temp->next = head;
        head = temp;
    }
}

void insertAtTail(Node* &tail, Node* &head, int data)
{   
    if(tail == NULL)
    {
        Node* temp = new Node(data);
        temp->next = NULL;
        tail = temp;
        head = temp;
    }
    else
    {
        Node* temp = new Node(data); // creating new node
        tail->next = temp;
        tail = temp;
    }
}

void insertAtPosition(Node* &head, Node* &tail, int position, int data)
{
    int n = 1;
    Node* ptr = head; // pointer to traverse

    while(n < position - 1)
    {
        ptr = ptr->next;
        n++;
    }

    if(position == 1) // case for insert at head
    {
        insertAtStart(head,tail,data);
        return;
    }
    else if(ptr->next == NULL) // case for insert at tail
    {
        insertAtTail(tail,head,data);
        return;
    }
    else // case for insert in middle of any nodes
    {
        Node* nodeToInsert = new Node(data);
        nodeToInsert->next = ptr->next;
        ptr->next = nodeToInsert;
    }
}

void deleteNode(Node* &head, Node* &tail, int position)
{
    Node* prev = NULL;
    Node* curr = head;
    int ct = 1;
    while(ct < position)
    {
        prev = curr;
        curr = curr->next;
        ct++;
    }

    if(position == 1) // deleting the head node
    {   
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else if(curr->next == NULL) // deleting the last node
    {   
        prev->next = curr->next;
        tail = prev;
        delete curr;
    }
    else // deleting the middle node
    {
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    printLinkedList(head);

    // insert a node at head
    insertAtStart(head,tail,2);
    printLinkedList(head);

    // //insert a node at tail
    insertAtTail(tail,head,3);
    printLinkedList(head);

    // //insert at any position
    insertAtPosition(head,tail,2,4);
    printLinkedList(head);

    // //delete the node
    deleteNode(head,tail,1);
    printLinkedList(head);
    cout << "Head = " << head->data << endl;
    cout << "Tail = " << tail->data << endl;

    return 0;
}
