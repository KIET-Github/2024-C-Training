#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;

        // constructor
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }

        // destructor
        ~Node()
        {
            int val = this->data;
            if(this->next != NULL)
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
        cout << "Linked List is Empty";
    else
    {
        Node* temp = head;
        // using do while loop so we handle the case when 1 node is present
        do
        {   
            cout << head->data << "->";
            head = head->next;
        }while (head != temp);
    }
    cout << endl;
}

void insertNode(Node* &head, int find, int data)
{   
    // List is Empty
    if(head == NULL)
    {
        Node* temp = new Node(data);
        head = temp;
        temp->next = temp;
        return;
    }
    // List is not empty
    // Assuming the find element is present in Linked List and Inserting after Find element
    else
    {
        Node* curr = head;
        while(curr->data != find)
        {
            curr = curr->next;
        }
        Node* temp = new Node(data); // creating new node
        temp->next = curr->next;
        curr->next = temp;
        return;
    }
    cout << endl << "Element is not present in the Linked List" << endl;
}

void deleteNode(Node* &head, int del)
{
    if(head == NULL)
    {
        cout << "Cannot delete, Linked List is Empty" << endl;
        return;
    }
    else
    {   
        Node* prev = head;
        Node* curr = head->next;

        // if only 1 Node is present
        if(prev == curr)
        {
            head = NULL;
        }

        while(curr->data != del)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;

        // if two or more than two nodes are present
        if(head == curr )
        {
            head = prev->next;
        }
        delete curr;
    }
}

int main()
{   
    Node* head = NULL;
    printLinkedList(head);

    insertNode(head,1,1);
    printLinkedList(head);
    // deleteNode(head,1);

    insertNode(head,1,2);
    printLinkedList(head);

    insertNode(head,2,3);
    printLinkedList(head);

    insertNode(head,3,4);
    printLinkedList(head);

    deleteNode(head,2);
    printLinkedList(head);

    return 0;
}