#include <bits/stdc++.h>
#define int long long
#define mid(s, e) ((s+e)/2)
#define MOD 1000000007
using namespace std;

int carsAtMax(int arr[], int n){
    int count = 1;
    int currMax = arr[0];
    for(int i=1; i<n; ++i){
        if(arr[i]>currMax){
            continue;
        }
        else{
            count++;
            currMax = arr[i];
        }
    }
    return count;
}

signed main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++) cin>>arr[i];

        cout<<carsAtMax (arr, n)<<"\n";
    }
    return 0;
}
