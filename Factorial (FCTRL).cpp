#include <bits/stdc++.h>
#define int long long
#define mid(s, e) ((s+e)/2)
#define MOD 1000000007
using namespace std;

int coins(int i, int n, int q){
    if( (n&1) ==0) return n/2;
    else if(i == q) return n/2;
    else return n/2+1;
}

signed main()
{
    int t;
    cin>>t;
    while(t--){
        int g;
        cin>>g;

        while(g--){
            int i, n, q;
            cin>>i>>n>>q;
            cout<<coins(i, n, q)<<endl;
        }
    }
    return 0;
}
