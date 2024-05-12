/*
 * 1. 단방향(u에서 v로 가는)
 * 2. 단방향 간선이 여러개
 * ㄴgraph에 저장할 때마다 가장 짧은 걸로 갱신*/
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
	static int V, E, start;
	static ArrayList<ArrayList<Node>> graph;

	static class Node {

		int idx, cost;
		/*
		 * Node(int idx) { this.idx = idx; this.cost = 0; }
		 */

		Node(int idx, int cost) {
			this.idx = idx;
			this.cost = cost;
		}
	}

	public static void main(String[] args) throws IOException {
		// 초기화
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		V = Integer.parseInt(st.nextToken());
		E = Integer.parseInt(st.nextToken());
		start = Integer.parseInt(br.readLine());
		graph = new ArrayList<ArrayList<Node>>();
		for (int i = 0; i < V + 1; i++) {
			graph.add(new ArrayList<Node>());
		}
		for (int i = 0; i < E; i++) {
			st = new StringTokenizer(br.readLine());
			int u = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
			int w = Integer.parseInt(st.nextToken());
			
			
			graph.get(u).add(new Node(v, w));
			
			/*try {
				if (graph.get(u).get(v).cost > w)
					graph.get(u).get(v).cost = w;
				continue;
			}catch (IndexOutOfBoundsException e) {
					graph.get(u).add(new Node(v, w));
					throw e;*/
			}
			//System.out.println(u+"에서"+graph.get(u).get(v).idx+"로의 가중치"+graph.get(u).get(v).cost);

		
int[] dist = new int[V + 1];
		for (int i = 0; i < V + 1; i++) {
			dist[i] = Integer.MAX_VALUE;
		}

		PriorityQueue<Node> q = new PriorityQueue<Node>((o1, o2) -> Integer.compare(o1.cost, o2.cost));

		q.offer(new Node(start, 0));
		dist[start] = 0;
		while (!q.isEmpty()) {
			Node curNode = q.poll();

			if (dist[curNode.idx] < curNode.cost) {
				continue;
			}

			for (int i = 0; i < graph.get(curNode.idx).size(); i++) {
				Node nxtNode = graph.get(curNode.idx).get(i);

				if (dist[nxtNode.idx] > curNode.cost + nxtNode.cost) {
					dist[nxtNode.idx] = curNode.cost + nxtNode.cost;
					q.offer(new Node(nxtNode.idx, dist[nxtNode.idx]));
				}
			}
		}

		for(int i=1;i<V+1;i++) {
			if(dist[i]!=Integer.MAX_VALUE)
				System.out.println(dist[i]);
			else
				System.out.println("INF");
		}
	}

}
