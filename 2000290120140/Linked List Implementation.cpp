#include <iostream>

using namespace std;

struct node
{
    int data;
    node* next;
};

void print(node* n)
{
    int count=0;
    while(n!=NULL)
    {
    cout << n->data << endl;
    n=n->next;
    count++;
    }
}
// Insertion at front
void push(node** head_ref, int newData)
{
    node* newNode= new node();
    newNode->data= newData;
    newNode->next= *head_ref;
    *head_ref= newNode;
}
// Insertion in middle
void insert(node* prev_node, int newData)
{
    node* newNode= new node();
    newNode->data= newData;
    newNode->next= prev_node->next;
    prev_node->next= newNode;
}
// Deletion from middle
void deleteNode(node** head_ref, int key)
{
    node* prev, *temp;
    temp= *head_ref;
    
    if(temp!=NULL && temp->data==key)
    {
       *head_ref= temp->next;
       free(temp);
       return;
    }
    while(temp!=NULL && temp->data!=key)
    {
       prev= temp;
       temp= temp->next;
    }
    if(temp==NULL)
    {
      return;
    }
    prev->next= temp->next;
    free(temp);
}

int main()
{
    node* head= NULL;
    push(&head, 4);
    push(&head, 9);
    push(&head, 11);
    push(&head, 24);
    //print(head);
    //insert(head->next, 15);
    deleteNode(&head, 11);
    print(head);
}
