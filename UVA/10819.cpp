#pragma GCC optimize ("O3")
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wall"
#pragma GCC diagnostic ignored "-Wextra"
#pragma GCC diagnostic ignored "-Wconversion"
#include<bits/stdc++.h>
using namespace std;
typedef long long lol;
const int OO=0x3f3f3f3f;
int m,n,p[10005],f[105],mem[105][10205];
int solve(int idx,int sum){
    if((sum>m&&m<1800)||sum>m+200||(idx==n&&sum>m&&sum<=2000))return -OO;
    if(idx==n)return 0;
    int& ret=mem[idx][sum];
    if(~ret)return ret;
    return ret=max(solve(idx+1,sum),solve(idx+1,sum+p[idx])+f[idx]);
}
int main(){
    while(~scanf("%d %d",&m,&n)){
        for(int i=0;i<n;i++)scanf("%d %d",p+i,f+i);
        memset(mem,-1,sizeof mem);
        printf("%d\n",solve(0,0));
    }
}
