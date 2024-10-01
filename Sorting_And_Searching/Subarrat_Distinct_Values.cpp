#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n,k;
    cin>>n>>k;

    vector<ll> v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i];
    }

    map<ll,ll> mp;
    ll i = 0, j = 0;
    ll ans = 0;
    while(j<n){
        mp[v[j]]++;
        while(mp.size()>k){
            mp[v[i]]--;
            if(mp[v[i]] == 0) mp.erase(v[i]);
            i++;
        }
        ans+=(j-i+1);
        j++;
    }
    cout<<"\n";
    cout<<ans<<"\n";



    return 0;
}