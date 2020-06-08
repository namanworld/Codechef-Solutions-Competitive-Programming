#include <bits/stdc++.h>
#define int long long
using namespace std;

void fun(string s){
    vector<int> alpha(256, 0);
    int maxCount = 0;
    for(int i=0; i<s.size(); i++){
        alpha[(int)s[i]]++;
        maxCount = max(alpha[(int)s[i]], maxCount);
    }

    int index = 0;
    for(int i=0; i<256; i++){
        if(alpha[i]==maxCount){
            index = i;
            break;
        }
    }

    for(int i=0; i<s.size(); ++i){
        if((int)s[i] == index) s[i] = '?';
    }

    cout<<s<<'\n';

}

signed main()
{
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        fun(s);
    }
    return 0;
}
