//WEEK 1: Linked List Implementation :)

#include <bits/stdc++.h>
using namespace std;
//Creation of node

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        head = NULL;
    }

//Insertion of node
    void insertAtHead(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

  void insertAtTail(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

  void insertAtPosition(int data, int position) {
        if (position <= 0) {
            std::cout << "Invalid position." << std::endl;
            return;
        }
        if (position == 1 || head == NULL) {
            insertAtHead(data);
        } else {
            Node* newNode = new Node(data);
            Node* current = head;
            int count = 1;
            while (count < position - 1 && current != NULL) {
                current = current->next;
                count++;
            }
            if (current == NULL) {
                std::cout << "Invalid position." << std::endl;
                return;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

//Deletion of node
    void deleteAtPosition(int position) {
        if (position <= 0 || head == NULL) {
            std::cout << "Invalid position." << std::endl;
            return;
        }
        if (position == 1) {
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            Node* current = head;
            Node* prev = NULL;
            int count = 1;
            while (count < position && current != NULL) {
                prev = current;
                current = current->next;
                count++;
            }
            if (current == NULL) {
                std::cout << "Invalid position." << std::endl;
                return;
            }
            prev->next = current->next;
            delete current;
        }
    }

//Searching of a node
    bool search(int value) {
        Node* current = head;
        while (current != NULL) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

//Display the nodes

    void print() {
        Node* current = head;
        while (current != NULL) {
            std::cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList abc;
    abc.insertAtHead(1);
    abc.insertAtHead(2);

    abc.insertAtTail(4);
    abc.insertAtTail(3);

    abc.insertAtPosition(10, 2);
    abc.insertAtPosition(20, 3);

    abc.print(); 

    abc.deleteAtPosition(4);
    abc.deleteAtPosition(1);

    abc.print();  

    cout << abc.search(20) << endl; 
    cout << abc.search(1) <<endl; 

    return 0;
}
