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

const int N = 1e4+4;
//int arr[N];

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

struct data{
    int t;
    int x;
    int a;
    int id;
};

void solve(int test){
    int h, n;
    cin>>h>>n;
    data arr[n];
    FOR(i, n){
        cin>>arr[i].t>>arr[i].x>>arr[i].a;
        arr[i].id = i;
    }
    sort(arr,arr+n,[&](data d1, data d2){
         return d1.x<d2.x;
    });

    int ans[n]={0};
    FOR(i, n){
        int num_up, num_down, den_up, den_down;
        bool type0 = 0, type1 = 0;
        FORI(j, i+1, n){
            int h = arr[j].a - arr[i].a;
            int w = arr[j].x - arr[i].x;

            bool posbelow = 0, posabove = 0;
            if(!type0) posbelow = 1;
            else{
                if(h*den_down > w*num_down){
                    if(arr[j].t==0){
                        num_down = h;
                        den_down = w;
                    }
                    posbelow = 1;
                }
            }

            if(!type1) posabove = 1;
            else{
                if(h*den_up < w*num_up){
                    if(arr[j].t==1){
                        num_up = h;
                        den_up = w;
                    }
                    posabove = 1;
                }
            }

            if(posabove && posbelow) ans[arr[i].id]++, ans[arr[j].id]++;
            if(!type0 && arr[j].t==0){
                den_down = w;
                num_down = h;
                type0 = 1;
            }
            if(!type1 && arr[j].t==1){
                den_up = w;
                num_up = h;
                type1 = 1;
            }

        }
    }

    FOR(i, n) cout<<ans[i]<<' ';
    cout<<endl;
    //cout<<"Case #"<<test+1<<": "<<ans<<endl;
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

