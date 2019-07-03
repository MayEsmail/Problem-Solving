#include<bits/stdc++.h>
using namespace std;
typedef long long lol;
int n,x,y,ctr,dx[]={0,0,1,-1,-1,-1,1,1},dy[]={1,-1,0,0,-1,1,-1,1};
char ch;
bool arr[30][30];
bool vis[30][30];
queue<pair<int,int> >q;
void bfs(int a,int b){
    q.push({a,b});
    vis[a][b]=1;
    while(!q.empty()){
        x=q.front().first;  y=q.front().second;
        q.pop();
        for(int i=0;i<8;i++){
            int nx=x+dx[i],ny=y+dy[i];
            if(nx>=0&&nx<n&&ny>=0&&ny<n&&!vis[nx][ny]&&arr[nx][ny]){
                vis[nx][ny]=1;
                q.push({nx,ny});
            }
        }
    }
}
int main(){
    int ca=0;
    while(cin>>n){
        memset(arr,0,sizeof arr);
        memset(vis,0,sizeof vis);
        ctr=0;  ca++;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>ch;
                if(ch=='1')arr[i][j]=1;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]&&!vis[i][j]){bfs(i,j);    ctr++;}
            }
        }
        printf("Image number %d contains %d war eagles.\n",ca,ctr);
    }
}