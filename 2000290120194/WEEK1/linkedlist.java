#LINKEDLIST IMPLEMENTATION


class Node {
    int data;
    Node next;

    public Node(int data) {
        this.data = data;
        this.next = null;
    }
}

class LinkedList {
    Node head;

    public LinkedList() {
        this.head = null;
    }

    // Insertion at the end of the list
    public void insert(int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
        } else {
            Node current = head;
            while (current.next != null) {
                current = current.next;
            }
            current.next = newNode;
        }
    }

    // Insertion at the beginning of the list
    public void insertAtBeginning(int data) {
        Node newNode = new Node(data);
        newNode.next = head;
        head = newNode;
    }

    // Insertion at a specific position in the list
    public void insertAtPosition(int data, int position) {
        if (position < 0) {
            throw new IllegalArgumentException("Position cannot be negative.");
        }

        if (position == 0) {
            insertAtBeginning(data);
            return;
        }

        Node newNode = new Node(data);
        Node current = head;
        for (int i = 0; i < position - 1; i++) {
            if (current == null) {
                throw new IndexOutOfBoundsException("Position exceeds the size of the list.");
            }
            current = current.next;
        }

        newNode.next = current.next;
        current.next = newNode;
    }

    // Deletion of a node with given data value
    public void delete(int data) {
        if (head == null) {
            return;
        }

        if (head.data == data) {
            head = head.next;
            return;
        }

        Node current = head;
        while (current.next != null) {
            if (current.next.data == data) {
                current.next = current.next.next;
                return;
            }
            current = current.next;
        }
    }

    // Display the linked list
    public void display() {
        Node current = head;
        while (current != null) {
            System.out.print(current.data + " ");
            current = current.next;
        }
        System.out.println();
    }
}

public class Main {
    public static void main(String[] args) {
        LinkedList linkedList = new LinkedList();

        linkedList.insert(1);
        linkedList.insert(2);
        linkedList.insert(3);

        linkedList.display(); // Output: 1 2 3

        linkedList.insertAtBeginning(0);
        linkedList.display(); // Output: 0 1 2 3

        linkedList.insertAtPosition(4, 4); // Inserting 4 at index 4 (which is out of range)
        // Output: IndexOutOfBoundsException: Position exceeds the size of the list.

        linkedList.insertAtPosition(4, 3); // Inserting 4 at index 3
        linkedList.display(); // Output: 0 1 2 4 3

        linkedList.delete(2);
        linkedList.display(); // Output: 0 1 4 3
    }
}

