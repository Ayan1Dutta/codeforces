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
int row[200002];
int col[200002];
struct BIT{
    int n;
    vector<int>a;
    BIT(int _n){
        n=_n+1;
        a.assign(n,0);
    }
    void update(int ind,int val){
        while(ind<=n){
            a[ind]+=val;
            ind+=(ind & -ind);
        }
    }
    int get(int ind){
        int sum=0;
        while(ind>0){
            sum+=a[ind];
            ind-=(ind & -ind);
        }
        return sum;
    }
    int query(int x,int y){
        return get(y)-get(x-1);
    }
};
int main(){
     cin.tie(0)->sync_with_stdio(0);
    int n,q;cin>>n>>q;
    BIT a(n),b(n);
    while(q--){
        int t;cin>>t;
        if(t==1){
            int x,y;
            cin>>x>>y;
            row[x]++;
            col[y]++;
            if(row[x]==1)a.update(x,1);
            if(col[y]==1)b.update(y,1);
        }else if(t==2){
            int x,y;
            cin>>x>>y;
            row[x]--;
            col[y]--;
            if(row[x]==0)a.update(x,-1);
            if(col[y]==0)b.update(y,-1);
        }else{
            int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
            int x=a.query(x1,x2);
            int y=b.query(y1,y2);
            if(x>=(x2-x1)+1 || y>=(y2-y1)+1){
                cout<<"yes"<<endl;
            }else{
                cout<<"no"<<endl;
            }
        }
    }
    
}