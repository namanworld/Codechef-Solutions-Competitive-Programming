#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define INF 10000000000000
using namespace std;

void pairs(int n, int m){
    int dig = floor(log10(m)+1);
    int num = pow(10, dig)-1;
    if(m != num) dig--;
    int res = dig * n;
    bool found = false;
    if(res>0) {
            found = true;
            cout<<res<<" "<<n<<endl;
    }
    else cout<<0<<" "<<0<<endl;

}

signed main()
{
    int t;
    cin>>t;

    while(t--){
        int n, m;
        cin>>n>>m;
        pairs(n, m);
    }

    return 0;
}
