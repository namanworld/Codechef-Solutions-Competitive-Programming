#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define MOD 1000000007
#define fastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(n) for(int i=0; i<n; i++)

using namespace std;

const int N = 1e5+5;

void solve(int test){
    int n;
    cin>>n;
    int currSum=0, profit=0, i=0;
    for(i=1;;i++){
        currSum += n - pow(2,i-1);
        if(n-(int)pow(2,i)>0) profit = i+1;
        if(currSum<=0) break;
    }
    cout<<i-1<<' '<<profit<<endl;
}

signed main()
{
    int t;
    cin>>t;
    for(int i=1; i<=t; i++) solve(i);
    return 0;
}
