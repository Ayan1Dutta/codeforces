#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<pair<ll,ll>,int>dp;
int func(vector<ll>&arr,int index,ll health=0){
    if(health<0)return INT_MIN;
    if(index==arr.size())return 0;
    if(dp.count({index,health})){
        return dp[{index,health}];
    } 
    int l=1+func(arr,index+1,health+arr[index]);
    int nl=func(arr,index+1,health);
    return dp[{index,health}]=max(l,nl);
}
int main(){
    int n;cin>>n;
    vector<ll>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    dp.clear();
    int a=func(arr,0);
    cout<<a<<endl;
}