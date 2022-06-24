#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
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
int main(){
    int t;cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vvc grid(n,vc(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>grid[i][j];
            }
        }
        int fl=0,fu=0,fs=0;
        int f1=0,f2=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='R'){
                    fu=i;
                    fs=j;
                    f1=1;
                    break;
                }
            }
            if(f1)break;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[j][i]=='R'){
                    fl=i;
                    f2=1;
                    break;
                }
            }
            if(f2)break;
        }
        if(fs==fl){
            cout<<"yes"<<endl;
        }else{
            cout<<"no"<<endl;
        }

    }
}