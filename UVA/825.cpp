#pragma GCC optimize ("O3")
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wall"
#pragma GCC diagnostic ignored "-Wextra"
#pragma GCC diagnostic ignored "-Wconversion"
#include<bits/stdc++.h>
using namespace std;
typedef long long lol;
int t,n,m,x,y,mem[105][105];
bool arr[105][105];
int solve(int i,int j){
    if(i==n&&j==m)return 1;
    int& ret=mem[i][j];
    if(~ret)return ret;
    ret=0;
    if(j+1<=m&&arr[i][j+1])ret=solve(i,j+1);
    if(i+1<=n&&arr[i+1][j])ret+=solve(i+1,j);
    return ret;
}
string s;
int main(){
    char ch;
    cin>>t;
    bool c=0;
    while(t--){
        cin>>n>>m;
        getline(cin,s);
        memset(arr,1,sizeof arr);
        for(int i=0;i<n;i++){
            getline(cin,s);
            stringstream s2(s);
            s2>>x;
            while(s2>>y){
                arr[x][y]=0;
            }
        }
        memset(mem,-1,sizeof mem);
        if(c)cout<<endl;
        c=1;
        cout<<solve(1,1)<<endl;
    }
}
