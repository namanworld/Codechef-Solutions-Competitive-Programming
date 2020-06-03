    #include <bits/stdc++.h>
    #define int long long
    #define INF 10000000000000
    #define MOD 1000000007
    using namespace std;

    int stair(int n, int k){
        if(k<=n) return k;
        else k = k-n;
        n--;
        int rem = k%n;
        if(((k/n)&1)==0) return n+1-rem;
        else return 1+rem;
    }

    signed main()
    {
        int t;
        cin>>t;
        while(t--){
            int n, k;
            cin>>n>>k;
            cout<<stair(n, k)<<endl;
        }
    }
