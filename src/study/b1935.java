package study;
import java.util.Scanner;

class ArrayStack{
	int top;
	float [] stack;
	int size;
	
	public ArrayStack(int size) {//생성자
		this.size=size;
		stack=new float[size];
		for(int i=0;i<size;i++)
			stack[i]=0;
		top=-1;
	}
	
	public void push(float item) {
		stack[++top]=item;
	}
	
	public float pop() {
		float ppo=stack[top];
		stack[top--]=0;
		return(ppo);
	}
}


public class b1935 {

	public static void main(String[] args){
		Scanner scanner=new Scanner(System.in);
		int size=scanner.nextInt();

		ArrayStack stac =new ArrayStack(100);//스택 생성
		
		String express=scanner.next();//식 받아서 저장
		char [] expe=new char[express.length()];
		for (int i=0;i<express.length();i++) {
			expe[i]=(express.charAt(i));
		}
		
		float [] num=new float[size];//대응 값 배열
		for(int i=0;i<size;i++)
			num[i]=(float)scanner.nextInt();
		
		for(int i=0;i<express.length();i++) {
			if((int)expe[i]>=65&&(int)expe[i]<=90) {
				int a=((int)expe[i]-65);//0
				stac.push(num[a]);
				}
			else if(expe[i]=='+')
				stac.push(stac.pop()+stac.pop());
			else if(expe[i]=='-')
				stac.push(-stac.pop()+stac.pop());
			else if(expe[i]=='*')
				stac.push(stac.pop()*stac.pop());
			else if(expe[i]=='/')
				stac.push(1/(stac.pop()/stac.pop()));			
			}
		
		System.out.printf("%.2f",stac.pop());

	}

}
