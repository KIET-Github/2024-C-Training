public class Linkedlist {
    public static void main(String[] args) {
        Linkedlist list = new Linkedlist();
        list.insertFirst(5);
        list.insertFirst(4);
        list.insertFirst(3);
        list.insertFirst(2);
        list.insertFirst(1);
        list.display();
        list.reorderList(list.head);
        list.display();
    }
    private int size;
    public Node head;
    private Node tail;

    public int getSize(){
        return size;
    }
    public Linkedlist(){
        this.size = 0;
    }
    Node temp;

    public void reorderList(Node head) {
        if (head.next == null)
            return;
        Node mid = middle(head);
        Node secondHead = reverse(mid); //stores head of the reversed part
        Node headFirst = head;
        Node temp;
        while (headFirst != null && secondHead != null) {
            temp = headFirst.next;
            headFirst.next = secondHead;
            headFirst = temp;

            temp = secondHead.next;
            secondHead.next = headFirst;
            secondHead = temp;
        }
        if(headFirst != null)
            headFirst.next = null;
    }
    public Node reverse(Node mid){
        Node prev = null;
        Node present = mid;
        Node next = present.next;
        while(present != null)
        {
            present.next = prev;
            prev = present;
            present = next;
            if(next != null){
                next = next.next;
            }
        }
        return prev;
    }

    public Node middle(Node head)
    {
        Node fast = head;
        Node slow = head;
        while(fast != null && fast.next != null)
        {
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }

    public void reverseRec(Node node)
    {
        if(node.next == null)
        {
            head = node;
            temp = node;
            return;
        }

        reverseRec(node.next);
        temp.next = node;
        temp = node;
        temp.next = null;
    }
    public void insertRec(int val, int index){
       head = insertRec(val, index, head);
    }
    private Node insertRec(int val, int index, Node node){
        if(index == 0)
        {
            Node newNode = new Node(val, node.next);
            size++;
            return newNode;
        }
        node.next = insertRec(val, --index, node.next);
        return node;
    }

    public void insertFirst(int val)
    {
        Node node = new Node(val);
        node.next = head;
        head = node;
        if(tail == null)
        {
            tail = head;
        }
        size++;
    }

    public void insertLast(int val)
    {
        Node node = new Node(val)
        tail.next = node;
        tail = node;
        size++;
    }

    public void insertAtIndex(int val, int index)
    {
        if(index == 0)
        {
            insertFirst(val);
            return;
        }
        else if(index == size)
        {
            insertLast(val);
            return;
        }
        Node temp = head;
        for(int i=1; i<index; i++)
        {
            temp = temp.next;
        }
        Node node = new Node(val, temp.next);
        temp.next = node;
        size++;
    }

    public int deleteFirst()
    {
        int val = head.val;
        head = head.next;
        size--;
        return val;
    }

    public int deleteLast(){
        if(size <= 1)
        {
           return deleteFirst();
        }
        Node temp = get(size-2);
        int val = tail.val;
        tail = temp;
        tail.next = null;
        size--;
        return val;
    }


    public int delete(int index)
    {
        if(index == 0)
        {
            return deleteFirst();
        }
        else if(index == (size - 1)){
            return deleteLast();
        }
        Node prev = get(index-1);
        int val = prev.next.val;
        prev.next = prev.next.next;
        return val;
    }

    public Node get(int index)
    {
        Node temp = head;
        for(int i=0; i<index; i++)
        {
            temp = temp.next;
        }
        return temp;
    }
    public void display()
    {
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.val + "->");
            temp = temp.next;
        }
        System.out.println("Null");
    }

    private static class Node{
        int val;
        Node next;

        public Node(int val){
            this.val = val;
        }
        public Node(int val, Node next){
            this.val = val;
            this.next = next;
        }
    }
}
