#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n;
    cin>>n;

    vector<ll> v(n);
    map<ll,ll> mp;
    mp[0]++;
    ll sum = 0;
    ll ans = 0;
    for(ll i=0;i<n;i++){
        cin>>v[i];
        sum = (sum + v[i]%n + n)%n;//+n due to negative numbers
        ans += mp[sum];
        mp[sum]++;
    }
    cout<<ans<<"\n";



    return 0;
}