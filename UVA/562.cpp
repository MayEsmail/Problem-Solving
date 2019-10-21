#pragma GCC optimize ("O3")
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wall"
#pragma GCC diagnostic ignored "-Wextra"
#pragma GCC diagnostic ignored "-Wconversion"
#include<bits/stdc++.h>
using namespace std;
typedef long long lol;
int sum,n,t,arr[101],mem[101][25001];
int solve(int idx,int rem){
    if(idx<0||rem==0)return 0;
    int& ret=mem[idx][rem];
    if(~ret)return ret;
    ret=0;
    if(arr[idx]<=rem)ret=solve(idx-1,rem-arr[idx])+arr[idx];
    return ret=max(ret,solve(idx-1,rem));
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        sum=0;
        for(int i=0;i<n;i++){
            scanf("%d",arr+i);
            sum+=arr[i];
        }
        memset(mem,-1,sizeof mem);
        printf("%d\n",sum-2*solve(n-1,sum/2));
    }
}
