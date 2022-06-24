#include<bits/stdc++.h>
using namespace std;
#define ll long long
int func(string &arr,int k){
    int n=arr.length();
    int ac=0,bc=0,i=-1,j=-1;
    int maxf=0;
    int ans=INT_MIN;
    while(i<n-1){
        i++;
        if(arr[i]=='a')ac++;
        else bc++;
        maxf=max(ac,bc);
        while(j<n && (i-j)-maxf>k){
            j++;
            if(arr[j]=='a')ac--;
            else bc--;
            maxf=max(ac,bc);
        }
        ans=max(ans,i-j);
    }
    return ans;
} 
int main(){
    int n,k;cin>>n>>k;
    string arr;
    cin>>arr;
    int a=func(arr,k);
    cout<<a<<endl;
}