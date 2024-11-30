#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll INF = 1e18;

//William Lin Solution
//just calculate the distance of each node form 1 (using noral graph) and from m (using the reversed graph)
//then go to each possible edge and calculate the maximum discount we can get

void dij(int startNode, vector<ll>& dist,vector<vector<pair<int,int>>>& g){
    set<pair<ll,int>> st;
    st.insert({0,startNode});
    dist[startNode] = 0;

    while(!st.empty()){
        auto node = *st.begin();
        st.erase(st.begin());

        ll currDis = node.first;
        int currNode = node.second;

        for(auto & it : g[currNode]){
            int nxt = it.first;
            ll dis = it.second;

            if(dist[currNode] + dis < dist[nxt]){
                if(dist[nxt] != INF){
                    st.erase({dist[nxt],nxt});
                }

                dist[nxt] = dist[currNode] + dis;
                st.insert({dist[nxt],nxt});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n,m;
    cin>>n>>m;

    vector<vector<pair<int,int>>> g1(n+1,vector<pair<int,int>>());//normal graph
    vector<vector<pair<int,int>>> g2(n+1,vector<pair<int,int>>());//reverse graph

    for(int i=0;i<m;i++){
        int u,v,z;
        cin>>u>>v>>z;

        g1[u].push_back({v,z});
        g2[v].push_back({u,z});

    }

    vector<ll> dist1(n+1,INF);
    vector<ll> dist2(n+1,INF);

    dij(1,dist1,g1);
    dij(n,dist2,g2);

    ll ans = INF;
    for(int i=1;i<=n;i++){
        for(auto & it : g1[i]){
            ans = min(ans,dist1[i] + dist2[it.first] + it.second/2);
        }
    }
    cout<<ans<<"\n";

    return 0; 
}