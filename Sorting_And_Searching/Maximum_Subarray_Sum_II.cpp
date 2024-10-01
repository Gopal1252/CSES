#include<bits/stdc++.h>
using namespace std;
#define ll long long

//william lin's solution
//keep a set which contains the of the last (a,b) elements
//take the max subarray sum each time among the sums available
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n,a,b;
    cin>>n>>a>>b;

    vector<ll> v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i];
    }

    vector<ll> pref(n+1);
    for(ll i=0;i<n;i++){
        pref[i+1] = pref[i] + v[i];
    }

    set<pair<ll,ll>> st;//set keeps the subarray sums of size {a to b-1}
    ll ans = -1e18;

    for(int i=0;i<=n;i++){
        if(i>=a){
            st.insert({pref[i-a],i-a});
        }
        if(!st.empty()){
            ans = max(ans,pref[i] - (*st.begin()).first);
        }
        if(i>=b){
            st.erase({pref[i-b],i-b});
        }
    }
    cout<<ans;


    return 0;
}