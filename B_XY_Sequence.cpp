#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t-->0){
    int n,B,x,y;
    cin>>n>>B>>x>>y;
    long long sum=0;
    long long start=0;
    long long prev=0;
    for(int i=0;i<n;i++){
        if(prev+x<=B){
            sum+=prev+x;
            prev=prev+x;
        }else{
            sum+=prev-y;
            prev=prev-y;
        }
    }
    cout<<sum<<endl;
    }
}