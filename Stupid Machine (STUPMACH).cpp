#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define INF 1000000000000
using namespace std;

signed main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n], mn = INT_MAX, count = 0;
        for(int i=0; i<n; i++) {
            int x;
            cin>>x;
            mn = min(mn, x);
            count+=mn;
        }

        cout<<count<<endl;

    }
    return 0;
}
