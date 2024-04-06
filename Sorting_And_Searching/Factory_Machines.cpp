#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool ok(ll mid, vector<ll> &a, ll prod){
    ll cnt = 0;
    for(ll i=0;i<a.size();i++){
        cnt += mid/a[i];
        if(cnt>=prod) return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n,t;
    cin>>n>>t;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    ll lo = 1;
    ll hi = 1e18;
    ll mid;

    while(hi-lo>1){
        // mid = lo + floor((hi-lo)/2);// gave tle on some cases
        mid = lo + (hi-lo)/2;//works
        // mid = (lo + hi)/2;//works

        if(ok(mid,a,t)){
            hi = mid;
        }
        else{
            lo = mid+1;
        }
    }

    if(ok(lo,a,t)) cout<<lo;
    else cout<<hi;

    return 0;
}