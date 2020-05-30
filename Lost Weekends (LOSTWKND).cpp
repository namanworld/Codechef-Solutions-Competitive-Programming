#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int days[5];
        for(int i=0;i<5; ++i) cin>>days[i];

        int p;
        cin>>p;

        int s = 0;
        for(int i=0; i<5; ++i) {
                days[i]=p*days[i];
                s+=days[i];
        }

        if(s>120) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}

