#include <bits/stdc++.h>
#define int long long
#define mid(s, e) ((s+e)/2)
#define MOD 1000000007
using namespace std;

int curr_max;

signed main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    sort(arr, arr+n);

    for(int i=0; i<n; i++){
        curr_max = max(curr_max, arr[i]*(n-i));
    }

    cout<<curr_max<<endl;

    return 0;
}
