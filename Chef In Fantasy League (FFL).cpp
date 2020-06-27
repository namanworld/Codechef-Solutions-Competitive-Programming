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

const int N = 5e5+4;
int arr[N];

void solve(int test){
    int n, x;
    cin>>n>>x;
    x = 100-x;
    FOR(i, n) cin>>arr[i];
    int def = INT_MAX, forw = INT_MAX;
    int j;
    FOR(i, n){
        cin>>j;
        if(j==0) def = min(def, arr[i]);
        else forw = min(forw, arr[i]);
    }
    if(forw+def<=x) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
}

/*int n, m;
int a[N], b[N];
bool select[N];
vector<vector<int>> adj(n, vector<int>());
bool visited[N];
vi res;
vi province;

void dfs(int x){
    visited[x] = true;
    province.pb(x);
    FOR(i, adj[x].size()){
        if(visited[adj[x][i]]==false && select[adj[x][i]]==true) dfs(adj[x][i]);
    }
}

void solve(int test){
    cin>>n>>m;
    FOR(i,n) cin>>a[i];
    FOR(i,n) cin>>b[i];


    vector<vector<int>> adj(n, vector<int>());
    memset(visited, false, n*sizeof(bool));
    memset(select, false, n*sizeof(bool));
    while(m--){
        int u, v;
        cin>>u>>v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    int num = a[0], den = b[0];

    for(int i=1; i<n; i++){
        if(num*b[i]<den*a[i]){
            num = a[i];
            den = b[i];
        }
    }


    FOR(i, n){
        if(num*b[i]==den*a[i]) select[i] = true;
    }

    for(int i=n-1; i>=0; i--){
        if(visited[i]==false && select[i]==true){
            province.clear();
            dfs(i);
            if(province.size()>res.size()) res = province;
        }
    }

    cout<<res.size()<<endl;

    for(auto i: res) cout<<i+1<<' ';
    cout<<endl;

}*/

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

