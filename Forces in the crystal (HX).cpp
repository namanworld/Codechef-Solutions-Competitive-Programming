#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

signed main()
{
    int n;
    cin>>n;
    int grid[n][n];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>grid[i][j];
    bool currRow = false;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(currRow) cout<<1<<" ";
            else cout<<0<<" ";
        }
        cout<<endl;
        currRow = !currRow;
    }

    return 0;
}
