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
int n, k;

void solve(int test){
    cin>>n>>k;
    vector<vi> adj(N);

    char c;
    FOR(i, n){
        FOR(j, n){
            cin>>c;
            if(c=='0'||j==i) continue;
            if(abs(i-j)<=k) adj[i].pb(j);
        }
    }

    vi dist(n, -1);
    dist[0] = 0;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        FOR(i, adj[x].size()){
            if(dist[adj[x][i]]!=-1) continue;
            dist[adj[x][i]] = dist[x]+1;
            q.push(adj[x][i]);
        }
    }
    cout<<dist[n-1]<<endl;
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
