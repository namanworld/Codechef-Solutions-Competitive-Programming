#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define MOD 1000000007
#define fastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(n) for(int i=0; i<n; i++)

using namespace std;

int arr[101];

void solve(int test){
    int n;
    cin>>n;
    int localInv = 0;
    FOR(n) {
        cin>>arr[i];
        if(i>0 && arr[i]<arr[i-1]) localInv++;
    }

    int tot = 0;
    FOR(n-1){
        for(int j=i+1; j<n; j++){
            if(arr[i]>arr[j]) tot++;
        }
    }

    if(tot == localInv) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;


}

signed main()
{
    fastIO
    int t;
    cin>>t;
    for(int i=0; i<t; i++) solve(i);
    return 0;
}
