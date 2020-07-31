#include <bits/stdc++.h>
#include <iomanip>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define endl '\n'
#define root2 1.41421
#define root3 1.73205
#define pi 3.14159
#define cntbit __builtin_popcountll
#define MOD 1000000007
#define INF 10000000000000000
// find_by_order(), order_of_key()
#define oset tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define fastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FORI(i,j,n) for(int i=j; i<=n; i++)
#define FOR(i, n) for(int i=0; i<n; i++)
#define all(a) a.begin(),a.end()
#define mp make_pair
#define vi vector<int>
#define ss second
#define pb push_back
#define ff first
#define pii pair<int,int>
#define vii vector<pii>
#define pq priority_queue<int>
#define pdq priority_queue<int, vi, greater<int> >
#define gethash(l, r) (MOD-(h[r+1]*p_pow[r-l+1])%MOD+h[l])%MOD;
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a*b)/gcd(a, b)
#define sqr(x) (x*x)

using namespace __gnu_pbds;
using namespace std;

const int N = 1e5 + 5;
int arr[N];

int pow(int x, int y){
    int res = 1;
    x = x%MOD;
    if(x==0) return 0;

    while(y>0){
        if(y&1) res = ((res*x)%MOD+MOD)%MOD;
        y = y>>1;
        x = ((x*x)%MOD+MOD)%MOD;
    }
    return res%MOD;
}

///Fibonacci under modulo
/*map<int, int> F;
int f(int n) {
    if (F.count(n)) return F[n];
    long k=n/2;
    if (n%2==0) { // n=2*k
        return F[n] = (f(k)*f(k) + f(k-1)*f(k-1)) % 10;
    } else { // n=2*k+1
        return F[n] = (f(k)*f(k+1) + f(k-1)*f(k)) % 10;
    }
}*/

void solve(int test){
    int n; cin>>n;
    FOR(i, n) cin>>arr[i];

    int dp[n];
    dp[0] = 1;

    int sum = 1;
    FORI(i, 1, n-1){
        dp[i] = 1;
        if(arr[i-1]<=arr[i]) dp[i] += dp[i-1];
        sum += dp[i];
    }

    cout<<sum<<endl;
}

signed main()
{
    fastIO

   /*#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("error.txt", "w", stderr);
   freopen("output.txt", "w", stdout);
   #endif*/
    ///Prime factors formations:
    /*primes.assign(N, true);
    for(int i=2; i<N; i++){
        if(primes[i]) for(int j=i*i; j<N; j+=i) primes[j] = false;
    }*/

    int t;
    cin>>t;
    FOR(i, t){
        solve(i);
    }

    //cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;

    return 0;
}

