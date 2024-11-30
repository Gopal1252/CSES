#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], int par, vector<int>& sub){
    for(auto & it : adj[node]){
        if(it == par) continue;
        dfs(it,adj,node,sub);
        sub[node] += (sub[it] + 1);
    }
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;

    vector<int> adj[n+1];
    for(int i=1;i<=n-1;i++){
        int boss;
        cin>>boss;
        adj[i+1].push_back(boss);
        adj[boss].push_back(i+1);
    }

    vector<int> sub(n+1);
    dfs(1,adj,-1,sub);

    for(int i=1;i<=n;i++){
        cout<<sub[i]<<" ";
    }

    return 0;
}