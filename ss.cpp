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
#define ff first
#define ss second
const int mod=1000000007;
int func(int n,int i){
    if ((1<<i)&n){
        return 1;
    }else return 0;
}
int func(int &a,int &b,int &c){
    for(int i=0;i<32;i++){
        if(a==b && b==c){
            return 1;
        }
        int n1=func(a,i);int n2=func(b,i);int n3=func(c,i);
        int zcnt=(n1==0)+(n2==0)+(n3==0);
        int ocnt=3-zcnt;
        if(zcnt==1 && ocnt==2){
            if(n1==0){
                a+=pow(2,i);
            }else if(n2==0){
                b+=pow(2,i);
            }else{
                c+=pow(2,i);
            }
        }else if(zcnt==2 && ocnt==1){
            if(n1==1){
                a+=pow(2,i);
            }else if(n2==1){
                b+=pow(2,i);
            }else{
                c+=pow(2,i);
            }

        }else{
            return 0;
        }
     }
     return 0;
}
int main(){
    int t;cin>>t;
     while(t--) {
        int n;cin>>n;
        if(n==1){
            cout<<1<<endl;
            cout<<1<<endl;
        }
        else if(__builtin_popcount(n)!=1){
            cout<<-1<<endl;
        }
        else{
            vi a;
           int i=1;
           int j=n;
           while(i<j){
            a.push_back(i++);
            a.push_back(j--);
           }
           for (int c:a)
           {
            cout<<c<<" ";
           }
           cout<<endl;
           reverse(a.begin(),a.end());
            for (int c:a)
           {
            cout<<c<<" ";
           }
           
           
           cout<<endl;
        }
	}
		
	}
