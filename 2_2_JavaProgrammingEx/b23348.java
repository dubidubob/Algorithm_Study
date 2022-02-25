import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		
		int A=sc.nextInt();
		int B=sc.nextInt();
		int C=sc.nextInt();
		
		int N=sc.nextInt();
		int Aarray[]=new int[3*N];
		int Barray[]=new int[3*N];
		int Carray[]=new int[3*N];
		
		for(int i=0;i<3*N;i++) {
			Aarray[i]=sc.nextInt();
			Barray[i]=sc.nextInt();
			Carray[i]=sc.nextInt();
		}
		
		//입력 단계
		
		int max=0;
		int sum=0;
		int i=0;
		
		for(;i<3*N;i++) {
			sum+=Aarray[i]*A+Barray[i]*B+Carray[i]*C;
			if((i+1)%3==0) {
				if(max<sum)
					max=sum;
				sum=0;
			}
		}
		System.out.println(max);
		sc.close();
		
	}
}
