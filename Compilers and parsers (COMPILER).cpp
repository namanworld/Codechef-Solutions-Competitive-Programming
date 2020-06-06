#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

int validLength(string s){
    stack<char> st;
    int counter = 0, temp_counter = 0;
    for(int i=0; i<s.length(); i++){
        if(s[i]=='<') st.push(s[i]);
        else{
            if(st.empty()) {
                    break;
                }

            else if(st.top()=='<'){
                temp_counter+=2;
                st.pop();
            }
            if(st.empty()){
                counter+=temp_counter;
                temp_counter = 0;
            }
            else if(st.top()=='>') break;
        }
    }
    if(st.empty()||st.top()=='<') return counter;
    else return 0;
}

signed main()
{
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        cout<<validLength(s)<<'\n';
    }
    return 0;
}
