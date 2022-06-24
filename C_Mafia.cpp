#include<bits/stdc++.h>
using ll = long long;
using namespace std;
ll isPossible(vector<ll>& a,ll mid){
    ll lossec=0;
    for(ll i:a){
       if(mid<i) return 0;
       else{
           lossec+=mid-i;
       }
    }
    return lossec>=mid;
}
int main(){
    ll n;
    cin>>n;
   vector<ll>a(n);
    ll sum=0;ll maxi=LONG_LONG_MIN;
    for(int i=0;i<n;i++){
        cin>>a[i];maxi=max(maxi,a[i]);
        sum+=a[i];
    }
    ll low=maxi;ll high=sum;
    ll ans=-1;

    while(low<=high){
        ll mid=(low+high)/2;
        if(isPossible(a,mid)){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    cout<<ans;

}