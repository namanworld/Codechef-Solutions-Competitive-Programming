#include <bits/stdc++.h>
#define int long long
using namespace std;

void matched(int n){
    int nestingDepth = 0, nestingDepthIndex = 0, maxSequence = 0, maxSequenceIndex = 0, countSeq = 0, currIndex = 1;
    stack<int> s;
    for(int i=0; i<n; ++i){
        int x;
        cin>>x;
        countSeq++;
        if(x==1){
            s.push(x);
        }
        else{
            if(s.size()>nestingDepth){
                nestingDepth = s.size();
                nestingDepthIndex = i;
            }
            s.pop();
            if(s.empty()){
                if(countSeq > maxSequence){
                    maxSequence = countSeq;
                    maxSequenceIndex = currIndex;
                }
                currIndex = i+2;
                countSeq = 0;
            }
        }
    }
    cout<<nestingDepth<<" "<<nestingDepthIndex<<" "<<maxSequence<<" "<<maxSequenceIndex;
}

signed main()
{
    int n;
    cin>>n;
    matched(n);
    return 0;
}
