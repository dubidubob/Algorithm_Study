package week10;

public class RandomEx {
	public static void main(String[] args) {
		int n1, n2, n3 = 0;
		while (true) {
			n1 = (int) (Math.random() * 3 + 1); // 1~3까지의 랜덤 정수 발생
			n2 = (int) (Math.random() * 3 + 1); // 1~3까지의 랜덤 정수 발생
			n3 = (int) (Math.random() * 3 + 1); // 1~3까지의 랜덤 정수 발생
			System.out.println(n1 + " " + n2 + " " + n3);
			System.out.println();
			if (n1 == n2 && n1 == n3) {
				System.out.println("성공");
				break;
			}

		}

	}
}
