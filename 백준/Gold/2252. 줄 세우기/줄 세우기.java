import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Queue;
import java.util.ArrayList;
import java.util.LinkedList;

public class Main {

	static int n, m;// vertex 수, edge 수

	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer(bf.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());

		int[] indegree = new int[n + 1];// 각 vertex에 대한 간접차수

		// arraylist를 이용한 graph 만들기
		ArrayList<ArrayList<Integer>> graph = new ArrayList<>();// arraylist를 인자로 갖는 arraylist
		for (int i = 0; i < n + 1; i++) {
			graph.add(new ArrayList<Integer>());// 안쪽 arraylist 생성/각 vertex의 edge를 연결할 수 있도록
		}

		for (int i = 0; i < m; i++) {
			st=new StringTokenizer(bf.readLine());
			int v1 = Integer.parseInt(st.nextToken());// 앞에 있어야하는 A
			int v2 = Integer.parseInt(st.nextToken());// 뒤에 있어야하는 B
			graph.get(v1).add(v2);// v1(<=n) 인덱스에 있는 곳에 v2를 넣어라
			indegree[v2]++;// 간접 차수 증가
		}

		// 위상정렬 알고리즘
		topologicalSort(indegree, graph);
	}

	static void topologicalSort(int[] indegree, ArrayList<ArrayList<Integer>> graph) {// arraylist: 삭제, 이동 연산이 없으니
		Queue<Integer> queue = new LinkedList();// https://stackoverflow.com/questions/21727873/queueinteger-q-new-linkedlistinteger

		for (int i = 1; i < n + 1; i++) {// acycle이니까 전부 순회하게 됨.
			if (indegree[i] == 0) {// 1. 간접 차수가 0이면 큐에 삽입
				queue.add(i);
			}
		}

		for (int i = 0; i < n; i++) {
			int v = queue.remove();// 2. 큐에서 간접 차수 0인 거 추출
			System.out.print(v + " ");

			// 3. 추출된 vertex와 연결된 모든 vertex의 간접 차수 -1
			for (int nextV : graph.get(v)) {// 향상된 for문, 배열
				indegree[nextV]--;
				// 4. 그중 간접차수 0인 vertex를 다시 큐에 넣기.
				if (indegree[nextV] == 0) {
					queue.add(nextV);
				}
			}

		}
	}

}
