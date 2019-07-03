#include<bits/stdc++.h>
using namespace std;
typedef long long lol;
vector<int>adj[101];
int n,m,f,t;bool vis[101];
vector<int>ans;
string del;
void dfs(int node){
    vis[node]=1;
    for(int i=0;i<adj[node].size();i++)
        if(!vis[adj[node][i]])dfs(adj[node][i]);
    cout<<del<<node;
    del=" ";
}
int main(){
    ios_base::sync_with_stdio(0);   cin.tie(0);
	while(cin>>n>>m&&(n||m)){
        for(int i=1;i<=n;i++)adj[i].clear();
        memset(vis,0,sizeof vis);
        while(m--){
            cin>>f>>t;
            adj[t].push_back(f);
        }
        del="";
        for(int i=1;i<=n;i++)
            if(!vis[i])dfs(i);
        cout<<endl;
	}
	return 0;
}
