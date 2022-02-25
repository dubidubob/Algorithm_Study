import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int x = sc.nextInt();//
		int y = sc.nextInt();
		int w = sc.nextInt();// 가로 길이
		int h = sc.nextInt();// 세로 길이

		// (6,2) (10,3)

		int i = w - x;// 가로와 차이
		int j = h - y;// 세로와의 차이
		int min=x;
		if(min>y)
			min=y;
		if(min>i)
			min=i;
		if(min>j)
			min=j;
		System.out.println(min);
		sc.close();
	}

}
