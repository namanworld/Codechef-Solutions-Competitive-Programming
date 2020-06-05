#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define INF 10000000000000
using namespace std;

signed main()
{
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        int sum = 0;
        for(int i=0; i<n; i++) {
                int x;
                cin>>x;
                if(x>k) sum = (sum+(x-k))%MOD;
        }
        cout<<sum<<endl;
    }
    return 0;
}
