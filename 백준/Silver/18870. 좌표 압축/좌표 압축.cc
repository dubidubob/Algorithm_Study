#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
 
int main(){
    int n;
    long long temp;
    vector<long long> x1;
    vector<long long> x2;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> temp;
        x1.push_back(temp); // 정렬 벡터
        x2.push_back(temp); // 원본 벡터
    } 
    sort(x1.begin(), x1.end()); // 정렬
    x1.erase(unique(x1.begin(), x1.end()), x1.end()); // 중복값 제거
 
    for (int i = 0; i < n; i++){
        cout << lower_bound(x1.begin(), x1.end(), x2[i]) - x1.begin() << " "; 
 // 몇 번째로 작은 수인지 리턴
    }
} // lower_bound 이용 함수 