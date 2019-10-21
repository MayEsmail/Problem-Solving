#pragma GCC optimize ("O3")
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wall"
#pragma GCC diagnostic ignored "-Wextra"
#pragma GCC diagnostic ignored "-Wconversion"
#include<bits/stdc++.h>
using namespace std;
typedef long long lol;
const int OO=0x3f3f3f3f;
bool f;
int t,n,k,arr[10005],mem[10005][100];
int solve(int idx,int mod){
    if(!f)return 0;
    if(idx==n){f=mod; return mod;}
    int& ret=mem[idx][mod];
    if(~ret){
        if(mod%k==0&&ret==0)f=1;
        return !(mod%k==0&&ret==0);
    }
    ret=(solve(idx+1,(mod+arr[idx])%k)&&solve(idx+1,((mod-arr[idx])%k+k)%k));
    return ret;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&k);
        for(int i=0;i<n;i++)scanf("%d",arr+i);
        memset(mem,-1,sizeof mem);
        f=1;
        solve(1,arr[0]%k);
        f?puts("Not divisible"):puts("Divisible");
    }
}
