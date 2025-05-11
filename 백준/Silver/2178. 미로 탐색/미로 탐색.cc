#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int map[101][101];
queue<pair<int,int>> q;
int x , y;
int nx ,ny;
int move_one[4][2] = { {0,1} , {0,-1} , {1,0} , {-1,0} };
int N , M;

void BFS(){
    pair<int,int> p = {1,1};
    q.push(p);

    while(!q.empty()){
        x = q.front().second;
        y = q.front().first;
        q.pop();

        for(int i = 0 ; i < 4 ; ++i){

            nx = x + move_one[i][0];
            ny = y + move_one[i][1];
            
            if(nx >=1 && nx <= M && ny >= 1 && ny <= N && map[ny][nx] == 1){
                q.push({ny,nx});
                map[ny][nx] = map[y][x] + 1;
            }
        }
    }

    
}

int main(int args ,char** argv){
    cin >> N >> M;

    string temp;
    for(int i = 1 ; i <= N ; ++i){
        cin >> temp;
        for(int j = 1 ; j <= temp.size() ; ++j){
            map[i][j] = temp[j-1]-'0';   
        }   
    }
    BFS();

    cout << map[N][M];
}