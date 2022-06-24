#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n;cin>>n;vector<ll>v(n);
    ll sum=0;
    for(int i=0;i<n;i++){
        cin>>v[i];sum+=v[i];
    }
    ll ans=0;
    if(sum%3==0){
        ll num1=sum/3;
        ll num2=2*num1;
        ll s=0,c1=0;
        for(int i=0;i<n-1;i++){
            s+=v[i];
            if(s==num2){
                ans=ans+c1;
            }
            if(s==num1){
                c1++;
            }
        }
    }
    cout<<ans<<endl;
}