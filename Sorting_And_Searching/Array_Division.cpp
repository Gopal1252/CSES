#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool isOk(ll mid, vector<ll> v, ll k){
    ll cnt = 0;
    ll sum = 0;
    int i = 0;
    while(i<v.size()){
        if(sum+v[i]>mid){
            cnt++;
            sum = 0;
        }
        else{
            sum+=v[i];
            i++;
        }
    }
    cnt++;
    if(cnt>k) return false;
    else return true;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n,k;
    cin>>n>>k;

    vector<ll> v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i];
        // if(i>0) v[i] += v[i-1];
    }

    ll lo = *max_element(v.begin(),v.end());
    ll hi = accumulate(v.begin(),v.end(),0ll);
    ll mid;

    while(hi-lo>1){
        mid = lo + (hi-lo)/2;

        if(isOk(mid,v,k)){
            hi = mid;
        }
        else{
            lo = mid+1;
        }
    }
    if(isOk(lo,v,k)){
        cout<<lo<<"\n";
    }
    else{
        cout<<hi<<"\n";
    }


    return 0;
}