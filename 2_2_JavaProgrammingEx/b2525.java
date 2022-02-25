import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int A=sc.nextInt();
		int B=sc.nextInt();
		int C=sc.nextInt();//370
		int sum, no;		
		sum=C/60;//6
		no=C%60;//10
		
		A+=sum;
		B+=no;
		
		if(B>59) {
			sum=B/60;
			B=B%60;
			A+=sum;
		}
		A=A%24;
		
		System.out.println(A+" "+B);
		sc.close();
	}
}
