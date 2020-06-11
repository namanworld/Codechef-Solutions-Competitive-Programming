NAIVE APPROACH:
One of the simplest is a string of the form: abcabcabcabcabcabc.... It’s easy to see why it doesn’t have any palindromic substring of length > 1>1: any substring of length > 1>1 has at least one of the following substrings: ab, bc, and ca. But the reversals of these substrings don’t appear anywhere in the string!

Thus, a very, very simple solution arises: Simply print a string of the form abcabcabcabcabcabc... of length N!
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int k = n/3;
        while(k--){
            cout<<"abc";
        }
        k = n%3;
        if(k==1) cout<<"a";
        if(k==2) cout<<"ab";
        cout<<endl;
    }
    return 0;
}


BEST APPROACH:

#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

const int MAXN = 10000 + 100;
const int MAXK = 100;

int tn;
int dp[MAXK][MAXN], par[MAXK][MAXN];

int main(int argc, const char * argv[]) {
    
    for(int i = 0; i < MAXK; i++)
        for(int j = 0; j < MAXN; j++)
            dp[i][j] = 0;
    dp[0][0] = 1;
    for(int i = 0; i + 1 < MAXK; i++) for(int j = 0; j < MAXN; j++) if (dp[i][j]) {
        for(int k = 1; j + k * (k + 1) / 2 < MAXN; k++) {
            dp[i + 1][j + k * (k + 1) / 2] = 1;
            par[i + 1][j + k * (k + 1) / 2] = k;
        }
    }
    
    cin >> tn;
    while (tn--) {
        int n;
        cin >> n;
        int p1 = -1, p2 = -1;
        for(int i = 1; i < MAXK; i++) if (dp[i][n]) {
            p1 = i;
            p2 = n;
            break;
        }
        assert(p1 != -1);
        string ans = "";
        while (p1 > 0) {
            for(int i = 0; i < par[p1][p2]; i++)
                ans += ('a' + p1);
            p2 -= par[p1][p2] * (par[p1][p2] + 1) / 2;
            --p1;
        }
        cout << ans << endl;
    }
    return 0;
}
