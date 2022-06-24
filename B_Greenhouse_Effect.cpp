#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
using vs = vector<string>;
#define cfast std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pll pair<ll,ll>
#define pii pair<int,int>
int main(){
    int t;cin>>t;
    while(t--){
       int n;cin>>n;
       vi a(n);
       for(int i=0;i<n;i++){
           cin>>a[i];
       }
       map<int,vector<int>>m;
       for(int i=0;i<n;i++){
           m[a[i]].push_back(i);
       }
       ll lans=INT_MIN;
       ll rans=INT_MIN;
       for(auto &x:m){
           ll s=x.second.size();
            if(s>1){
               if(s%2==0){
                   ll mid1=(s/2);
                   ll mid2=(s-1)/2;
                   lans=max(lans,x.second[mid1]+1);
                   rans=max()
               }else if(s%2==1){
                   int mid=s/2;
               }
            }
       }
       int aa=max(lans,rans);
       if(aa==INT_MAX){
           aa=0;
       }
       cout<<aa<<endl;

    }
}