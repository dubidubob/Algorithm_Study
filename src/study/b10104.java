package study;

import java.util.Scanner;
import java.util.LinkedList;

public class b10104 {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		int num = scanner.nextInt();// �ο� ����
		int time = scanner.nextInt();// Ƚ�� ����

		LinkedList<Integer> survive = new LinkedList<Integer>();
		for (int i = 1; i <= num; i++)// �ο� ������� �ֱ�
			survive.add(i);

		for (int i = 0; i < time; i++) {// ��� ���ڴ� �Ѹ�ŭ
			int a = scanner.nextInt();// a�� ����� �Ǵ� ��
			while (true) {
				int b = (num / a) * a;// b�� �ο� �� �� ���� ���� a�� ���
				if (b <= 0)// b�� 0�� �Ǹ� index�� -1���� �ǹǷ� ����������
					break;
				survive.remove(b - 1);// �ִ� ū ���-1 �ε����� ����
				num = num - a;// ���� ū ����� ���� ū ���� �����ڱ� ����

			}
			num = survive.size();// ���� ũ��� �ٽ� ����
		}

		for (int i = 0; i < survive.size(); i++) {// ��ũ�� ����Ʈ ���
			System.out.print(survive.get(i) + " ");

		}
		scanner.close();
	}

}
