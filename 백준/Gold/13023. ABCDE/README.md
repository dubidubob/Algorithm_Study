/*
오해 : N 노드 중 노드 5개가 연결되어 있는 유니온이 존재하는지 찾는 문제
이게 아님!
N 노드에서 끝까지 갔을 때 5번 끝까지 갈 수 있는지 찾는 문제

노드 수 N(2000)
엣지 수 M(2000)

O(V+E): 노드 최대 범위: 2000 O(V+E)=O(4000) 각 노드에 대해서 2000*4000=8000000
->제한 시간 내에 가능(2초 2억회까지 가능)
1. 인접리스트로 관계 전부 삽입
2. DFS 실행
	각 노드 타고 들어간 뒤, 다음 노드로 전환
	중요. count 함수로 관계 1 깊어질 때마다 업데이트 
		count == 5 일 시 1 출력 후 return
		아닐 시 continue, 마지막에 0 출력 후 return

인접리스트 구현 방법!

재귀함수의 return 값
*/

# [Gold V] ABCDE - 13023 

[문제 링크](https://www.acmicpc.net/problem/13023) 

### 성능 요약

메모리: 2192 KB, 시간: 52 ms

### 분류

백트래킹, 깊이 우선 탐색, 그래프 이론, 그래프 탐색

### 제출 일자

2024년 5월 16일 17:33:18

### 문제 설명

<p>BOJ 알고리즘 캠프에는 총 N명이 참가하고 있다. 사람들은 0번부터 N-1번으로 번호가 매겨져 있고, 일부 사람들은 친구이다.</p>

<p>오늘은 다음과 같은 친구 관계를 가진 사람 A, B, C, D, E가 존재하는지 구해보려고 한다.</p>

<ul>
	<li>A는 B와 친구다.</li>
	<li>B는 C와 친구다.</li>
	<li>C는 D와 친구다.</li>
	<li>D는 E와 친구다.</li>
</ul>

<p>위와 같은 친구 관계가 존재하는지 안하는지 구하는 프로그램을 작성하시오.</p>

### 입력 

 <p>첫째 줄에 사람의 수 N (5 ≤ N ≤ 2000)과 친구 관계의 수 M (1 ≤ M ≤ 2000)이 주어진다.</p>

<p>둘째 줄부터 M개의 줄에는 정수 a와 b가 주어지며, a와 b가 친구라는 뜻이다. (0 ≤ a, b ≤ N-1, a ≠ b) 같은 친구 관계가 두 번 이상 주어지는 경우는 없다.</p>

### 출력 

 <p>문제의 조건에 맞는 A, B, C, D, E가 존재하면 1을 없으면 0을 출력한다.</p>

