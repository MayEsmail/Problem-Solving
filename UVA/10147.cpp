#pragma GCC optimize ("O3")
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wall"
#pragma GCC diagnostic ignored "-Wextra"
#pragma GCC diagnostic ignored "-Wconversion"
#include<bits/stdc++.h>
using namespace std;
typedef long long lol;
bool f;
const int N=1e3+5,M=1e6+5,OO=0x3f3f3f3f;
int n,m,x,y,parent[N],sz[N],comps,from[M],to[M],sorted[M],ne,cost[M];
vector<pair<int,int>>v;
bool vis[N][N];
void init(){
    iota(parent,parent+n+1,0);
    fill(sz,sz+n+1,1);
    comps=n;
    f=0;
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
    comps--;
    return 1;
}
void kruskal(){
    sort(sorted,sorted+ne,[](int a,int b){return cost[a]<cost[b];});
    for(int i=0;comps&&i<ne;i++){
        x=sorted[i];
        if(join(from[x],to[x])){printf("%d %d\n",from[x],to[x]);    f=1;}
    }
}
int main(){
    int t;
    scanf("%d",&t);
    for(int a=0;a<t;a++){
        if(a)puts("");
        scanf("%d",&n);
        v.clear();
        for(int i=0;i<n;i++){
            scanf("%d %d",&x,&y);
            v.push_back({x,y});
        }
        ne=0;
        memset(vis,0,sizeof vis);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j])continue;
                if(i==j)continue;
                from[ne]=i+1;
                to[ne]=j+1;
                sorted[ne]=ne;
                cost[ne++]=pow(v[i].first-v[j].first,2)+pow(v[i].second-v[j].second,2);
                vis[i][j]=vis[j][i]=1;
            }
        }
        init();
        scanf("%d",&m);
        for(int i=0;i<m;i++){
            scanf("%d %d",&x,&y);
            join(x,y);
        }
        kruskal();
        if(!f)puts("No new highways need");
    }
}
