#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;

    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    map<int,int> mp;
    int ans = 0;
    int curr = 0;
    int st = 0;
    for(int i=0;i<n;i++){
        if(mp.count(v[i]) == 0 || mp[v[i]] < st){
            curr++;
            ans = max(ans,curr);
        }
        else{
            curr -= (mp[v[i]] - st + 1);
            curr +=  1;
            st = mp[v[i]]+1;
        }
        mp[v[i]] = i;
    }
    cout<<ans<<"\n";

    return 0;
}