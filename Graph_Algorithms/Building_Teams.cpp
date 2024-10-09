#include<bits/stdc++.h>
using namespace std;

bool dfs(int i, bool col, vector<vector<int>>& adj, vector<int>& ans){
    ans[i] = col;
    for(auto & it : adj[i]){
        if(ans[it] == -1){
            if(!dfs(it,!col,adj,ans)){
                return false;
            }
        }
        else if(ans[it] == col){
            return false;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n,vector<int>());
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        u--;v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }



    vector<int> ans(n,-1);
    for(int i=0;i<n;i++){
        if(ans[i] == -1){
            if(!dfs(i,0,adj,ans)){
                cout<<"IMPOSSIBLE\n";
                return 0;
            }
        }
    }

    for(auto & it : ans){
        cout<<it+1<<" ";
    }
    cout<<"\n";

    return 0;
}