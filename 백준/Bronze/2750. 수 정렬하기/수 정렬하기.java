import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int n=Integer.parseInt(br.readLine());//들어오는 글자 수
		int[] numArray=new int[n];//숫자를 받을 배열
		for(int i=0;i<n;i++) {
			numArray[i]=Integer.parseInt(br.readLine());
		}
		
		Arrays.sort(numArray);
		for(int i=0;i<n;i++) {
			System.out.println(numArray[i]);
		}


	}

}
