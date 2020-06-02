#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define INF 100000000000000
using namespace std;

int time(string s, int n){
    int A_goals = 0, B_goals = 0;
    int rem_A = n/2, rem_B = n/2;
    for(int i=0; i<n; i++){
        if((i&1) == 0) {
                A_goals+=s[i]-'0';
                rem_A--;
        }
        else {
                B_goals+=s[i]-'0';
                rem_B--;
        }
        if ((A_goals-B_goals>rem_B) || (B_goals-A_goals>rem_A)) return i+1;
    }
    return n;
}

signed main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        cout<<time(s,2*n)<<endl;
    }
    return 0;
}
