#include<bits/stdc++.h>
using namespace std;

#define ll long long

const ll M = 1e9+7;

const ll INF = 1e18;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n,m;
    cin>>n>>m;

    vector<pair<ll,ll>> adj[n+1];

    for(ll i=0;i<m;i++){
        ll u,v,w;
        cin>>u>>v>>w;

        adj[u].push_back({v,w});
    }

    vector<ll> dis(n+1,INF), ways(n+1,0), minFlights(n+1,INF), maxFlights(n+1,0);
    dis[1] = 0;
    ways[1] = 1;
    minFlights[1] = maxFlights[1] = 0;

    set<pair<ll,ll>> st;
    st.insert({0,1});

    while(!st.empty()){
        ll currDis = (*st.begin()).first;
        ll curr = (*st.begin()).second;
        st.erase(st.begin());

        for(auto & it : adj[curr]){
            ll nxt = it.first;
            ll wt = it.second;

            if(dis[curr] + wt < dis[nxt]){
                if(dis[nxt] != INF){
                    st.erase({dis[nxt],nxt});
                }
                dis[nxt] = dis[curr] + wt;
                ways[nxt] = ways[curr];
                minFlights[nxt] = minFlights[curr]+1;
                maxFlights[nxt] = maxFlights[curr]+1;

                st.insert({dis[nxt],nxt});
            }
            else if(dis[curr] + wt == dis[nxt]){
                ways[nxt] = (ways[nxt] + 0LL + ways[curr])%M;
                minFlights[nxt] = min(minFlights[nxt],minFlights[curr]+1);
                maxFlights[nxt] = max(maxFlights[nxt],maxFlights[curr]+1);
            }
        }
    }

    cout<<dis[n]<<" "<<ways[n]<<" "<<minFlights[n]<<" "<<maxFlights[n]<<"\n";



    return 0;
}