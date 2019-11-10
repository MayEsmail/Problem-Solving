#pragma GCC optimize ("O3")
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wall"
#pragma GCC diagnostic ignored "-Wextra"
#pragma GCC diagnostic ignored "-Wconversion"
#include <bits/stdc++.h>
using namespace std;
typedef long long lol;
void print(const vector<int>&v,const vector<int>&path,int pos){
    if(pos==-1)return;
    print(v,path,path[pos]);
    cout<<v[pos]<<endl;
}
int main(){
    int num,sz,lisend=0,liscnt=0,pos;
    vector<int>v;
    while(cin>>num)v.push_back(num);
    sz=v.size();
    vector<int>l(sz),lid(sz),path(sz);
    for(int i=0;i<sz;i++){
        pos=lower_bound(l.begin(),l.begin()+liscnt,v[i])-l.begin();
        l[pos]=v[i];  lid[pos]=i;
        if(pos)path[i]=lid[pos-1];
        else path[i]=-1;
        if(pos==liscnt){lisend=i;       liscnt++;}
    }
    cout<<liscnt<<"\n-\n";
    print(v,path,lisend);
}
