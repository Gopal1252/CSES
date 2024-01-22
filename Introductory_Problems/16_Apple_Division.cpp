#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll ans = LLONG_MAX;
void solve(int ind,vector<ll>& v, ll sum, ll otherSum){
    if(ind == v.size()){
        ans = min(ans,abs(sum-otherSum));
        return;
    }
    solve(ind+1,v,sum-v[ind],otherSum+v[ind]);
    solve(ind+1,v,sum,otherSum);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;
    vector<ll> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    ll sum = accumulate(v.begin(),v.end(),0LL);
    solve(0,v,sum,0);
    cout<<ans;


    return 0;
}