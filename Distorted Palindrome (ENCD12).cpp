#include <bits/stdc++.h>
#include <iomanip>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define endl '\n'
#define root2 1.41421
#define root3 1.73205
#define pi 3.14159
#define cntbit __builtin_popcountll
#define MOD 1000000007
#define INF 10000000000000000
// find_by_order(), order_of_key()
#define oset tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define fastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FORI(i,j,n) for(int i=j; i<=n; i++)
#define FOR(i, n) for(int i=0; i<n; i++)
#define all(a) a.begin(),a.end()
//#define mp make_pair
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
int arr[N];
bool visited[N];

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

void solve(string s){
    map<int, int> m;
    FOR(i, s.length()){
        m[s[i]]++;
    }

    int odd = 0;
    FOR(i, s.length()){
        if(m[s[i]]%2) odd++;
    }
    if(odd>1){
        cout<<"Impossible"<<endl;
        return;
    }

    int i=0, j=s.length()-1;
    int res=0;
    while(i<j){
        if(s[i] == s[j]) {
            i++, j--;
        }
        else{
            int x = i+1, y=j-1;
            while(x<j && s[x]!=s[j]) x++;
            while(y>i && s[y]!=s[i]) y--;

            if(x-i<=j-y){
                for(int p=x; p>i; p--){
                    swap(s[p], s[p-1]);
                    res++;
                }
            }
            else{
                for(int p=y; p<j; p++){
                    swap(s[p], s[p+1]);
                    res++;
                }
            }
            i++, j--;
        }
    }
    cout<<res<<endl;
}

signed main()
{
    fastIO
    while(1){
        string s;
        cin>>s;
        if(s=="0") break;
        solve(s);
    }
    return 0;
}

