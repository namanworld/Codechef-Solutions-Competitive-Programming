#include <bits/stdc++.h>
using namespace std;

int variation(int arr[], int n, int k){
    int i=0, j=1, count=0;
    while(j<n){
        if(i==j) j++;
        if(arr[j]-arr[i]>=k) {
                i++;
                count+=n-j;
        }
        else j++;
    }
    return count;
}

int main()
{
    int n, k;
    cin>>n>>k;

    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    sort(arr, arr+n);

    cout<<variation(arr, n, k);

    return 0;
}
