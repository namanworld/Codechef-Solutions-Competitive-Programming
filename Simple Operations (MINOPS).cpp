#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

signed main()
{
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        string t;
        cin>>t;
        vector<int> gaps;
        int k = 0, l = 0, gl = 0;
        bool flag = false;
        for(int i=0; i<s.length(); ++i){
            if(s[i]==t[i]){
                if(flag) gl++;
            }
            else{
                if(!flag) {
                    k++;
                    flag = true;
                }
                l++;
                if(gl>0){
                    k++;
                    gaps.push_back(gl);
                    gl = 0;
                }
            }
        }
        sort(gaps.begin(), gaps.end());
        int res = k*l;
        for(int i=0; i<gaps.size(); ++i){
            l+=gaps[i];
            k--;
            res = min(res, k*l);
        }
        cout<<res<<endl;
    }
    return 0;
}
