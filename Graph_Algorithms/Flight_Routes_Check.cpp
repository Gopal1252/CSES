#include<bits/stdc++.h>
using namespace std;

//strongly connected components
//kosaraju algo
//need to check if the given graph is a SCC

//1) Do a DFS from any node and mark reachable nodes
//1.1) If not all nodes are visited, the graph is not strongly connected

//2) Reverse all edges in the graph

//3) Do a DFS from the same node again on the reversed graph
//3.1) If not all nodes are visited, the graph is not strongly connected

void dfs(int node, vector<vector<int>>& adj, vector<int>& vis){
    vis[node] = 1;

    for(auto & it : adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n+1,vector<int>()), adj2(n+1,vector<int>());

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj2[v].push_back(u);
    }

    vector<int> vis(n+1);

    dfs(1,adj,vis);

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            cout<<"NO\n";
            cout<<1<<" "<<i<<"\n";
            return 0;
        }
    }

    for(int i=1;i<=n;i++){
        vis[i] = 0;
    }

    dfs(1,adj2,vis);

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            cout<<"NO\n";
            cout<<i<<" "<<1<<"\n";
            return 0;
        }
    }
    cout<<"YES\n";

    return 0;
}