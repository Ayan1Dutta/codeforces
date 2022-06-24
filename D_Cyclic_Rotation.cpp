#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
using vs = vector<string>;
const ll mod = 1e9 + 7,inf = 1e18;
void func(vector<ll>&a,vector<ll>&b){
            multiset<int> s;
        int index = 0,n=a.size();
        for(int i = 0; i < n; i++)  {
            // watch(i);
            // watch(index);
            if(a[i] == b[index])    {
                index++;
                continue;
            } 
            if(i > 0 && a[i-1] == b[index] && s.find(a[i-1]) != s.end())  {
                s.erase(s.find(a[i-1]));
                index++;
                i--;
            } else{
                s.insert(a[i]);
            }
        }
        while(index != n && a[n-1] == b[index] && s.find(a[n-1]) != s.end())    {
            s.erase(s.find(a[n-1]));
            index++;
        }
        if(index == n)  {
            cout << "YES\n";
        } else{
            cout << "NO\n";
        }
}
int main(){
    int t;cin>>t;
    while(t--){
    int n;cin>>n;
    vector<ll>v(n),ref(n);
    for(int i=0;i<n;i++)cin>>v[i];
    for(int i=0;i<n;i++)cin>>ref[i];
    func(v,ref);
    }
    return 0;
}
