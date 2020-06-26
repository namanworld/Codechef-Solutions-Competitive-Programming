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
#define FORI(i,j,n) for(int i=j; i<n; i++)
#define FOR(i, n) FORI(i, 0, n)
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

const int N = 1e5+5;
int profit = 0;
int a[4][4],p[4],f[4];

void solve(int test){
    int n; cin>>n;
    memset(a, 0, sizeof(a));
    FOR(i,n){
        char y;
        cin>>y;
        int x;
        cin>>x;
        a[y-'A'][x/3-1]++;
    }
    iota(p,p+4,0);
    int ans = INT_MIN;
    do{
        for(int i=0; i<4; i++) f[i]=a[i][p[i]];
        int ca=0;
        sort(f,f+4);
        for(int i=0;i<4;i++){
            ca+=(i+1)*25*f[i];
        }

        for(int i=0; i<4; i++) if(!f[i]) ca-=100;
        ans = max(ca,ans);
    }while(next_permutation(p,p+4));

    profit+=ans;
    cout<<ans<<endl;
}

signed main()
{
    fastIO
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        solve(i);
    }
    cout<<profit<<endl;
    return 0;
}
