#pragma GCC optimize ("O3")
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wall"
#pragma GCC diagnostic ignored "-Wextra"
#pragma GCC diagnostic ignored "-Wconversion"
#include <bits/stdc++.h>
using namespace std;
typedef long long lol;
string s1,s2;
int mem[105][105];
int lcs(int x,int y){
    if(x==s1.length()||y==s2.length())return 0;
    int& ret=mem[x][y];
    if(~ret)return ret;
    if(s1[x]==s2[y])return ret=1+lcs(x+1,y+1);
    return ret=max(lcs(x+1,y),lcs(x,y+1));
}
int main(){
    int c=0;
    while(getline(cin,s1)){
        if(s1[0]=='#')break;
        getline(cin,s2);
        memset(mem,-1,sizeof mem);
        cout<<"Case #"<<++c<<": you can visit at most "<<lcs(0,0)<<" cities."<<endl;
    }
}
