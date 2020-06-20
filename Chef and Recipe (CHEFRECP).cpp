#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define endl '\n'
#define MOD 1000000007
#define oset tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define fastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(n) for(int i=0; i<n; i++)

using namespace __gnu_pbds;
using namespace std;

const int N = 1e3+5;
int arr[N];
int freq[N];

void solve(int test){
    int n;
    cin>>n;
    bool ans = true;
    FOR(n) cin>>arr[i];
    memset(freq, 0, sizeof(freq));

    FOR(n){
        if(i==0 || arr[i]==arr[i-1]){
            freq[arr[i]]++;
        }
        else if(arr[i]!=arr[i-1]){
            if(freq[arr[i]]>0){
                ans = false;
                break;
            }
            freq[arr[i]]++;
        }
    }
    
    if(!ans){
        cout<<"NO"<<endl;
        return;
    }

    set<int> s;
    FOR(N){
        auto it = s.find(freq[i]);
        if(freq[i]>0 && it==s.end()) s.insert(freq[i]);
        else if(it!=s.end()){
            ans = false;
            break;
        }
    }

    if(ans) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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
