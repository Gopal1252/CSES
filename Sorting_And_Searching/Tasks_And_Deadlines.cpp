#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n;
    cin>>n;

    vector<pair<ll,ll>> v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
    }
    sort(v.begin(),v.end());
    ll t = 0;
    ll ans = 0;
    for(ll i=0;i<n;i++){
        t+=v[i].first;
        ans += v[i].second - t;
    }
    cout<<ans<<"\n";

    return 0;
}