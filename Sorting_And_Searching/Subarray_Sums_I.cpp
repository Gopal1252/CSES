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
        if(i>0) v[i] += v[i-1];
    }

    map<ll,ll> mp;
    mp[0]++;
    ll ans = 0;
    for(int i=0;i<n;i++){
        ans += mp[v[i]-k];
        mp[v[i]]++;
    }
    cout<<ans<<"\n";

    return 0;
}