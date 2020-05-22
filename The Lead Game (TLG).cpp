#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;

    int cumA =0, cumB =0, lead =0, currLeader = 1;
    for(int i=0; i<n; i++){
        int x, y;
        cin>>x>>y;
        cumA+=x, cumB+=y;
        if(cumA > cumB){
            if(cumA-cumB > lead){
                lead = cumA-cumB;
                currLeader = 1;
            }
        }
        else{
            if(cumB-cumA > lead){
                lead = cumB-cumA;
                currLeader = 2;
            }
        }
    }

    cout<< currLeader<<" "<<lead<<endl;

    return 0;
}
