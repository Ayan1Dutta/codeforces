#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
void func(string &s1,string &s2){
  int a=0;
  for(int i=0;i<s2.size();i++){
    if(s2[i]=='a'){
      a++;
    }
  }
  if(a==0){
    cout<<pow(2,s1.size())<<endl;
  }else if(a==1 && s2.size()==1){
    cout<<1<<endl;
  }else{
    cout<<-1<<endl;
  }
}
int main(){
  int t=1;cin>>t;
  while(t--){
    string s,t;cin>>s>>t;
    func(s,t);
  }
    return 0;
}