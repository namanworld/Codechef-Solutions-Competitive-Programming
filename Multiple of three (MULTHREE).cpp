#include <bits/stdc++.h>
#define mid(l,u) ((l+u)/2)
#define MOD 1000000007
#define INF 10000000000000
#define int long long
using namespace std;

bool mulofthree(int n, int a, int b){
    int sum = a+b;
    if(sum==1 || sum%10==0 || sum%10==5) return false;
    if(n==2) sum = a+b;
    else{
        sum+=sum%10;
        int rem = (n-3)>=0 ? (n-3)%4 : 0;
        int q = (n-3)>=0 ? (n-3)/4 : 0;
        sum+=q*20;
        while(rem--){
            sum+=sum%10;
        }
    }
    if(sum % 3==0) return true;
    else return false;
}

signed main()
{
    int t;
    cin>>t;

    while(t--){
        int n, a, b;
        cin>>n>>a>>b;
        if(mulofthree(n,a,b)) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
