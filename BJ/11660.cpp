/*배열로 풀어봄
시간 초과 났다.*/

#include <iostream>
#include <vector>
using namespace std;

void inputMatrix(vector<vector<int>>& inputMat, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cin >> inputMat[i][j];
		}
	}
}

void inputPoints(vector<int>& points, int size) {
	for (int i = 0; i < size*4; i++) {
		cin >> points[i];
		points[i]--;
	}
}

int  sumUp(vector<vector<int>>& inputMat, vector<int>& points, int m) {
	int output = 0;

	//points[0] points[1] points[2] points[3]
	int x1 = points[4 * m];
	int y1 = points[4 * m + 1];
	int x2 = points[4 * m + 2];
	int y2 = points[4 * m + 3];
	
	for (int i = x1; i <= x2;i++) { //(2,2)(2,3)(3,2)(3,3)
		for (int j= y1;j<= y2;j++)
		{
			output += inputMat[i][j];
		}
	}
	return output;
}

int main()
{
	int N;
	int M;
	int output = 0;
	
	cin >> N; //표 크기
	cin >> M;//횟수 M

	vector<vector<int>> inputMat(N, vector<int>(N)); // N x N 크기의 2차원 vector 생성
	vector<int> points(M * 4);

	inputMatrix(inputMat, N); //2차 배열을 저장
	inputPoints(points, M); //포인트들을 저장

	for (int i = 0; i < M; i++) {		
		output=sumUp(inputMat, points, i);
		cout << output << "\n";
		output = 0;
	}
}
