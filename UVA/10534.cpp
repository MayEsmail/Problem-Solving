#pragma GCC optimize ("O3")
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wall"
#pragma GCC diagnostic ignored "-Wextra"
#pragma GCC diagnostic ignored "-Wconversion"
#include <bits/stdc++.h>
using namespace std;
typedef long long lol;
int main(){
    int n,mx,liscnt,pos,lis[10005],rlis[10005];
    while(scanf("%d",&n)==1){
        vector<int>v(n),l(n);
        liscnt=0;
        for(int i=0;i<n;i++)scanf("%d",&v[i]);
        for(int i=0;i<n;i++){
            pos=lower_bound(l.begin(),l.begin()+liscnt,v[i])-l.begin();
            l[pos]=v[i];
            if(pos==liscnt)liscnt++;
            lis[i]=pos+1;
        }
        reverse(v.begin(),v.end());
        liscnt=0;
        for(int i=0;i<n;i++){
            pos=lower_bound(l.begin(),l.begin()+liscnt,v[i])-l.begin();
            l[pos]=v[i];
            if(pos==liscnt)liscnt++;
            rlis[n-i-1]=pos+1;
        }
        mx=0;
        for(int i=0;i<n;i++){
            mx=max(mx,2*min(lis[i],rlis[i])-1);
        }
        printf("%d\n",mx);
    }
}
