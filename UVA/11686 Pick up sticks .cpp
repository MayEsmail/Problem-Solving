#include<bits/stdc++.h>
using namespace std;
typedef long long lol;
const int N=10000005,M=10000005,OO=0x3f3f3f3f;
int n,m,f,t,vid,timer=0,vis[N],s[N],fin[N],ne,nxt[M],to[M],head[N];
bool flag=0;
vector<int>ans;
void init(){
    ne=0;
    memset(head,-1,n*sizeof head[0]);
}
void addedge(int u,int v){
    to[ne]=v;
    nxt[ne]=head[u];
    head[u]=ne++;
}
void dfs(int node){
    if(flag)return;
    s[node]=timer++;
    vis[node]=vid;
    for(int i=head[node];~i;i=nxt[i]){
        if(vis[to[i]]!=vid)dfs(to[i]);
        else if(s[to[i]]!=-1&&fin[to[i]]==-1)flag=1;
        }
    ans.push_back(node+1);
    fin[node]=timer++;
}
int main(){
	while(scanf("%d%d",&n,&m)&&(n||m)){
        vid++;
        timer=0;
        init();
        ans.clear();
        memset(s,-1,n*sizeof s[0]);
        memset(fin,-1,n*sizeof fin[0]);
        flag=0;
        while(m--){
            scanf("%d%d",&f,&t);
            --f;    --t;
            addedge(t,f);
            }
        for(int i=0;i<n;i++)
            if(vis[i]!=vid)dfs(i);
	if(flag)printf("IMPOSSIBLE\n");
    else
        for(int i=0;i<ans.size();i++)printf("%d\n",ans[i]);
	}return 0;
}
