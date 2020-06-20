#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define endl '\n'
#define MOD 1000000007
#define oset tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define fastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(n) for(int i=0; i<n; i++)
#define gethash(l, r) (MOD-(h[r+1]*p_pow[r-l+1])%MOD+h[l])%MOD;

using namespace __gnu_pbds;
using namespace std;

const int N = 1e3+5;

void solve(int test){
    string s;
    cin>>s;
    int ways = 0;
    int n = s.size(), p = 31;
    vector<int> p_pow(n+1, 0);
    p_pow[0] = 1;

    vector<int> h(n + 1, 0);
    for (int i=n-1; i>=0 ; i--){
        h[i] = ((h[i+1]*p)%MOD + (s[i]-'a'+1))%MOD;
        p_pow[n-i]=(p_pow[n-i-1]*p)%MOD;
    }
    p_pow[n]=(p_pow[n-1]*p)%MOD;

    for(int i=2; i<=n-2; i+=2){
        int h1 = gethash(0, i/2-1);
        int h2 = gethash(i/2, i-1);
        int h3 = gethash(i, (n+i)/2-1);
        int h4 = gethash((n+i)/2, n-1);
        if(h1==h2&&h3==h4) ways++;
    }
    cout<<ways<<endl;
}

signed main()
{

    fastIO;
    int t;
    cin>>t;
    while(t){
        solve(t--);
    }
    return 0;
}
