#include <bits/stdc++.h>
using namespace std;

char getChar(int i){
    return (char)(i+97);
}

void printPalindrome(string s){
    map<char, vector<int> > indexes;
    for(int i=0;i<s.length(); i++){
        indexes[s[i]].push_back(i);
    }

    int odd = 0;
    for(int i=0; i<26; i++){
        if((indexes[getChar(i)].size()%2)!=0){
            odd++;
        }
    }

    if(odd>=2){
        cout<<"-1";
        return;
    }

    int res[s.length()];
    int start = 0, end = s.length()-1;
    for(int i=0; i<26; i++){
        char currChar = getChar(i);
        for(int j=0; j<indexes[currChar].size(); j+=2){
            if((indexes[currChar].size()-j) == 1) {
                res[s.length()/2] = indexes[currChar][j];
                continue;
            }
            res[start] = indexes[currChar][j];
            res[end] = indexes[currChar][j+1];
            start++;
            end--;
        }
    }

    for(int i=0; i<s.length(); i++){
        cout<<res[i]+1<<" ";
    }
    return;

}

int main()
{
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        printPalindrome(s);
        cout<<endl;
    }
    return 0;
}
