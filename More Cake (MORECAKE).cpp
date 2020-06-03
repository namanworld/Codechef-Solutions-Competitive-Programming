#include <bits/stdc++.h>
#define int long long
#define INF 1000000000000
#define MOD 1000000007
using namespace std;


signed main()
{
    int t;
    cin>>t;
    int we_require = 0;

    while(t--){
        int n,s,k,r;
        cin>>s>>n>>k>>r;
        int slices_used = 0;
        for(int i=0; i<n; i++){
            slices_used+=k;
            k*=r;
        }
        if(s >= slices_used){
            cout<<"POSSIBLE "<<s-slices_used<<'\n';
            we_require += s-slices_used;
        }
        else{
            cout<<"IMPOSSIBLE "<<slices_used-s<<'\n';
            we_require-= slices_used - s;
        }
    }
    if(we_require>=0) cout<<"POSSIBLE"<<endl;
    else cout<<"IMPOSSIBLE"<<endl;
    return 0;
}

