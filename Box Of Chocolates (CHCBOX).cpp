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

const int N = 2e5+5;
int arr[N];

void solve(int test){
    int n; cin>>n;
    int w = INT_MIN;
    FOR(i, n){
        cin>>arr[i];
        w = max(w, arr[i]);
    }

    vi v;

    for(int i=0; i<n; ){
        if(arr[i]==w){
            i++;
            continue;
        }
        int j=i;
        for(;j<n && arr[j]!=w; j++);
        v.pb(j-i);
        i=j;
    }

    if(arr[0]!=w && arr[n-1]!=w){
        v[0]+=v.back();
        v.pop_back();
    }
    
    int ans = 0;
    FOR(i, v.size()){
        int temp = 0;
        ans+=max(v[i]-n/2+1, temp);
    }

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
    return 0;
}

