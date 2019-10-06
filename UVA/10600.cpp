#pragma GCC optimize ("O3")
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wall"
#pragma GCC diagnostic ignored "-Wextra"
#pragma GCC diagnostic ignored "-Wconversion"
#include<bits/stdc++.h>
using namespace std;
typedef long long lol;
const int N=1e2+5,M=1e4+5,OO=0x3f3f3f3f;
int n,m,x,y,c,from[M],to[M],cost[M],parent[N],sz[N],sorted[M],comps;
vector<int>v;
void init(){
    iota(parent,parent+n+1,0);
    fill(sz,sz+n+1,1);
    comps=n;
}
int findpar(int u){
    return(u==parent[u])?u:parent[u]=findpar(parent[u]);
}
bool join(int u,int v){
    u=findpar(u);
    v=findpar(v);
    if(u==v)return 0;
    if(sz[u]>sz[v])swap(u,v);
    parent[u]=v;
    sz[v]+=sz[u];
    comps--;
    return 1;
}
int kruskal(){
    init();
    int ret=0;
    for(int i=0;i<m&&comps>1;i++){
        int e=sorted[i];
        if(join(from[e],to[e])){ret+=cost[e];   v.push_back(e);}
    }
    return ret;
}
int kruskalremoveedge(int edge){
    init();
    int ret=0;
    for(int i=0;i<m&&comps>1;i++){
        int e=sorted[i];
        if(e==edge)continue;
        if(join(from[e],to[e]))ret+=cost[e];
    }
    return ret;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        for(int i=0;i<m;i++){
            scanf("%d %d %d",&x,&y,&c);
            from[i]=x;   to[i]=y;   cost[i]=c;    sorted[i]=i;
        }
        sort(sorted,sorted+m,[](int a,int b){return cost[a]<cost[b];});
        v.clear();
        printf("%d ",kruskal());
        int mn=OO;
        for(int i=0;i<v.size();i++){
            x=kruskalremoveedge(v[i]);
            if(comps==1)mn=min(mn,x);
        }
        printf("%d\n",mn);
    }
}
