#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define INF 10000000000000
using namespace std;

int pairs(string s){
    if(s.length()<=1) return 0;
    int ans = 0;
    for(int i=0; i<s.length()-1;){
        if(s[i]!=s[i+1]) {
                ans++;
                i+=2;
        }
        else i++;
    }
    return ans;
}

signed main()
{
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        cout<<pairs(s)<<endl;
    }
    return 0;
}
