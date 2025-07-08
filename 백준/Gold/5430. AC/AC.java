import java.util.*;
import java.io.*;


public class Main {

    public static void func(BufferedReader br) throws IOException {
        String word = br.readLine();
        int n = Integer.parseInt(br.readLine());
        String arrays = br.readLine();

        Deque<Integer> dq = new ArrayDeque<>();

        // 배열 파싱
        StringBuilder numStr = new StringBuilder();
        for (char ch : arrays.toCharArray()) {
            if (Character.isDigit(ch)) {
                numStr.append(ch);
            } else if (numStr.length() > 0) {
                dq.addLast(Integer.parseInt(numStr.toString()));
                numStr.setLength(0);
            }
        }

        boolean isRev = false;

        for (char ch : word.toCharArray()) {
            if (ch == 'R') {
                isRev = !isRev;
            } else if (ch == 'D') {
                if (dq.isEmpty()) {
                    System.out.println("error");
                    return;
                }
                if (isRev) dq.pollLast();
                else dq.pollFirst();
            }
        }

        // 결과 출력
        StringBuilder sb = new StringBuilder();
        sb.append('[');
        if (isRev) {
            Iterator<Integer> it = dq.descendingIterator();
            while (it.hasNext()) {
                sb.append(it.next());
                if (it.hasNext()) sb.append(',');
            }
        } else {
            Iterator<Integer> it = dq.iterator();
            while (it.hasNext()) {
                sb.append(it.next());
                if (it.hasNext()) sb.append(',');
            }
        }
        sb.append(']');
        System.out.println(sb);
    }

    public static void main(String[] args) throws IOException {
        // 빠른 입출력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            func(br);
        }
    }
}
