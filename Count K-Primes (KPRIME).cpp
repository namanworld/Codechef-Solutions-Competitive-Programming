#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int A[N];
int prefix[N][6];

int prime_factor[N+5];
vector<pair<int, int> > prime_factors[N+5];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    for(int i=2; i<N; i++){
        if(prime_factor[i]!=0) continue;
        prime_factor[i] = i;
        for(int j=2*i; j<N; j+=i) prime_factor[j] = i;
    }

    for(int i=2; i<N; i++){
        int x = i;
        map<int, int> M;
        while(x!=1){
            M[prime_factor[x]]++;
            x/=prime_factor[x];
        }
        for(auto v:M) prime_factors[i].push_back(v);
    }

    for(int i=1; i<N; i++) A[i] = prime_factors[i].size();

    for(int i=1; i<N; i++){
        for(int k=1; k<=5; k++){
            prefix[i][k] = prefix[i-1][k] + (A[i]==k);
        }
    }

    int t;
    cin>>t;

    while(t--){
        int l, r, k;
        cin>>l>>r>>k;
        cout<<prefix[r][k]-prefix[l-1][k]<<'\n';
    }

    return 0;
}


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

const int N = 1e5+5;

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

int primes[N];
int kPrime[N][6];

void precompute(){
    FORI(i, 2, N-1){
        if(!primes[i]){
            for(int j=i; j<N; j+=i) primes[j]++;
        }
    }

    FORI(i, 2, N-1){
        FORI(j, 1, 5){
            kPrime[i][j] = kPrime[i-1][j] + (primes[i]==j ? 1 : 0);
        }
    }
}

void solve(int test){
    int a, b, k;
    cin>>a>>b>>k;
    cout<< kPrime[b][k] - kPrime[a-1][k] <<endl;
}

signed main()
{
    ///Prime factors formations:
    /*primes.assign(N, true);
    for(int i=2; i<N; i++){
        if(primes[i]) for(int j=i*i; j<N; j+=i) primes[j] = false;
    }*/

    precompute();

    int t;
    cin>>t;
    while(t--){
        solve(t);
    }
    return 0;
}


