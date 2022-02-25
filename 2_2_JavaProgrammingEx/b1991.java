package study;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
/*ctrl shift o*/

class Node{
	char data;
	Node left;
	Node right;
	public Node(char data) {
		this.data=data;
	}
}

class Tree{
	public Node root;
	
public void makeNode(char data1, char leftdata, char rightdata) {
	if(root==null) {
		root=new Node(data1);
		if(leftdata!='.')
			root.left=new Node(leftdata);
		if(rightdata!='.')
			root.right=new Node(rightdata);
	}
	else { //data1을 가지고 있는 node에 갖다 붙여야한다.
		Search(root, data1, leftdata, rightdata);
	}
}

public int Search(Node root, char data1, char leftdata, char rightdata) {
	//root에서 시작해서 찾아나가는 것. data1을 가지고 있는가 확인
	//일단 root에 있는가? 있으면 붙이고 없으면 왼쪽 노드를 본다. 없다? 없으면 오른쪽을 본다.
	if(root==null) {
		return 0;
	}
else if(root.data==data1) {//이고 밑에 자식 노드 없으면 여기에 붙임. 있으면 이진트리는 덮어씌워지며 엉망이됨.
		if(leftdata!='.')
			root.left=new Node(leftdata);
		if(rightdata!='.')
			root.right=new Node(rightdata);	
	}
	else {
		Search(root.left, data1, leftdata, rightdata);//left 찾아보고 없으면
		Search(root.right, data1, leftdata, rightdata);//right도 찾아봐라
	}
	return 0;
	
}


public void inorder(Node node) {
	if(node !=null) {
		inorder(node.left);
		System.out.print(node.data);
		inorder(node.right);		
	}
}
public void preorder(Node node) {
	if(node!=null) {
		System.out.print(node.data);
		preorder(node.left);
		preorder(node.right);
	}
}
public void postorder(Node node) {
	if(node!=null) {
		postorder(node.left);
		postorder(node.right);
		System.out.print(node.data);
	}
}

}


public class b1991 {

	public static void main(String[] args) throws IOException {
		
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		Tree t=new Tree();
		int num=Integer.parseInt(bf.readLine());
		for(int i=0;i<num;i++) {
			char array[]=bf.readLine().replace(" ", "").toCharArray();
			t.makeNode(array[0], array[1], array[2]);	
		}
		t.preorder(t.root);
		System.out.println();
		t.inorder(t.root);
		System.out.println();
		t.postorder(t.root);
		
		bf.close();

	}

}
