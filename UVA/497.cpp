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
    int t,num,sz,lisend=0,liscnt=0,pos;
    cin>>t;
    cin.ignore();
    cin.ignore();
    string s;
    while(t--){
        vector<int>v;
        while(getline(cin,s)){
            if(!s.size())break;
            stringstream s2(s);
            s2>>num;
            v.push_back(num);
        }
        sz=v.size();
        if(sz==0){cout<<"Max hits: "<<0<<"\n";  if(t)cout<<"\n";    continue;}
        vector<int>l(sz),lid(sz),path(sz);
        lisend=liscnt=0;
        for(int i=0;i<sz;i++){
            pos=lower_bound(l.begin(),l.begin()+liscnt,v[i])-l.begin();
            l[pos]=v[i];  lid[pos]=i;
            if(pos)path[i]=lid[pos-1];
            else path[i]=-1;
            if(pos==liscnt){lisend=i;       liscnt++;}
        }
        cout<<"Max hits: "<<liscnt<<"\n";
        print(v,path,lisend);
        if(t)cout<<endl;
    }
}
