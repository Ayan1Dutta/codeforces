#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t-->0){
        int n;cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        if(n==1){
            arr[0]>1?cout<<"NO"<<endl:cout<<"YES"<<endl;
            continue;
        }
        int f=-1,s=-1;
        sort(arr.begin(),arr.end(),greater<int>());
        s=arr[0];
        f=arr[1];
        if(abs(f-s)>1)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}