#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/*
n = 100,000
만들어야 하는 수열이 주어진다. stack

push
push_back : vector에 객체 삽입하는 함수
*/
int main()
{
	int N;
	cin >> N;
	vector<int> A(N, 0);
	vector<char> resultV;

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];//만들어야하는 수열
	}

	stack<int> myStack;
	int num = 1; //오름차순 수
	bool result = true;

	for (int i = 0; i < A.size(); i++)
	{
		int su = A[i]; //현재 수열의 수
		//현재 수열값 >=오름차순 자연수: 값이 같아질 때까지 push() 수행
		if (su >= num) {
			while (su >= num) {
				myStack.push(num++);
				resultV.push_back('+');//적을 때마다 char 배열에 + 넣기
			}
			//su==num일 때
			myStack.pop();
			resultV.push_back('-');
		}
		else 
		{
			int n = myStack.top(); //맨 위에 있는 거
			myStack.pop();
			if (n > su) 
			{
				cout << "NO";
				result = false;
				break;
			}
			else 
			{
				resultV.push_back('-');
			}
		}
	}
	if (result) {
		for (int i = 0; i < resultV.size(); i++)
		{
			cout << resultV[i] << '\n';
		}
	}
	return 0;
}