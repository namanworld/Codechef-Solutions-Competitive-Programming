#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define MOD 1000000007
#define fastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(n) for(int i=0; i<n; i++)

using namespace std;

void solve(int test){
    int n,k, sum=0;
    cin>>n>>k;
    int arr[n];
    FOR(n) {
        cin>>arr[i];
        sum+=arr[i];
    }

    int ans = 0;
    FOR(n){
        if(k>sum-2*arr[i]) ans++;
    }

    cout<<ans<<endl;
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
