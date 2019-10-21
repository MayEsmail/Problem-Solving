#pragma GCC optimize ("O3")
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wall"
#pragma GCC diagnostic ignored "-Wextra"
#pragma GCC diagnostic ignored "-Wconversion"
#include<bits/stdc++.h>
using namespace std;
typedef long long lol;
int n,we,iq,lis,mem[1001],chi[1001];
struct ele{
    int w,s,idx;
}arr[1001];
int solve(int lst){
    int& ret=mem[lst];
    if(~ret)return ret;
    ret=1;
    for(int i=n-1;i>=0;i--){
        if(arr[i].w<arr[lst].w&&arr[i].s>arr[lst].s){
            int v=solve(i);
            if(v+1>ret){
                ret=v+1;
                chi[lst]=i;
            }
        }
    }
    return ret;
}
int main(){
    while(~scanf("%d %d",&we,&iq)){
        arr[n].w=we;  arr[n].s=iq;  arr[n].idx=++n;
    }
    memset(mem,-1,sizeof mem);
    int lst,sol;
    for(int i=n-1;i>=0;i--){
        sol=solve(i);
        if(sol>lis){
            lis=sol;
            lst=i;
        }
    }
    printf("%d\n",lis);
    sol=lis;
    vector<int>v;
    while(sol--){
        v.push_back(lst+1);
        lst=chi[lst];
    }
    while(v.size()){
        printf("%d\n",v[v.size()-1]);
        v.pop_back();
    }
}
