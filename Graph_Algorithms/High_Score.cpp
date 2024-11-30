#include<bits/stdc++.h>
using namespace std;
//bellman ford
//will negate all the edge weights and calculate the minimum score using bellman ford
//the added point here is that what if the negative weight cycle is not between 1 and n, i.e what if it doesn't come in the path from one to n
//so we need to ensure that the edge that gives is the -ve weight cycle (when checking in the nth iteration) is a part of the path from 1 to n or not
//if it is a part, then we will return -1
//however if it is not a part, then we will return t=our answer

//saw these 2 vid -->
//https://www.youtube.com/watch?v=WMTIoCkVFw4&ab_channel=HiteshTripathi
//https://www.youtube.com/watch?v=DojVgr-qlfo&ab_channel=YouLearn
//code of 1st and starting explanation of the 2nd
#define ll long long

void dfs(int node, vector<int>& vis, vector<vector<int>>& g){
    vis[node] = 1;
    for(auto & it : g[node]){
        if(!vis[it]){
            dfs(it,vis,g);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n,m;
    cin>>n>>m;

    vector<vector<int>> edges;
    vector<vector<int>> adj1(n+1,vector<int>());//graph {do dfs starting from 1 (To get all the nodes reachable from 1)}
    vector<vector<int>> adj2(n+1,vector<int>());//reverse graph {do dfs starting from n (To get all the nodes reachable from n)}

    for(int i=0;i<m;i++){
        int u,v,z;
        cin>>u>>v>>z;
        edges.push_back({u,v,-z});
        adj1[u].push_back(v);
        adj2[v].push_back(u);
    }

    vector<int> vis1(n+1),vis2(n+1);

    dfs(1,vis1,adj1);
    dfs(n,vis2,adj2);

    vector<ll> dis(n+1,1e18);
    dis[1] = 0;

    for(int i=0;i<n-1;i++){
        for(auto & it : edges){
            int u = it[0];
            int v = it[1];
            int d = it[2];

            if(dis[u] != 1e18 && dis[u] + d < dis[v]){
                dis[v] = dis[u] + d;
            }
        }
    }

    for(auto & it : edges){
        int u = it[0];
        int v = it[1];
        int d = it[2];

        if(vis1[u] && vis2[v] && dis[u] + d < dis[v]){//vis1[u] && vis2[v] means u -->  v comes in the path from 1 to n
            cout<<-1<<"\n";
            return 0;
        }
    }

    cout<<-dis[n]<<"\n";



    return 0;
}