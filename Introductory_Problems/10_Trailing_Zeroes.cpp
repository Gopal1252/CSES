#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll power(ll n, ll a){
    ll ans = 0;
    ll p = a;
    while(p<=n){
        ans += n/p;
        p = p*a;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n;
    cin>>n;
    cout<<min(power(n,2),power(n,5));
    
    return 0;
}