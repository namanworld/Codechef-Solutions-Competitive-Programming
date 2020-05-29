#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int A[N];
int prefix[N][6];

int prime_factor[N+5];
vector<pair<int, int> > prime_factors[N+5];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    for(int i=2; i<N; i++){
        if(prime_factor[i]!=0) continue;
        prime_factor[i] = i;
        for(int j=2*i; j<N; j+=i) prime_factor[j] = i;
    }

    for(int i=2; i<N; i++){
        int x = i;
        map<int, int> M;
        while(x!=1){
            M[prime_factor[x]]++;
            x/=prime_factor[x];
        }
        for(auto v:M) prime_factors[i].push_back(v);
    }

    for(int i=1; i<N; i++) A[i] = prime_factors[i].size();

    for(int i=1; i<N; i++){
        for(int k=1; k<=5; k++){
            prefix[i][k] = prefix[i-1][k] + (A[i]==k);
        }
    }

    int t;
    cin>>t;

    while(t--){
        int l, r, k;
        cin>>l>>r>>k;
        cout<<prefix[r][k]-prefix[l-1][k]<<'\n';
    }

    return 0;
}
