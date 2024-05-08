#include <iostream>
using namespace std;

int main() 
{
	//int 배열을 만들어서, 해당 문자가 나왔으면 count++
	string word;
	int alphabet[26] = {0,};
	int translate;

	cin >> word;
	for (int i=0; i < word.size(); i++)
	{
		translate = word[i] - 'a';
		alphabet[translate]++;
	}

	for (int i = 0; i < sizeof(alphabet)/sizeof(*alphabet); i++)
	{
		cout << alphabet[i] << " ";
	}
	return 0;
}