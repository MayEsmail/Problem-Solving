#pragma GCC optimize ("O3")
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wall"
#pragma GCC diagnostic ignored "-Wextra"
#pragma GCC diagnostic ignored "-Wconversion"
#include<bits/stdc++.h>
using namespace std;
typedef long long lol;
int mem[101][101];
int n,m,a[101],b[101];
int solve(int x,int y){
    if(x==n||y==m)return 0;
    int& ret=mem[x][y];
    if(~ret)return ret;
    if(a[x]==b[y])ret=solve(x+1,y+1)+1;
    else ret=max(solve(x+1,y),solve(x,y+1));
    return ret;
}
int main(){
    int c=1;
    while(scanf("%d %d",&n,&m)&&(n||m)){
        for(int i=0;i<n;i++)scanf("%d",a+i);
        for(int i=0;i<m;i++)scanf("%d",b+i);
        memset(mem,-1,sizeof mem);
        printf("Twin Towers #%d\nNumber of Tiles : %d\n\n",c++,solve(0,0));
    }
}
