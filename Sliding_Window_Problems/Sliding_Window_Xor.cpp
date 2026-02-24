#include<bits/stdc++.h>
using namespace std;

#define ll long long
void solve(){
    ll n,k;
    cin>>n>>k;
    ll x,a,b,c;
    cin>>x>>a>>b>>c;

    vector<ll> v(n);

    ll currXor = 0;
    ll ansXor = 0;
    for(ll i=0;i<n;i++){
        if(i == 0){
            v[i] = x;
        }
        else{
            v[i] = ((v[i-1]*a)%c + b)%c;
        }
        
        currXor = currXor ^ v[i];

        if(i>=k-1){
            ansXor^=currXor;
            currXor = currXor ^ v[i-k+1];
        }
    }
    cout<<ansXor<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    solve();

    return 0;
}