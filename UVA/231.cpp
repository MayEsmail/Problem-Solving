#pragma GCC optimize ("O3")
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wall"
#pragma GCC diagnostic ignored "-Wextra"
#pragma GCC diagnostic ignored "-Wconversion"
#include <bits/stdc++.h>
using namespace std;
typedef long long lol;
int main(){
    int num,c=0;
    while(cin>>num&&num!=-1){
        if(c)cout<<endl;
        vector<int>v;
        v.push_back(num);
        while(cin>>num&&num!=-1)v.push_back(num);
        reverse(v.begin(),v.end());
        num=v.size();
        vector<int>l(num),lid(num);
        int pos,liscnt=0;
        for(int i=0;i<num;i++){
            pos=upper_bound(l.begin(),l.begin()+liscnt,v[i])-l.begin();
            l[pos]=v[i];
            if(pos==liscnt)liscnt++;
        }
        cout<<"Test #"<<++c<<":\n"<<"  maximum possible interceptions: "<<liscnt<<endl;
    }
}
