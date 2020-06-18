#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define MOD 1000000007
#define fastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;
const int N = 1e5+5;

int n, m, k;

void solve(int test){
    vector<pair<int, int>> v;
    map<pair<int, int>, bool> p;
    cin>>n>>m>>k;
    int a, b;
    while(k--){
        cin>>a>>b;
        v.push_back(make_pair(a,b));
        p[make_pair(a, b)] = true;
    }
    int ans = 0;
    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++){
        ans+=4;
        pair<int, int> x = v[i];
        if(p.count(make_pair(x.first-1, x.second))) ans-=2;
        if(p.count(make_pair(x.first, x.second-1))) ans-=2;
    }
    cout<<ans<<endl;
}

signed main()
{
    int t;
    cin>>t;
    for(int i=1; i<=t; i++){
        solve(i);
    }
    return 0;
}
