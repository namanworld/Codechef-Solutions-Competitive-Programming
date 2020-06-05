#include <bits/stdc++.h>
#include <map>
#define int long long
#define MOD 1000000007
#define INF 10000000000000
using namespace std;



signed main()
{
    int t;
    cin>>t;
    map<int, int> mapx;
    mapx[0] = INF;
    mapx[5] = 0;
    mapx[10] = 0;
    mapx[15] = 0;
    while(t--){
        int n;
        cin>>n;
        bool found = true;
        for(int i=0; i<n; i++){
            int curr;
            cin>>curr;
            if(found){
                int rem = curr-5;
                if(rem==10){
                    if(mapx[rem]>0){
                        mapx[rem]--;
                        mapx[curr]++;
                    }
                    else if(mapx[rem/2]>1){
                        mapx[rem/2]-=2;
                        mapx[curr]++;
                    }
                    else found = false;
                    continue;
                }
                if(rem==5){
                    if(mapx[rem]>0){
                        mapx[rem]--;
                        mapx[curr]++;
                    }
                    else found = false;
                }
                if(rem==0) mapx[curr]++;
            }
        }
        if(found) cout<<"YES\n";
        else cout<<"NO\n";
        mapx[5] = 0;
        mapx[10] = 0;
        mapx[15] = 0;
    }
    return 0;
}
