#include<bits/stdc++.h>
using namespace std;
vector<long long> ans;
void findpath(vector<int>&par,int src,int dest){
    if(par[dest]==-1)return;
    else{
        ans.push_back(par[dest]);
        findpath(par,src,par[dest]);
    }
  
}
void func(vector<pair<int,int>> *adj, vector<int>&par, vector<long long>&dist,int src,int dst){
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,long long>>> q;
    q.push({0,src});
    dist[src]=0;
    par[src]=-1;
    while(!q.empty()){
        auto x=q.top();q.pop();
        int d=x.first;
        if (x.first!= dist[x.second]){
            cout<<"hu";
            continue;
        } 
        for(auto a:adj[x.second]){
           if(dist[a.first]>a.second+d){
                par[a.first]=x.second;
                dist[a.first]=a.second+d;
                q.push({a.second+d,a.first});
            }
        }
    }
    if(dist[dst]!=LONG_LONG_MAX)findpath(par, src, dst);
}
int main(){
    int n,m;cin>>n>>m;
    vector<int>par(n+1,-1);
    vector<pair<int,int>> adj[n+1];
    vector<long long>dist(n+1,LONG_LONG_MAX);
    for(int i=1;i<=m;i++){
        int a,b,w;cin>>a>>b>>w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }
    ans.push_back(n);
    
    func(adj,par,dist,1,n);
    reverse(ans.begin(),ans.end());
    if(ans.size()==1)cout<<-1;
    else{
    for(int i:ans){
        cout<<i<<" ";
    }
    }
    return 0;
}