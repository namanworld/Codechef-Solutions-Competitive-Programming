#include <bits/stdc++.h>
#include <iomanip>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define endl '\n'
#define MOD 1000000007
#define INF 10000000000000000
// find_by_order(), order_of_key()
#define oset tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define fastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
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

using namespace __gnu_pbds;
using namespace std;

const int N = 1e3+2;

int c[2][2];
void mul(int a[2][2], int b[2][2]){
    FOR(i, 2){
        FOR(j, 2){
            c[i][j] = 0;
        }
    }

    FOR(i, 2){
        FOR(j, 2){
            FOR(k, 2){
                c[i][k]+=a[i][j]*b[j][k];
                c[i][k]%=MOD;
            }
        }
    }
    FOR(i, 2){
        FOR(j, 2){
            a[i][j] = c[i][j];
        }
    }
}

int a[2][2], res[2][2];
void solve(int test){
    int n, m;
    cin>>n>>m;
    int val = m;
    val%=MOD;
    int val2 = val*val;
    val2%=MOD;
    m--;
    m%=MOD;
    n--;
    a[0][0] = m;
    a[0][1] = m;
    a[1][0] = 1;
    a[1][1] = 0;
    res[0][0] = 1;
    res[0][1] = 0;
    res[1][0] = 0;
    res[1][1] = 1;
    while(n){
        if(n%2) mul(res, a);
        mul(a, a);
        n/=2;
    }

    val2 *= res[1][0];
    val2%=MOD;
    val2+=res[1][1]*val;
    val2%=MOD;
    cout<<val2<<endl;
}

signed main()
{
    fastIO
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        solve(i);
    }
    return 0;
}
