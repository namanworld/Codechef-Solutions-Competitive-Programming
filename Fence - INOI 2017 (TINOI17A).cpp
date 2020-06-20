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

const int N = 3000;
int arr[N][N];
bool vis[N][N];
int r, c, n;

int calc(int i, int j){
    int dir[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    queue<pii> q;
    q.push({i, j});
    vis[i][j] = true;
    int ans = 0;
    while(!q.empty()){
        int nr = q.front().ff;
        int nc = q.front().ss;
        q.pop();

        ans+=4;
        if(nr>0 && arr[nr-1][nc]) ans-=2;
        if(nc>0 && arr[nr][nc-1 ]) ans-=2;

        for(int k=0; k<4; k++){
            int rr = nr+dir[k][0];
            int cc = nc+dir[k][1];
            if(rr>=0 && rr<r && cc>=0 && cc<c && arr[rr][cc] && !vis[rr][cc]) {
                    q.push({rr, cc});
                    vis[rr][cc] = true;
            }
        }

    }
    return ans;
}

signed main()
{
    fastIO;
    cin>>r>>c>>n;

    while(n--){
        int row, col;
        cin>>row>>col;
        arr[row-1][col-1] = 1;
    }

    int ans = 0;
    FOR(i, r){
        FOR(j, c){
            if(arr[i][j]==1 && !vis[i][j]) ans = max(ans, calc(i,j));
        }
    }

    cout<<ans<<endl;

    return 0;
}
