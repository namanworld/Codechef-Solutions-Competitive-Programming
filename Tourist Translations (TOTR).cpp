#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    int t;
    cin>>t;
    string dict;
    cin>>dict;
    while(t--){
        string test;
        cin>>test;
        for(int i=0; i<test.length(); i++){
            if(test[i]=='_') cout<<' ';
            else if(islower(test[i])){
                cout<<dict[test[i]-'a'];
            }
            else if(isupper(test[i])) cout<<(char)toupper(dict[tolower(test[i])-'a']);
            else cout<<test[i];
        }
        cout<<endl;
    }
    return 0;
}
