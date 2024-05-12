import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

class Graphy{
	int node;//정점의 개수
	boolean visited[];
	boolean adjArray[][];
	int count;
	
	public Graphy(int n) {//생성자에서 배열 초기화 하는 방법
		this.node=n;
		visited =new boolean[n];
		adjArray=new boolean[n][n];
		count=0;
		}
	
	public void insert_edge(Graphy g, int start, int end) {//원래 노드-1 가공 후
		if(start>=g.node || end>=g.node) {
			System.out.println("그래프: 정점 번호 오류");
		}
		g.adjArray[start][end]=true;
		g.adjArray[end][start]=true;
	}
	
	public void dfs_mat(Graphy g, int v){
		g.visited[v]=true;
		for(int w=0;w<g.node;w++) {
			if((g.adjArray[v][w])&&!(visited[w])) {
				g.count++;
				dfs_mat(g,w);
			}
		}
	}
}

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		Graphy g= new Graphy(Integer.parseInt(bf.readLine()));
		StringTokenizer st;
		
		int num=Integer.parseInt(bf.readLine());
		for(int i=0;i<num;i++) {
			st=new StringTokenizer(bf.readLine());
			g.insert_edge(g, Integer.parseInt(st.nextToken())-1, Integer.parseInt(st.nextToken())-1);
		}
		
		g.dfs_mat(g, 0);
		System.out.println(g.count);

	}

}
