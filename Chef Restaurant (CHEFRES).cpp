#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<pair<int,int> > intervals;
        for(int i=0; i<n; i++){
            int l,r;
            cin>>l>>r;
            intervals.push_back({l, r});
        }

        sort(intervals.begin(), intervals.end());

        while(m--){
            int q;
            cin>>q;
            int position = lower_bound(intervals.begin(), intervals.end(), make_pair(q,0)) - intervals.begin();
            if(position == 0){
                cout<<intervals[0].first - q<<endl;
            }
            else{
                int ans = -1;
                if(intervals[position-1].second>q) ans = 0;
                else if(position < intervals.size()){
                    ans = intervals[position].first - q;
                }
                cout<<ans<<endl;
            }
        }

    }
    return 0;
}
