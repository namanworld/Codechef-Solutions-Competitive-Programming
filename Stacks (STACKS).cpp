#include <bits/stdc++.h>
#include <iomanip>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define endl '\n'
#define MOD (1000000007)
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

const int N = 1e5+4;
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

void solve(int test){
    int n;
    cin>>n;
    multiset<int> s;
    int c;

    FOR(i, n){
        cin>>c;
        if(s.empty()) s.insert(c);
        else {
            if(s.upper_bound(c)==s.end()) s.insert(c);
            else {
                s.erase(s.upper_bound(c));
                s.insert(c);
            }
        }
    }

    cout<<s.size()<<' ';
    for(auto it=s.begin(); it!=s.end(); it++) cout<<*it<<' ';
    cout<<endl;

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
