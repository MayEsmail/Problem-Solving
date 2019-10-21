#pragma GCC optimize ("O3")
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wall"
#pragma GCC diagnostic ignored "-Wextra"
#pragma GCC diagnostic ignored "-Wconversion"
#include<bits/stdc++.h>
using namespace std;
typedef long long lol;
int t,n,g,mw,w[1001],p[1001],sum,mem[1001][31];
int solve(int idx,int rem){
    if(idx<0||rem==0)return 0;
    int& ret=mem[idx][rem];
    if(~ret)return ret;
    ret=0;
    if(rem>=w[idx])ret=solve(idx-1,rem-w[idx])+p[idx];
    ret=max(ret,solve(idx-1,rem));
    return ret;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d %d",p+i,w+i);
        scanf("%d",&g);
        sum=0;
        memset(mem,-1,sizeof mem);
        while(g--){
            scanf("%d",&mw);
            sum+=solve(n-1,mw);
        }
        printf("%d\n",sum);
    }
}
