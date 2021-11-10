package week10;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Adder {

	public static void main(String[] args) {
		Scanner scanner=new Scanner(System.in);
		String ori=scanner.nextLine();
		
		//+�� ������
		StringTokenizer stan=new StringTokenizer(ori,"+");
		
		int count=stan.countTokens();
		String token[]=new String[count];
	
		//���� �� ��� 
		for(int i=0;i<count;i++) 
			token[i] = stan.nextToken(); // ��ū ���
		
		//���� �� ����
		for(int i=0;i<count;i++)
			token[i] = token[i].trim(); // ��ū ���
		
		//string�� int�� ��ȯ
		int fin[]=new int[count];
		int sum=0;
		for(int i=0;i<count;i++) {
			fin[i]=Integer.parseInt(token[i]);
			sum+=fin[i];
		}
		//�հ� ���
		System.out.println("���� "+sum);
		scanner.close();
	}

}
