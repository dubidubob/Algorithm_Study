package week10;

public class RandomEx {
	public static void main(String[] args) {
		int n1, n2, n3 = 0;
		while (true) {
			n1 = (int) (Math.random() * 3 + 1); // 1~3������ ���� ���� �߻�
			n2 = (int) (Math.random() * 3 + 1); // 1~3������ ���� ���� �߻�
			n3 = (int) (Math.random() * 3 + 1); // 1~3������ ���� ���� �߻�
			System.out.println(n1 + " " + n2 + " " + n3);
			System.out.println();
			if (n1 == n2 && n1 == n3) {
				System.out.println("����");
				break;
			}

		}

	}
}
