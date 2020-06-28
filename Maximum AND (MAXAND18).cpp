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
int freq[32];

bool compare(pii p, pii q){
    if(p.ff!=q.ff) return p.ff>q.ff;
    else if(p.ff==q.ff && p.ss!=q.ss) return p.ss<q.ss;
}

void solve(int test){
    int n, k;
    cin>>n>>k;
    memset(freq, 0, sizeof(freq));
    FOR(i, n){
        cin>>arr[i];
        int j = 0;
        while(j<32){
            if(arr[i]&(1<<j)) freq[j]++;
            j++;
        }
    }

    int sum[32]={0};
    vector<pii> pp(32);

    FOR(i, 32) {
        sum[i] = freq[i]*pow(2,i);
        pp[i] = {sum[i], i};
    }

    sort(all(pp), compare);

    int ans = 0;
    FOR(i, k){
        pii curr = pp[i];
        ans+=pow(2, curr.ss);
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

