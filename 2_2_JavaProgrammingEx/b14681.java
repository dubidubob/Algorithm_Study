import java.util.Scanner;
import java.util.InputMismatchException;

public class Main {
	public static void main(String[] args) {
	Scanner scanner=new Scanner(System.in);
	try {
	int x=scanner.nextInt();
	int y=scanner.nextInt();
	
	if(x>0&&y>0)
		System.out.println("1");
	else if(x<0&&y>0)
		System.out.println("2");
	else if(x<0&&y<0)
		System.out.println("3");
	else if(x>0&&y<0)
		System.out.println("4");
	else
		System.out.println("0을 입력하지 마십시오");
	}catch(InputMismatchException e) {
		System.out.println("제대로 된 정수 입력!");
	}
	scanner.close();
	}
}
