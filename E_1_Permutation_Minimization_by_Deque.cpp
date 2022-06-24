#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t-->0){
        int n;cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        deque<int> d;
        for(int i=0;i<n;i++){
            if(d.size()>0 && d.front()>=arr[i]){
                d.push_front(arr[i]);
            }else{
                d.push_back(arr[i]);
            }
        }
        while(d.size()>0){
            cout<<d.front();
            d.pop_front();
             if(d.size()>0) cout<<" "; 
        }
        cout<<endl;
    }
    return 0;
}