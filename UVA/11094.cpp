#pragma GCC optimize ("O3")
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wall"
#pragma GCC diagnostic ignored "-Wextra"
#pragma GCC diagnostic ignored "-Wconversion"
#include <bits/stdc++.h>
using namespace std;
typedef long long lol;
char arr[25][25];
int n,m,mx,ctr,nx,ny,dx[]={0,0,1,-1},dy[]={1,-1,0,0};
char ch;
bool vis[25][25];
void dfs(int x,int y){
    vis[x][y]=1;
    ctr++;
    for(int i=0;i<4;i++){
        nx=x+dx[i],ny=y+dy[i];
        if(ny<0)ny=m-1;
        if(ny>=m)ny=0;
        if(nx>=0&&nx<n&&!vis[nx][ny]&&arr[nx][ny]==ch)dfs(nx,ny);
    }
}
int main(){
    int x,y;
    while(cin>>n>>m){
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin>>arr[i][j];
        cin>>x>>y;
        ch=arr[x][y];
        memset(vis,0,sizeof vis);
        dfs(x,y);
        mx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]&&arr[i][j]==ch){
                    ctr=0;
                    dfs(i,j);
                    mx=max(mx,ctr);
                }
            }
        }
        cout<<mx<<endl;
    }
}
