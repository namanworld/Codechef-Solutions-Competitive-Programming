#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define MOD 1000000007
#define fastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(n) for(int i=0; i<n; i++)
using namespace std;
double p, s;

void solve(int test){
    cin>>p>>s;
    double l = (p - sqrt(p*p-24*s))/12;
    cout<<fixed<<setprecision(2)<<l*l*l -(p/4)*l*l + s*l/2<<endl;
}

signed main()
{
    int t;
    cin>>t;
    for(int i=1; i<=t; i++) solve(i);
    return 0;
}
