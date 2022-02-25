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
	else { //data1�� ������ �ִ� node�� ���� �ٿ����Ѵ�.
		Search(root, data1, leftdata, rightdata);
	}
}

public int Search(Node root, char data1, char leftdata, char rightdata) {
	//root���� �����ؼ� ã�Ƴ����� ��. data1�� ������ �ִ°� Ȯ��
	//�ϴ� root�� �ִ°�? ������ ���̰� ������ ���� ��带 ����. ����? ������ �������� ����.
	if(root==null) {
		return 0;
	}
else if(root.data==data1) {//�̰� �ؿ� �ڽ� ��� ������ ���⿡ ����. ������ ����Ʈ���� ��������� �����̵�.
		if(leftdata!='.')
			root.left=new Node(leftdata);
		if(rightdata!='.')
			root.right=new Node(rightdata);	
	}
	else {
		Search(root.left, data1, leftdata, rightdata);//left ã�ƺ��� ������
		Search(root.right, data1, leftdata, rightdata);//right�� ã�ƺ���
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
