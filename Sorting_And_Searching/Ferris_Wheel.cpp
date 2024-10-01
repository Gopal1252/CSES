#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n,x;
    cin>>n>>x;

    vector<ll> v(n);
    for(ll i=0;i<n;i++) cin>>v[i];

    sort(v.begin(),v.end());

    ll i = 0, j = n-1;
    ll ans = 0;
    while(i<j){
        if(v[i] + v[j] > x){
            j--;
            ans++;
        }
        else{
            i++;
            j--;
            ans++;
        }
    }
    if(i == j) ans++;
    cout<<ans<<"\n";

    return 0;
}