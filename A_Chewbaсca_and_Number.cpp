#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    int ans=0;
    cin>>n;
    string s=to_string(n);
    string anss="";
    for(int i=0;i<s.length();i++){
        if(s[i]>='5'){
            int a=stoi(s[i]+"");
            a=9-a;
            string x=to_string(a);
            anss+=x;
        }else{
            int a=stoi(s[i]+"");
            string x=to_string(a);
            anss+=x;
        }
    }
    cout<<stoll(anss)<<endl;
    return 0;
}