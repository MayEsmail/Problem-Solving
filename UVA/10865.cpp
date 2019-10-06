#pragma GCC optimize ("O3")
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wall"
#pragma GCC diagnostic ignored "-Wextra"
#pragma GCC diagnostic ignored "-Wconversion"
#include <bits/stdc++.h>
using namespace std;
typedef long long lol;
int main(){
    int n,idx,f,s;
    pair<int,int>p[200001];
    while(scanf("%d",&n)&&n){
        f=s=0;
        for(int i=0;i<n;i++)
            scanf("%d %d",&p[i].first,&p[i].second);
        idx=n/2;
        for(int i=0;i<n;i++){
            if(p[i].first==p[idx].first||p[i].second==p[idx].second)continue;
            if((p[i].first>p[idx].first)==(p[i].second>p[idx].second))f++;
            else s++;
        }
        printf("%d %d\n",f,s);
    }
}
