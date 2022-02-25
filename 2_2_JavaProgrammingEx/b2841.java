package study;
import java.util.EmptyStackException;
import java.util.Scanner;

class Stack<T>{
	class Node<T>{
		private int data;
		private Node<T> next;
		
		public Node(int data) {
			this.data=data;
		}
	}
	
	private Node<T> top;
	
	public int pop() {
		if (top ==null) {
			throw new EmptyStackException();
		}
		
		int item=top.data;
		top=top.next;
		return item;
	}
	
	public void push(int item) {
		Node<T> t=new Node<T>(item);
		t.next=top;
		top=t;
	}
	
	public int peek() {
		if(top == null) {
			throw new EmptyStackException();
		}
		return top.data;
		}
	
	public int melody(int a, int b, int ct) {
	if(a<b) {
		push(b);
		return ++ct;
	}
	
	else if(a>b) {
		int d=pop();
		++ct;
		ct=melody(peek(),b,ct);
	}
	
	return ct;
		
	}


	
}

public class b2841 {

	public static void main(String[] args) {
		
		Scanner scanner=new Scanner(System.in);
		
		int count=0;//손가락 움직인 횟수
		int num=scanner.nextInt();
		int p=scanner.nextInt();
		
		Stack<Integer>[] stack=new Stack[7];
		for(int i=1;i<=6;i++) {
			stack[i]=new Stack<Integer>(); //객체 생성
			stack[i].push(0);//데이터를 0으로 초기화
		}
		
		for(int i=1;i<=num;i++) {
			int a=scanner.nextInt();
			int b=scanner.nextInt();
			
			count= stack[a].melody(stack[a].peek(), b, count);
		}
		
		System.out.println(count);
		scanner.close();
	}

}
