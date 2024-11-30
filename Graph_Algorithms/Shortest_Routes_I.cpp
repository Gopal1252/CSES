#include<bits/stdc++.h>
using namespace std;
//dijikstra
#define ll long long

const ll INF = 1e18;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n,m;
    cin>>n>>m;

    vector<vector<pair<int,int>>> g(n+1,vector<pair<int,int>>());

    for(int i=0;i<m;i++){
        int u,v,z;
        cin>>u>>v>>z;

        g[u].push_back({v,z});
    }

    vector<ll> dist(n+1,INF);

    set<pair<ll,int>> st;

    st.insert({0,1});
    dist[1] = 0;

    while(!st.empty()){
        auto node = *st.begin();
        st.erase(st.begin());
        ll currD = node.first;
        int currNode = node.second;

        for(auto & it : g[currNode]){
            int nxt = it.first;
            ll nextD = it.second;
            if(dist[currNode] + nextD < dist[nxt]){
                if(dist[nxt] != 1e18){//this line is a very important optimization
                    st.erase({dist[nxt],nxt});
                }
                dist[nxt] = dist[currNode] + nextD;
                st.insert({dist[nxt],nxt});
            }
        }
    }

    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
    cout<<"\n";



    return 0;
}