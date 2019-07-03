#include<bits/stdc++.h>
using namespace std;
typedef long long lol;
int vis[10][10],dx[]={-2,-2,-1,-1,1,1,2,2},dy[]={-1,1,-2,2,-2,2,-1,1};
bool valid(int x,int y){
    return (x>0&&x<=8&&y>0&&y<=8)?1:0;
}
int main(){
    char ca,cb;
    int x1,y1,x2,y2,ia;
    queue<pair<int,int> >q;
    while(cin>>ca>>x1>>cb>>x2){
        ia=x1;
        memset(vis,0,sizeof vis);
        while(!q.empty())q.pop();
        y1=ca-'a'+1;
        y2=cb-'a'+1;
        q.push({x1,y1});
        vis[x1][y1]=1;
        while(!q.empty()&&!vis[x2][y2]){
            x1=q.front().first;     y1=q.front().second;
            q.pop();
            for(int i=0;i<8;i++){
                int nx=x1+dx[i],ny=y1+dy[i];
                if(valid(nx,ny)&&!vis[nx][ny]){
                    vis[nx][ny]=vis[x1][y1]+1;
                    q.push({nx,ny});
                }
            }
        }
        cout<<"To get from "<<ca<<ia<<" to "<<cb<<x2<<" takes "<<vis[x2][y2]-1<<" knight moves.\n";
    }
}