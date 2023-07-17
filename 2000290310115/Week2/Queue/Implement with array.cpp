#include<bits/stdc++.>
using namespace std;
#define max 10

int queue[max];
int front=-1;
int rear=-1;

void enqueue()
{
    int item;
    cout<<"Enter the value to enter : ";
    cin>>item;
    if(rear==max-1)
    {
        cout<<"Queue is full";
    }
    else if(rear==-1)
    {
        rear++;
        front++;
        queue[rear]=item;
    }
    else
    {
        queue[++rear]=item;
    }


}

void dequeue()
{
    if(front==-1 || front==rear+1)
    {
       cout<<"Queue is empty already ";
    }
    else
    {
        front++;
    }
}

void display()
{
    if(front==-1 || front==rear+1)
    {
        cout<<"Queue is empty "
    }
    else{
        cout<<"Our queue is :";
    for(int i=front;i<=rear;i++)
    {
        cout<<queue[i];
    }
    }
}
int main()
{
    int choice;
    while (1)
    {
        cout<<"1. Insert ";
        cout<<"2. Delete ";
        cout<<"3. traverse all data ";
        cout<<"4. exit ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4: exit(1);
        
        default:
            break;
        }


    }
return 0;    
}
