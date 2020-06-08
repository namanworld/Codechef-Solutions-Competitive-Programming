#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

int fearx(int arr[], int n){
    stack<pair<int, int> > s;
    int fear = 1;
    for(int i=n-1;i>=0;i--){
        if(s.size()==0) fear*=1;
        else if(s.size()>0 && s.top().first < arr[i]){
            fear = ((fear)%MOD*(s.top().second-i)%MOD)%MOD;
        }
        else if(s.size()>0 && s.top().first>=arr[i]){
            while(s.size()>0 && s.top().first>=arr[i]) {
                    s.pop();
            }
            if(s.size()==0) fear*=1;
            else fear = ((fear)%MOD*(s.top().second-i)%MOD)%MOD;
        }
        s.push({arr[i], i+1});
    }
    return fear;
}

signed main()
{
    int n, k;
    cin>>n>>k;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<fearx(arr, n);
    return 0;
}
