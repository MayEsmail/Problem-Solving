#pragma GCC optimize ("O3")
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wall"
#pragma GCC diagnostic ignored "-Wextra"
#pragma GCC diagnostic ignored "-Wconversion"
#include<bits/stdc++.h>
using namespace std;
typedef long long lol;
string s,ans;
int mem[101][101];
vector<string>v1,v2;
int solve(int x,int y){
    if(x==v1.size()||y==v2.size())return 0;
    int& ret=mem[x][y];
    if(~ret)return ret;
    if(v1[x]==v2[y])ret=solve(x+1,y+1)+1;
    else ret=max(solve(x+1,y),solve(x,y+1));
    return ret;
}
void print(int x,int y){
    if(x==v1.size()||y==v2.size())return;
    if(v1[x]==v2[y]){
        ans+=v1[x]+" ";
        print(x+1,y+1);}
    else if(solve(x+1,y)>solve(x,y+1))
        print(x+1,y);
    else
        print(x,y+1);
}
int main(){
    while(cin>>s){
        v1.clear(); v2.clear();
        v1.push_back(s);
        while(cin>>s&&s!="#")
            v1.push_back(s);
        while(cin>>s&&s!="#")
            v2.push_back(s);
        memset(mem,-1,sizeof mem);
        solve(0,0);
        ans="";
        print(0,0);
        if(ans.size())ans.pop_back();
        cout<<ans<<endl;
    }
}
