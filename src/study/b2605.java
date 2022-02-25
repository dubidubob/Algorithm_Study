package study;

import java.util.Scanner;
import java.util.LinkedList;

public class b2605 {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		int num = scanner.nextInt(); // 인원 수 받기
		int[] rnd = new int[num]; // 배열 선언 및 생성

		LinkedList<Integer> order = new LinkedList<Integer>();// linked list 선언 및 생성
		for (int i = 0; i < num; i++) {// 인원 수 동안 돌리기

			rnd[i] = scanner.nextInt();// 각자 번호 표 뽑고
			// 이동을 하나 안 하나가 기준
			if (rnd[i] == 0)
				order.add(i + 1);// 제자리, 인덱스 함수 필요 없음!
			else
				order.add(order.size() - rnd[i], i + 1);// 인덱스 필요
		}

		for (int i = 0; i < num; i++) {// 링크드 리스트 출력
			System.out.print(order.get(i) + " ");
		}

		scanner.close();

	}

}
