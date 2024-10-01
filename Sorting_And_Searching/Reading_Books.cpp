#include<bits/stdc++.h>
using namespace std;

#define ll long long

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n;
    cin>>n;
    vector<ll> v(n);
    ll sum = 0;
    for(ll i=0;i<n;i++){
        cin>>v[i];
        sum += v[i];
    }

    sort(v.begin(),v.end());

    //if the time for biggest book is greater than all the other books, the ans = 2*(time for biggest book)
    //else ans = total time
    cout<<max(sum,2*v[n-1])<<"\n";

    return 0;
}