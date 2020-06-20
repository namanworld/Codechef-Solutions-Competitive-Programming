#include <bits/stdc++.h>
#include <iomanip>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define endl '\n'
#define MOD 1000000007
#define INF 10000000000000000
#define oset tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define fastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, n) for(int i=0; i<n; i++)
#define all(a) a.begin(),a.end()
#define mp make_pair
#define vi vector<int>
#define ss second
#define ff first
#define pii pair<int,int>
#define vii vector<pii>
#define gethash(l, r) (MOD-(h[r+1]*p_pow[r-l+1])%MOD+h[l])%MOD;

using namespace __gnu_pbds;
using namespace std;

const int N = 305;
int arr[N][N];

void solve(int test){
    int n, m;
    cin>>n>>m;
    map<int, int> mp;

    FOR(i, n){
        FOR(j, m) {
            cin>>arr[i][j];
            mp[arr[i][j]]++;
        }
    }

    int odd = 0;
    for(auto it=mp.begin(); it!=mp.end(); it++){
        if((it->second)&1!=0){
            odd++;
        }
    }

    if((m&1)==0 && odd!=0){
        cout<<-1<<endl;
        return;
    }
    if((m&1)!=0 && odd>n){
        cout<<-1<<endl;
        return;
    }

    auto it = mp.begin();
    for(int i=0; i<n; i++){
        for(int j=0; j<m/2; j++){
            while(it->second<=1) it++;
            arr[i][j] = arr[i][m-j-1] = it->first;
            (it->second)-=2;
        }
    }

    if((m&1)!=0){
        it = mp.begin();
        FOR(i, n){
            while(it->second==0) it++;
            arr[i][m/2] = it->first;
            (it->second)--;
        }
    }

    FOR(i, n){
        FOR(j, m) cout<<arr[i][j]<<' ';
        cout<<endl;
    }
}

signed main()
{

    fastIO;
    int t;
    cin>>t;
    while(t){
        solve(t--);
    }
    return 0;
}
