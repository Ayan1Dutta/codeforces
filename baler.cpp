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
void func(string &s ,vector<int>&special){
	int maxi=0;
	stack<char>sc;
	for(int i=0;i<s.length();i++){
		if(special[s[i]-'a']){
			int cnt=0;
			while(!sc.empty()){
				sc.pop();
				cnt++;
			}
			maxi=max(maxi,cnt);
			
		}
		sc.push(s[i]);
	}
	cout<<maxi<<endl;
}
int main(){
   int t=1;
   cin>>t;
   while(t--){
    int n;cin>>n;
	string s;cin>>s;
	int k;cin>>k;
	vector<int>special(26);
	for(int i=0;i<k;i++){
		char ch;cin>>ch;
		special[ch-'a']=1;
	}
	func(s,special);
	// for(auto i:special){
	// 	cout<<i<<" ";
	// }
   }
   return 0;
}