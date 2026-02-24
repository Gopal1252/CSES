//check the notes in stack queue repo that i added (cp algo article is good)
#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){

    ll n,k;
    cin>>n>>k;
    ll x,a,b,c;
    cin>>x>>a>>b>>c;

    vector<ll> v(n);

    deque<int> q;//monotonically increasing queue (front has the minimum element always)
    ll ansXor = 0;
    for(ll i=0;i<n;i++){

        if(i == 0){
            v[i] = x;
        }
        else{
            v[i] = ((v[i-1]*a)%c + b)%c;
        }

        while(!q.empty() && q.back() > v[i]){
            q.pop_back();
        }
        q.push_back(v[i]);

        if(i>=k-1){
            ansXor^=q.front();
            if(!q.empty() && q.front() == v[i-k+1]){
                q.pop_front();
            }
        }
    }
    cout<<ansXor<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    solve();

    return 0;
}