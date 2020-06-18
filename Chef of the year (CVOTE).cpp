#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define MOD 1000000007
#define fastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int n, m;
unordered_map<string, int> countryVotes;
unordered_map<string, string> country;
unordered_map<string, int> votes;
string chef, cty;
vector<string> names, ctys;

signed main()
{
    fastIO;
    cin>>n>>m;
    int maxCtyVote = 0;
    for(int i=0; i<n; i++){
        cin>>chef>>cty;
        country[chef] = cty;
    }

    int maxVotes = 0;
    for(int i=0; i<m; i++){
        cin>>chef;
        votes[chef]++;
        countryVotes[country[chef]]++;
        maxVotes = max(maxVotes, votes[chef]);
        maxCtyVote = max(maxCtyVote, countryVotes[country[chef]]);
    }

    for(auto it=votes.begin(); it!=votes.end(); it++){
        if(it->second == maxVotes) {
                names.push_back(it->first);
        }
    }

    for(auto it=countryVotes.begin(); it!=countryVotes.end()/*&&curr!=maxCtyVote*/; it++){
        if(it->second==maxCtyVote) ctys.push_back(it->first);
    }

    sort(names.begin(), names.end());
    sort(ctys.begin(), ctys.end());
    cout<<ctys[0]<<endl;
    cout<<names[0]<<endl;

    return 0;
}
