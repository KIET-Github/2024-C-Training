package linkedList;
import java.util.ArrayList;
public class arrayListDemo {
	
	public static void main(String[] args) {
		ArrayList<Integer>list1=new ArrayList<>();
		System.out.println(list1.size());
		list1.add(14);
		list1.add(60);
		list1.add(30);
		System.out.println(list1.size());
		for(int i=0;i<list1.size();i++) {
			System.out.println(list1.get(i)+ " ");
		}
	}

}
