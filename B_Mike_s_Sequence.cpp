#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    unordered_map<int,int> map;
    for(int i:arr){
        map[i]++;
    }
    for(auto it=map.begin();it!=map.end();it++){
        if(it->second==1){
            cout<<it->first<<endl;
            return 0;
        } 
       
    }
}