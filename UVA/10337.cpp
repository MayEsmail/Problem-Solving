#pragma GCC optimize ("O3")
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wall"
#pragma GCC diagnostic ignored "-Wextra"
#pragma GCC diagnostic ignored "-Wconversion"
#include<bits/stdc++.h>
using namespace std;
typedef long long lol;
const int OO=0x3f3f3f3f;
int x,arr[10][1001],mem[10][1001];
int solve(int lvl,int mile){
    if(lvl==0&&mile==x)return 0;
    else if(mile==x)return OO;
    int& ret=mem[lvl][mile];
    if(~ret)return ret;
    ret=OO;
    if(lvl-1>=0)ret=min(ret,solve(lvl-1,mile+1)+20-arr[lvl][mile]);
    if(lvl+1<=9)ret=min(ret,solve(lvl+1,mile+1)+60-arr[lvl][mile]);
    ret=min(ret,solve(lvl,mile+1)+30-arr[lvl][mile]);
    return ret;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&x);
        x/=100;
        for(int i=9;i>=0;i--)
            for(int j=0;j<x;j++)
                scanf("%d",&arr[i][j]);
        memset(mem,-1,sizeof mem);
        printf("%d\n",solve(0,0));
        puts("");
    }
}
