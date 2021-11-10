package week10;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Adder {

	public static void main(String[] args) {
		Scanner scanner=new Scanner(System.in);
		String ori=scanner.nextLine();
		
		//+로 나누기
		StringTokenizer stan=new StringTokenizer(ori,"+");
		
		int count=stan.countTokens();
		String token[]=new String[count];
	
		//나눈 거 담고 
		for(int i=0;i<count;i++) 
			token[i] = stan.nextToken(); // 토큰 얻기
		
		//공백 싹 제거
		for(int i=0;i<count;i++)
			token[i] = token[i].trim(); // 토큰 얻기
		
		//string을 int로 변환
		int fin[]=new int[count];
		int sum=0;
		for(int i=0;i<count;i++) {
			fin[i]=Integer.parseInt(token[i]);
			sum+=fin[i];
		}
		//합계 출력
		System.out.println("합은 "+sum);
		scanner.close();
	}

}
