#include<bits/stdc++.h>
using namespace std;

vector<int> par;

void dfs(int node, vector<int>& vis, vector<vector<int>>& adj, int parent = -1){
    vis[node] = 1;
    par[node] = parent;
    for(auto & it : adj[node]){
        if(it == parent) continue;
        if(vis[it] == 1){
            vector<int> ans;
            ans.push_back(it);
            int curr = node;
            while(curr != it){
                ans.push_back(curr);
                curr = par[curr];
            }
            ans.push_back(it);
            cout<<ans.size()<<"\n";
            for(auto & it : ans){
                cout<<it+1<<" ";
            }
            cout<<"\n";
            exit(0);
        }
        else dfs(it,vis,adj,node);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n,m;
    cin>>n>>m;

    par.resize(n);

    vector<vector<int>> adj(n,vector<int>());
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        u--;
        v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(n);

    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,vis,adj);
        }
    }

    cout<<"IMPOSSIBLE\n";


    return 0;
}