#include<bits/stdc++.h> 
using namespace std;
class Node{ 
public: 
	int data; 
	Node* next;

	Node(int val){
		data = val; 
		next = NULL; 
	} 
};  
void insert(int x,Node* head){
	Node* tmp = new Node(x); 
	if(head == NULL){
		head = tmp; 
	}
	else{
		Node * ptr = head; 
		while(ptr.next!=NULL){
			ptr = ptr.next; 
		}	
		ptr.next = tmp; 
	}

}int main(){



	return 0; 
}