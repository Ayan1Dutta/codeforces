#include<bits/stdc++.h>
using namespace std;
string ss="Case #";
int main(){
    int t;cin>>t;
    int a=0;
    while(t-->0){
        a++;
        string s;cin>>s;
        cout<<ss<<to_string(a)<<": ";
        int i=0;
        for( i=1;i<s.length();){
            if(s[i]<=s[i-1]){
                i++;
            }else{
                break;
            }
        }
        if(i==s.length()){
            cout<<s<<endl;
        }else{
            string ans;
            for(int i=0;i<s.length()-1;i++){
                if(s[i]<=s[i+1]){
                    string a;
                    a.push_back(s[i]);a.push_back(s[i]);
                    ans+=a;
                }else{
                    ans.push_back(s[i]);
                }
            }
            ans.push_back(s[s.length()-1]);
            cout<<ans<<endl;
        }
    }
    return 0;
}