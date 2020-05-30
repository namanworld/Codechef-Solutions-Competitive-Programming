#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll wierdWalk(ll A[], ll B[], int n){
    ll sA = 0, sB = 0, dist = 0;
    for(int i=0; i<n; ++i){
        sA+=A[i];
        sB+=B[i];
        if(sA == sB && A[i]==B[i]) dist+=A[i];
    }
    return dist;
}

int main()
{
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        ll A[n], B[n];
        for(int i=0; i<n; ++i) cin>>A[i];
        for(int i=0; i<n; ++i) cin>>B[i];

        cout<<wierdWalk(A, B, n)<<"\n";

    }
    return 0;
}
