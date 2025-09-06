#include<bits/stdc++.h>
using namespace std;

#define ll long long
//my solution
//TC:O(mklog(mk))
//SC:O(mk)
//explanation: https://chatgpt.com/s/t_68b929ea31948191953b9c63f38ceb41
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n,m,k;
    cin>>n>>m>>k;

    vector<pair<ll,ll>> adj[n+1];

    for(ll i=0;i<m;i++){
        ll a,b,c;
        cin>>a>>b>>c;

        adj[a].push_back({b,c});
    }

    vector<ll> cnt(n+1);
    cnt[1] = 1;

    multiset<pair<ll,ll>> st;
    st.insert({0,1});

    vector<ll> ans;

    while(!st.empty()){
        ll currDis = (*st.begin()).first;
        ll node = (*st.begin()).second;
        st.erase(st.begin());

        if(cnt[node] > k) continue;
        cnt[node]++;

        for(auto & it : adj[node]){
            ll nxt = it.first;
            ll wt = it.second;

            st.insert({currDis+wt,nxt});

            if(nxt == n){
                ans.push_back(currDis+wt);
            }
        }
    }

    sort(ans.begin(),ans.end());

    for(ll i=0;i<k;i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}