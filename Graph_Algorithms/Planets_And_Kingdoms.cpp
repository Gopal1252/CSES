#include<bits/stdc++.h>
using namespace std;

//kosaraju
//strongly connected components

void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, stack<int>& st){
    vis[node] = 1;

    for(auto & it : adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis,st);
        }
    }
    st.push(node);
}

void dfs2(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& ans, int comp){
    vis[node] = 1;
    ans[node] = comp;

    for(auto & it : adj[node]){
        if(!vis[it]){
            dfs2(it,adj,vis,ans,comp);
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

    stack<int> st;
    vector<int> vis(n+1);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,adj,vis,st);
        }
    }

    for(int i=1;i<=n;i++){
        vis[i] = 0;
    }

    vector<int> ans(n+1);
    int comp = 0;

    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(!vis[node]){
            comp++;
            dfs2(node,adj2,vis,ans,comp);
        }
    }

    cout<<comp<<"\n";
    for(int i = 1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";

    return 0;
}