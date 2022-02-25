package study;

//실패함 왜?
import java.util.Scanner;

class Node2 {
	int data;
	Node2 parent;
	Node2 left;
	Node2 right;

	public Node2(int data) {
		this.data = data;
	}
}

class Tree2 {
	public Node2 root;

	public void makeNode2(int parent, int child) {
		System.out.println("tlfgo");
		if (root == null) {
			root = new Node2(parent);
			if (root.left == null) {
				root.left = new Node2(child);
				root.left.parent = root;
				System.out.println(root.left.parent.data);
			}

			else {
				root.right = new Node2(child);
				root.right.parent = root;
				System.out.println(root.right.parent.data);
			}

		} else
			searchNode2(root, parent, child);
	}

	public int searchNode2(Node2 node, int parent, int child) {
		System.out.println("asdf");
		if (node == null)
			return 0;
		
		else if (node.data == parent) {
			System.out.println("fda");
			if (node.left == null) {
				node.left = new Node2(child);
				node.left.parent = node;
				System.out.println("fffff");
				return 0;
			}

			else {
				node.right = new Node2(child);
				node.right.parent = node;
				return 0;
			}

		}

		else if (node.data == child) {
			if (node.left == null) {
				node.left = new Node2(parent);
				node.left.parent = node;

			}

			else {
				node.right = new Node2(parent);
				node.right.parent = node;
			}
			return 0;

		} 
		
		else {
			searchNode2(node.left, parent, child);
			searchNode2(node.right, parent, child);
		}

		return 0;

	}

	public int search2Node2(Node2 node, int data) {
		if (node.data == data) {
			System.out.println(node.parent.data);
			return 0;
		} else {
			search2Node2(node.left, data);
			search2Node2(node.right, data);
		}
		return 0;
	}
}

public class b11725 {

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		Tree2 t2 = new Tree2();
		int num = s.nextInt();

		for (int i = 1; i < num; i++) {
			int a1 = s.nextInt();
			int a2 = s.nextInt();
			System.out.println(a1 + " " + a2);
			t2.makeNode2(a1, a2);
		}
		System.out.println("oroo");

		for (int i = 1; i < num; i++)
			t2.search2Node2(t2.root, i + 1);

		s.close();

	}

}
