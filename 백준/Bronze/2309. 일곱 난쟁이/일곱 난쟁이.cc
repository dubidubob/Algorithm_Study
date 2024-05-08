#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int shorts[9] = { 0, };
    //난쟁이 총 키 합
    int sum = 0;

    //전부 저장 및 더한 뒤
    for (int &num : shorts)
    {
        cin >> num;
        sum += num;
    }
    //배열 정렬
    sort(shorts, shorts + 9);
    
    //9C2 해서 빼보기, 100일 때 종료
    for (int i = 0; i < 8; i++)
    {
        for (int j = i + 1; j < 9; j++)
        {
            if (sum - (shorts[i] + shorts[j]) == 100) {
                for (int k = 0; k < 9; k++)
                {
                    //||인지, &&인지
                    if (k != i && k != j)
                        cout << shorts[k] << "\n";
                }
                //return 까먹지 말기
                return 0;
            }
        }
    }
    return 0;
}
