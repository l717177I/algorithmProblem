#include <bits/stdc++.h>

using namespace std;
char field[101][101];
bool vis[101][101];

int dx[]= {-1, 1, 0, 0};
int dy[]= {0, 0, -1, 1};

int N, M, W, B; 

int bfs(int i, int j, char c){
    int cnt=0;
    queue<pair<int, int>> q;
    q.push({i, j});
    vis[i][j]=true;
    
    while(!q.empty()){
        int x=q.front().first; int y=q.front().second;
        q.pop();
        cnt++;
        for(int k=0; k<4; k++){
            int nx=x+dx[k]; int ny=y+dy[k];
            if(nx<0 || nx>=M || ny<0 || ny>=N || vis[nx][ny]) continue;
            if(field[nx][ny]==c){
                vis[nx][ny]=true;
                q.push({nx, ny});
            }
        }
    }
    return cnt;
}

int main(){
    cin>>N>>M;
    W=B=0;
    
    for(int i=0; i<M; i++){
        string s; cin>>s;
        for(int j=0; j<N; j++){
            field[i][j]=s[j];
            vis[i][j]=false;
        }
    }
    
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            if(!vis[i][j]){
                int cc=0;
                if(field[i][j]=='W'){
                    cc+=bfs(i, j,'W');
                    W+=cc*cc;
                }else{
                    cc+=bfs(i, j, 'B');
                    B+=cc*cc;
                }
            }
        }
    }
    cout<<W<<" "<<B;

    return 0;
}