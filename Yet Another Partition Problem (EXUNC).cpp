#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define MOD 1000000007
#define fastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(n) for(int i=0; i<n; i++)
using namespace std;
const int N = 1e6+5;
int n, q;
int arr[N];
set<int> par;

int pos(int x){
	auto it = par.upper_bound(x);
	it--;
	return *it;
}

void remove(int x){
    par.erase(x);
}

signed main()
{
    fastIO;
    cin>>n>>q;

    for(int i=1; i<=n; i++) cin>>arr[i];

    par.insert(1);
    for(int i=2; i<=n; i++){
        if(arr[i]%arr[i-1]==0) continue;
        par.insert(i);
    }



    int op, index;
    while(q--){
        cin>>op>>index;
        if(op==1){
            cin>>arr[index];
            if(index>1){
                if(pos(index)==index && arr[index]%arr[index-1]==0) remove(index);
                else if(pos(index)<index && arr[index]%arr[index-1]!=0) par.insert(index);
            }
            if(index<n){
                if(pos(index+1)>index && arr[index+1]%arr[index]==0) remove(index+1);
                else if(pos(index+1)<=index && arr[index+1]%arr[index]!=0) par.insert(index+1);
            }
        }
        else cout<<pos(index)<<endl;
    }

    return 0;
}
