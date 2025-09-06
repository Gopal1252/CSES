#include<bits/stdc++.h>
using namespace std;
//using a parent array
bool dfs(int node, vector<int> adj[], vector<int>& vis, vector<int>& pathVis, vector<int>& par){
    vis[node] = 1;
    pathVis[node] = 1;
 
    for(auto & it : adj[node]){
 
        if(!vis[it]){
            par[it] = node;
            if(dfs(it,adj,vis,pathVis,par)){
                return true;
            }
        }
        else if(pathVis[it]){
 
            vector<int> ans;
            ans.push_back(it);
 
            int curr = node;
            while(curr != it){
                ans.push_back(curr);
                curr = par[curr];
            }
            ans.push_back(it);
 
            cout<<ans.size()<<"\n";
            reverse(ans.begin(),ans.end());
            for(auto & it : ans){
                cout<<it<<" ";
            }
 
            return true;
        }
 
        
    }
    pathVis[node] = 0;
    return false;
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int n,m;
    cin>>n>>m;
 
    vector<int> adj[n+1];
 
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
 
        adj[u].push_back(v);
    }
 
    vector<int> vis(n+1), pathVis(n+1), par(n+1,-1);
 
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(dfs(i,adj,vis,pathVis, par)){
                return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE\n";
 
 
    return 0;
}