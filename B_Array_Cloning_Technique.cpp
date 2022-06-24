#include<bits/stdc++.h>
using namespace std;
void func(vector<int>& A){
    unordered_map<int,int>map;
    int n=A.size();
    int maxi=0;
    for(int i:A){
        map[i]++;
        maxi=max(maxi,map[i]);
    }
    int req=n-maxi;
    int cnt=maxi;
    int op=0;
    int i=0;
    while(req>0){
        i++;
        op++;
        int prev=req;
        req-=min(req,i*maxi);
        op+=min(prev,i*maxi);
    }
    cout<<op;

}
int main(){
    int t;
    cin>>t;
    while(t-->0){
        int n;cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        if(n==1) cout<<0<<endl;
        else{
            func(v);
            if(t!=0) cout<<endl;
        }
    }
    return 0;
}