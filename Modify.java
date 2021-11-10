package week10;

import java.util.Scanner;

public class Modify {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		while (true) {
			System.out.print(">>");
			String s = scanner.nextLine(); // 사용자로부터 한 줄 읽기
			StringBuffer sb = new StringBuffer(s);
			// StringBuffer 객체 sb 생성
			if (sb.toString().equals("exit")) {
				System.out.println("종료합니다...");
				break;
			}
			int index = (int) (Math.random() * s.length());
			// 변경할 문자의 위치 선택
			while (true) {
				int i = (int) (Math.random() * 26);
				// 삽입할 문자를 26개 알파벳 중에서 선택
				char c = (char) ('a' + i); // 새로 삽입할 문자 결정
				if (sb.charAt(index) != c) {
					// StringBuffer 속의 문자와 삽입하는 문자가 다른 경우
// s의 index 위치에 있는 문자를 문자 c로 변경
					sb.replace(index, index + 1, Character.toString(c));
					break;
				}
			}
			System.out.println(sb);
		}
		scanner.close();
	}
}
