#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* prev;
        Node* next;

        //constructor
        Node(int data)
        {
            this->data = data;
            this->prev = NULL;
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
                this->prev = NULL;
                delete next;
                delete prev;
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

    Node* ptr = head; // pointer to traverse the linked list
    while(ptr != NULL)
    {
        cout << ptr->data << "->";
        ptr = ptr->next;
    }
    cout << endl;
}

void insertAtHead(Node* &head, Node* &tail, int data)
{   
    if(head == NULL)
    {
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else
    {
        Node* temp = new Node(data);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtTail(Node* &tail, Node* &head, int data)
{   
    if(tail == NULL)
    {
        Node* temp = new Node(data);
        tail = temp;
        head = temp;
    }
    else
    {
        Node* temp = new Node(data);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtPosition(Node* &head, Node* &tail, int position, int data)
{
    Node* ptr = head;

    int ct = 1;
    while(ct < position - 1)
    {   
        ptr = ptr->next;
        ct++;
    }

    if(position == 1)
    {
        insertAtHead(head,tail,data);
        return;
    }
    else if(ptr->next == NULL)
    {
        insertAtTail(tail,head,data);
        return;
    }
    else
    {   
        Node* nodeToInsert = new Node(data);

        nodeToInsert->next = ptr->next;
        ptr->next = nodeToInsert;
        nodeToInsert->prev = ptr;
        ptr->next->prev = nodeToInsert;
    }
}

void deleteNode(Node* &head, Node* &tail, int position)
{   
    int ct = 1;
    Node* prev = NULL;
    Node* curr = head;

    while(ct < position)
    {
        prev = curr;
        curr = curr->next;
        ct++;
    }

    if(head == NULL)
        cout << "Cannot delete, List is Empty" << endl;
    else if(position == 1) // deleting the first node
    {
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        temp->prev = NULL;
        delete temp;
    }
    else if(curr->next == NULL) // deleting the last node of linked list
    {   
        prev->next = NULL;
        curr->prev = NULL;
        tail = prev;
        delete curr;
    }
    else // deleting any middle node
    {
        prev->next = curr->next;
        curr->next->prev = prev;
        curr->next = NULL;
        curr->prev = NULL;
        delete curr;
    }
}

int main()
{   
    Node* head = NULL;
    Node* tail = NULL;

    printLinkedList(head);
    deleteNode(head,tail,1);

    // insert at head
    insertAtHead(head,tail,2);
    printLinkedList(head);

    // insert at tail
    insertAtTail(tail,head,3);
    printLinkedList(head);

    // //insert at any position
    insertAtPosition(head,tail,1,6);
    printLinkedList(head);

    //delete Node
    deleteNode(head,tail,3);
    printLinkedList(head);
    cout << "Head = " << head->data << endl;
    cout << "Tail = " << tail->data << endl;

    return 0;
}