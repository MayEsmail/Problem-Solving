#pragma GCC optimize ("O3")
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wall"
#pragma GCC diagnostic ignored "-Wextra"
#pragma GCC diagnostic ignored "-Wconversion"
#include<bits/stdc++.h>
using namespace std;
typedef long long lol;
const int N=2e5+5,OO=0x3f3f3f3f;
int m,ne,parent[N],sz[N];
string s1,s2;
map<string,int>mp;
void init(){
    iota(parent,parent+N,0);
    fill(sz,sz+N,1);
    mp.clear();
    ne=1;
}
int findpar(int u){
    return (u==parent[u])?u:parent[u]=findpar(parent[u]);
}
int join(int u,int v){
    u=findpar(u);
    v=findpar(v);
    if(u==v)return sz[v];
    if(sz[u]>sz[v])swap(u,v);
    parent[u]=v;
    sz[v]+=sz[u];
    return sz[v];
}
int main(){
    ios_base::sync_with_stdio(0);   cin.tie(0);     cout.tie(0);
    int t,u,v;
    cin>>t;
    while(t--){
        cin>>m;
        init();
        for(int i=0;i<m;i++){
            cin>>s1>>s2;
            if(mp[s1])u=mp[s1];
            else mp[s1]=u=ne++;
            if(mp[s2])v=mp[s2];
            else mp[s2]=v=ne++;
            cout<<join(u,v)<<endl;
        }
    }
}
