#include <iostream>

using namespace std;

struct Node {
  int data;
  Node* next;
};

Node* createNode(int data) {
  Node* newNode = new Node();
  newNode->data = data;
  newNode->next = nullptr;
  return newNode;
}

void insertNode(Node* head, int data) {
  Node* newNode = createNode(data);
  if (head == nullptr) {
    head = newNode;
  } else {
    Node* ptr = head;
    while (ptr->next != nullptr) {
      ptr = ptr->next;
    }
    ptr->next = newNode;
  }
}

void deleteNode(Node* head, int data) {
  if (head == nullptr) {
    return;
  }

  if (head->data == data) {
    Node* temp = head;
    head = head->next;
    delete temp;
    return;
  }

  Node* prev = head;
  Node* curr = head->next;
  while (curr != nullptr && curr->data != data) {
    prev = curr;
    curr = curr->next;
  }

  if (curr == nullptr) {
    return;
  }

  prev->next = curr->next;
  delete curr;
}

void printList(Node* head) {
  Node* ptr = head;
  while (ptr != nullptr) {
    cout << ptr->data << " ";
    ptr = ptr->next;
  }
  cout << endl;
}

int main() {
  Node* head = nullptr;
  insertNode(head, 10);
  insertNode(head, 20);
  insertNode(head, 30);
  printList(head);

  deleteNode(head, 20);
  printList(head);

  return 0;
}
