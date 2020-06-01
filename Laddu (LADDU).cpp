#include <bits/stdc++.h>
#define int long long
#define mid(l,u) ((l+u)/2)
#define MOD 1000000007
#define INF 10000000000000
using namespace std;


signed main()
{
    int t;
    cin>>t;
    while(t--){
        int ActNo;
        cin>>ActNo;
        int laddus = 0;
        int minLaddus = 200;
        string nationality;
        cin>>nationality;
        if(nationality == "NON_INDIAN") minLaddus = 400;
        for(int i=0; i<ActNo; ++i){
            string act;
            cin>>act;
            if(act=="CONTEST_WON"){
                int rank;
                cin>>rank;
                if(rank>20) laddus+=300;
                else laddus+=320-rank;
            }
            else if(act=="BUG_FOUND"){
                int bugs;
                cin>>bugs;
                laddus+=bugs;
            }
            else if(act=="TOP_CONTRIBUTOR") laddus+=300;
            else if(act=="CONTEST_HOSTED") laddus+=50;
        }

        cout<<laddus/minLaddus<<endl;

    }
    return 0;
}
