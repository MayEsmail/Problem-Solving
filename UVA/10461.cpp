#pragma GCC optimize ("O3")
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wall"
#pragma GCC diagnostic ignored "-Wextra"
#pragma GCC diagnostic ignored "-Wconversion"
#include <bits/stdc++.h>
using namespace std;
typedef long long lol;
int n,e,ne1,head1[505],nxt1[505],to1[505],ne2,head2[505],nxt2[505],to2[505];
lol cost[505];
bool vis1[505],vis2[505];
void init(){
    ne1=ne2=0;
    memset(head1,-1,(n+1)*sizeof head1[0]);
    memset(head2,-1,(n+1)*sizeof head2[0]);
}
void addedge1(int f,int t){
    to1[ne1]=t;
    nxt1[ne1]=head1[f];
    head1[f]=ne1++;
}
void addedge2(int f,int t){
    to2[ne2]=t;
    nxt2[ne2]=head2[f];
    head2[f]=ne2++;
}
lol dfs1(int node){
    vis1[node]=1;
    lol sum=cost[node];
    for(int i=head1[node];~i;i=nxt1[i])
        if(!vis1[to1[i]])sum+=dfs1(to1[i]);
    return sum;
}
lol dfs2(int node){
    vis2[node]=1;
    lol sum=cost[node];
    for(int i=head2[node];~i;i=nxt2[i])
        if(!vis2[to2[i]])sum+=dfs2(to2[i]);
    return sum;
}
int main(){
    int u,v,c=1;    lol tot;
    while(scanf("%d %d",&n,&e)&&(n||e)){
        init(); tot=0;
        for(int i=1;i<=n;i++){scanf("%lld",cost+i);       tot+=cost[i];}
        for(int i=0;i<e;i++){
            scanf("%d %d",&u,&v);
            addedge1(v,u);
            addedge2(u,v);
        }
        scanf("%d",&u);
        printf("Case #%d:\n",c++);
        while(u--){
            memset(vis1,0,sizeof vis1);
            memset(vis2,0,sizeof vis2);
            scanf("%d",&v);
            printf("%lld\n",(tot-dfs1(v))-(dfs2(v)-cost[v]));
        }
        puts("");
    }
}
