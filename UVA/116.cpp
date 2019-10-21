#pragma GCC optimize ("O3")
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wall"
#pragma GCC diagnostic ignored "-Wextra"
#pragma GCC diagnostic ignored "-Wconversion"
#include<bits/stdc++.h>
using namespace std;
typedef long long lol;
const int OO=0x3f3f3f3f;
int n,m,arr[11][101],mn,num,path[105],mem[11][101],xs[3];
int solve(int x,int y){
    if(y==m-1)return arr[x][y];
    int& ret=mem[x][y];
    if(~ret)return ret;
    ret=min(solve((x+1)%n,y+1),min(solve(x,y+1),solve((x-1+n)%n,y+1)))+arr[x][y];
    return ret;
}
void savepath(int x,int y){
    path[y]=x+1;
    if(y==m-1)return;
    xs[0]=(x-1+n)%n;    xs[1]=x;    xs[2]=(x+1)%n;
    sort(xs,xs+3);
    if(solve(xs[0],y+1)<=solve(xs[1],y+1)&&solve(xs[0],y+1)<=solve(xs[2],y+1))
        savepath(xs[0],y+1);
    else if(solve(xs[1],y+1)<=solve(xs[0],y+1)&&solve(xs[1],y+1)<=solve(xs[2],y+1))
        savepath(xs[1],y+1);
    else if(solve(xs[2],y+1)<=solve(xs[0],y+1)&&solve(xs[2],y+1)<=solve(xs[1],y+1))
        savepath(xs[2],y+1);
}
int main(){
    while(~(scanf("%d %d",&n,&m))){
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                scanf("%d",&arr[i][j]);
        mn=OO;
        for(int i=0;i<n;i++){
            memset(mem,-1,sizeof mem);
            num=solve(i,0);
            if(num<mn){savepath(i,0);  mn=num;}
        }
        printf("%d",path[0]);
        for(int i=1;i<m;i++){ printf(" %d",path[i]);}
        printf("\n%d\n",mn);
    }
}
