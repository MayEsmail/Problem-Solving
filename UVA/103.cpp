#pragma GCC optimize ("O3")
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wall"
#pragma GCC diagnostic ignored "-Wextra"
#pragma GCC diagnostic ignored "-Wconversion"
#include<bits/stdc++.h>
using namespace std;
typedef long long lol;
int k,n,arr[50][11],mem[31],l,mx,v,stps,child[31];
vector<int>ans;
bool f;
int solve(int lst){
    int& ret=mem[lst];
    if(~ret)return ret;
    ret=1;
    for(int i=0;i<k;i++){
        f=1;
        for(int j=0;j<n;j++){
            if(arr[i][j]>=arr[lst][j]){f=0; break;}
        }
        if(f){
            v=solve(i);
            if(v+1>ret){
                ret=v+1;
                child[lst]=i;
            }
        }
    }
    return ret;
}
int main(){
    while(~scanf("%d %d",&k,&n)){
        for(int i=0;i<k;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&arr[i][j]);
            }
            sort(arr[i],arr[i]+n);
        }
        mx=0;
        for(int i=0;i<k;i++){
            memset(mem,-1,sizeof  mem);
            stps=solve(i);
            l=i;
            if(stps>mx){
                mx=stps;
                ans.clear();
                while(stps--){
                    ans.push_back(l);
                    l=child[l];
                }
            }
        }
        printf("%d\n%d",mx,ans[ans.size()-1]+1);
        for(int i=ans.size()-2;i>=0;i--)printf(" %d",ans[i]+1);
        puts("");
    }
}
