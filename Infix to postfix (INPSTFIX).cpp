#include <bits/stdc++.h>
#define boost_io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define int long long
#define MOD 1000000007
using namespace std;

int PrecedenceValue(char a){
  if(a=='^'){
    return 3;
  }else if(a=='*'||a=='/'){
    return 2;
  }else if(a=='+'||a=='-'){
    return 1;
  }else{
    return 0;
  }
}

int checkPrecedence(char first_op, char second_op){
  return (PrecedenceValue(first_op)>PrecedenceValue(second_op));
}

void inToPost(string s, int n){
    stack<char> st;
    string res = "";
    for(int i=0; i<n; ++i){
        if(isalpha(s[i])) res+=s[i];
        else if(!st.empty()){
            if(s[i]=='(' || PrecedenceValue(s[i]) > PrecedenceValue(st.top())) st.push(s[i]);
            else{
                 while(!st.empty() && PrecedenceValue(s[i])<=PrecedenceValue(st.top()) && st.top()!='('){
                        res+=st.top();
                        st.pop();
                }
                if(s[i]==')') st.pop();
                else st.push(s[i]);
            }
        }
        else st.push(s[i]);
    }

    while(!st.empty()){
        res+=st.top();
        st.pop();
    }
    cout<<res<<endl;
}

signed main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        inToPost(s, n);
    }
    return 0;
}
I
