import java.util.Scanner;
import java.util.LinkedList;

public class b10104 {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		int num = scanner.nextInt();// 인원 받음
		int time = scanner.nextInt();// 횟수 받음

		LinkedList<Integer> survive = new LinkedList<Integer>();
		for (int i = 1; i <= num; i++)// 인원 순서대로 넣기
			survive.add(i);

		for (int i = 0; i < time; i++) {// 몇번 돌겠다 한만큼
			int a = scanner.nextInt();// a는 배수가 되는 수
			while (true) {
				int b = (num / a) * a;// b는 인원 수 중 가장 높은 a의 배수
				if (b <= 0)// b가 0이 되면 index가 -1일이 되므로 빠져나가기
					break;
				survive.remove(b - 1);// 최대 큰 배수-1 인덱스를 제거
				num = num - a;// 가장 큰 배수의 다음 큰 수가 나오겠금 조절

			}
			num = survive.size();// 원래 크기로 다시 갱신
		}

		for (int i = 0; i < survive.size(); i++) {// 링크드 리스트 출력
			System.out.print(survive.get(i) + " ");

		}
		scanner.close();
	}

}
