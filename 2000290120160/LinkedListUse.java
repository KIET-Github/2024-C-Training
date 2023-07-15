package linkedList;
import java.util.Scanner;

public class LinkedListUse {
	
	public static Node<Integer> takeInput(){
		
	
	Node<Integer>head=null;
	Scanner sc=new Scanner(System.in);
	int data=sc.nextInt();
	
	while(data!=-1) {
		Node<Integer> newNode=new Node<Integer>(data);
		if(head==null) {
			head=newNode;
		}
		else {
			Node<Integer>temp=head;
			while(temp.next!=null) {
				temp=temp.next;
			}
			temp.next=newNode;
		}
		data=sc.nextInt();
	}
	return head;
	}
	public static void print(Node<Integer>head) {
		while(head!=null) {
			System.out.print(head.data+" ");
			head=head.next;
		}
		System.out.println();
	}
	public static void insert(Node<Integer> head, int data, int pos) {
		Node<Integer>newNode=new Node<Integer>(data);
		if(pos==0) {
			newNode.next=head;
			return;
		}
		int i=0;
		Node<Integer> temp=head;
		while(i<pos-1) {
			temp=temp.next;
			i++;
		}
		newNode.next=temp.next;
		temp.next=newNode;
		
		
	}
	public static void main(String[] args) {
		Node<Integer> head=takeInput();
		insert(head, 50,3);
		print(head);
	}
}
	
	
	