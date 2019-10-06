#pragma GCC optimize ("O3")
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wall"
#pragma GCC diagnostic ignored "-Wextra"
#pragma GCC diagnostic ignored "-Wconversion"
#include<bits/stdc++.h>
using namespace std;
typedef long long lol;
const int N=505,M=250005,OO=0x3f3f3f3f;
map<string,vector<int>>mp;
bool f;
vector<string>v;
void init(){
    mp.clear();
    f=1;
    v.clear();
}
bool cmp(string a,string b){
    if(a.size()!=b.size()){
        if(a.size()<b.size())return 1;
        return 0;
    }
    return a<b;
}
int main(){
    ios_base::sync_with_stdio(0);   cin.tie(0);     cout.tie(0);
    string s,t;   int n;    f=1;
    while(cin>>s){
        if(s=="()"){
            if(!f){cout<<"not complete"<<endl;    init();    continue;}
            auto it=mp.end();   it--;
            do{
                s=it->first;
                if(s==""){it--; continue;}
                s.pop_back();
                if(!mp[s].size()){f=0;  break;}
                it--;
            }while(it!=mp.begin());
            if(!f){cout<<"not complete"<<endl;    init();    continue;}
            sort(v.begin(),v.end(),cmp);
            for(int i=0;i<v.size();i++){if(i)cout<<" ";    cout<<mp[v[i]][0];}
            cout<<endl;   init();   continue;
        }
        if(f){
            int i;  n=0;
            for(i=1;s[i]!=',';i++){n*=10;   n+=int(s[i]-'0');}
            s=&s[i+1];  s.pop_back();
            v.push_back(s);
            mp[s].push_back(n);
            if(mp[s].size()>1)f=0;
        }
    }
}
