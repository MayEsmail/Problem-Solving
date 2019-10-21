#pragma GCC optimize ("O3")
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wall"
#pragma GCC diagnostic ignored "-Wextra"
#pragma GCC diagnostic ignored "-Wconversion"
#include<bits/stdc++.h>
using namespace std;
typedef long long lol;
int n,a[21],b[21],num,c;
string s;
vector<int>line;
int vis[22];
int solve(int idx){
    if(idx==n)return 0;
    bool ff=1;
    int ret=0;
    for(int i=0;i<n;i++)
        if(vis[i]&&((a[i]>a[idx]&&vis[i]<b[idx])||(a[i]<a[idx]&&vis[i]>b[idx]))){ff=0;   break;}
    if(ff){vis[idx]=b[idx];  ret=solve(idx+1)+1;     vis[idx]=0;}
    return ret=max(ret,solve(idx+1));
}
int main(){
    while(getline(cin,s)){
        line.clear();
        stringstream s2(s);
        while(s2>>num){line.push_back(num);}
        if(line.size()==1){n=line[0];   c=0;    continue;}
        if(!c){
            for(int i=0;i<n;i++)a[i]=line[i];
            c=1;
        }
        else{
            for(int i=0;i<n;i++)b[i]=line[i];
            memset(vis,0,sizeof vis);
            cout<<solve(0)<<endl;
        }
    }
}
