#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define MOD 1000000007
#define fastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2e5+5;
int a[N], b[N];
unordered_map<int, int> A;
unordered_map<int, int> B;
signed main()
{
    fastIO;
    int n, m;
    cin>>n>>m;
    for(int i=0; i<n; i++) {
            cin>>a[i];
            A[a[i]] = i;
    }
    for(int i=0; i<m; i++) {
            cin>>b[i];
            B[b[i]] = i;
    }
    sort(a, a+n);
    sort(b, b+m);

    int j = A[a[0]];

    for(int i=0; i<m; i++){
        cout<<j<<' '<<B[b[i]]<<endl;
    }
    j = B[b[m-1]];
    for(int i=1; i<n; i++){
        cout<<A[a[i]]<<' '<<j<<endl;
    }

    return 0;
}
