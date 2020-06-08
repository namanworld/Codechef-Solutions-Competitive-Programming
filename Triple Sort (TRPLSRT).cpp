#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
#include <tuple>
int n, k;
int arr[200001];
bool visited[200001];

void solve(){
    cin>>n>>k;
    vector<pair<int, int> > doub;
    vector<tuple<int, int, int> > answer;
    for(int i=1; i<=n; i++) cin>>arr[i];
    memset(visited, 0, (n+1)*sizeof(bool));
    vector<int> cycle;
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            int j=1;
            while(!visited[j]){
                visited[j] = true;
                cycle.push_back(j);
                j = arr[j];
            }
        }
        while(cycle.size()>2){
            int z = cycle.back();
            cycle.pop_back();
            int y = cycle.back();
            cycle.pop_back();
            int x = cycle.back();
            if(cycle.size()==1){
                cycle.pop_back();
                answer.push_back(tie(x, y, z));
                k--;
            }
        }
        if(cycle.size()==2) doub.push_back({cycle[0], cycle[1]});
    }
    while(doub.size()>1){
            pair<int, int> one = doub.back();
            doub.pop_back();
            pair<int, int> sec = doub.back();
            doub.pop_back();
            answer.push_back(tie(one.second, sec.first, sec.second));
            answer.push_back(tie(one.first, one.second, sec.first));
            k-=2;
        }
        if(!doub.empty()) cout<<"-1"<<endl;
        if(k>=0){
            cout<<answer.size()<<endl;
            for(int i=0; i<answer.size(); ++i){
                cout<<get<0>(answer[i])<<" "<<get<1>(answer[i])<<" "<<get<2>(answer[i])<<endl;
            }
        }
        else cout<<"-1"<<endl;
        return;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
