/*
문제 분석
N개 숫자를 받자마자 더하기.
무조건 1자릿수
*/

#include <iostream>
using namespace std;

int main() 
{
	
	int N = 0;
	string input;

	cin >> N;
	cin >> input; 

	int output = 0;
	for (int i = 0; i < input.length(); i++) {
		output += input[i] - '0';
	}
	cout << output;
	return 0;
}

/*
1. char to int
[char 변수] - '0';

2. string to int
stoi([string 변수])
long, double, float : stol, stod, stof
*/