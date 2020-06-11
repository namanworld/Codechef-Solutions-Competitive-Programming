#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int odd = 0;
        if(n&1) odd = 1, n-=3;
        for(int i=1; i<=n; i+=2) cout<<i+1<<" "<<i<<" ";
        if(odd) cout<<n+2<<" "<<n+3<<" "<<n+1<<" ";
        cout<<endl;
    }
    return 0;
}
