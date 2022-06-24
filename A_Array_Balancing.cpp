
#include <iostream>
#include<vector>
using namespace std;
int func(vector<long long>&a,vector<long long>&b){
    int n=a.size();
    int ans=0;
   for(int i=1;i<n;i++){
        ans += min(abs(a[i] - a[i - 1]) + abs(b[i] - b[i - 1]), abs(a[i] - b[i - 1]) + abs(b[i] - a[i - 1]));
   }
   return ans;
}
int main(){
    int t;cin>>t;
    while(t-->0){
        int n;cin>>n;
        vector<long long> v1(n),v2(n);
        for(int i=0;i<n;i++) cin>>v1[i];
        for(int i=0;i<n;i++) cin>>v2[i];
        vector<long long> dp(n+1,-1);
        long long a=func(v1,v2);
        cout<<a<<endl;
    }
}