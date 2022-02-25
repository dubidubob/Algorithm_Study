package study;

import java.util.Scanner;
import java.util.LinkedList;

public class b2605 {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		int num = scanner.nextInt(); // �ο� �� �ޱ�
		int[] rnd = new int[num]; // �迭 ���� �� ����

		LinkedList<Integer> order = new LinkedList<Integer>();// linked list ���� �� ����
		for (int i = 0; i < num; i++) {// �ο� �� ���� ������

			rnd[i] = scanner.nextInt();// ���� ��ȣ ǥ �̰�
			// �̵��� �ϳ� �� �ϳ��� ����
			if (rnd[i] == 0)
				order.add(i + 1);// ���ڸ�, �ε��� �Լ� �ʿ� ����!
			else
				order.add(order.size() - rnd[i], i + 1);// �ε��� �ʿ�
		}

		for (int i = 0; i < num; i++) {// ��ũ�� ����Ʈ ���
			System.out.print(order.get(i) + " ");
		}

		scanner.close();

	}

}
