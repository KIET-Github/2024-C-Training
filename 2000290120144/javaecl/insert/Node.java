package insert;

public class Node {
	int data;
	Node next;
	Node(int x)
	{
		data = x;
		next = null;
	}
class Test{
	static Node insertBegin(Node head , int x)
	{
	Node temp = new Node(x);
	temp.next = head;
	return temp;
	}
	
}
public static void displayList(Node head) {
    Node curr = head;
    while (curr != null) {
        System.out.print(curr.data + " ");
        curr = curr.next;
    }
    System.out.println();
}
	public static void main(String[] args) {
		
		Node head = null;
		head = Test.insertBegin(head , 30);
		head = Test.insertBegin(head , 20);
		head = Test.insertBegin(head , 10);
	    displayList(head);
	}
}

