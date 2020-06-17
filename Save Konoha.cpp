#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define MOD 1000000007
#define fastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e4+5;
int n, z, p;

void solve(int test){
    cin>>n;
    cin>>z;
    int powers[N]={0};
    for(int i=0; i<n; i++){
        cin>>p;
        powers[p]++;
    }

    int count = 0;
    for(int i=10000; i>0 && z>0 ; i--){
        while(powers[i]>0&&z>0){
            count++;
            z-=i;
            powers[i/2]++;
            powers[i]--;
        }
    }
    if(z>0) cout<<"Evacuate"<<endl;
    else cout<<count<<endl;
}

signed main()
{
    int t;
    cin>>t;
    for(int i=1; i<=t; i++) solve(i);
    return 0;
}
