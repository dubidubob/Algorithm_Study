#include <iostream>
#include <string>
using namespace std;
 // C언어에서 문자 처리하는 법은 자바보다 쉽다...
int main()
{
    int t;
    cin >> t;
    for(int i = 0;i < t;i++)
    {
        int r;
        string p;
        cin >> r;
        cin >> p;
 
        for(int j = 0;j < p.length();j++)
        {
            for(int k = 0;k < r;k++)
            {
                cout << p[j];
            }
        }
        cout << endl;
    }
    return 0;
}