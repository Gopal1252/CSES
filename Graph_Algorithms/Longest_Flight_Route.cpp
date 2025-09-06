#include<bits/stdc++.h>
using namespace std;
 
//can't do with normal bfs
//longest paths need DAG DP
//and the longest path in a DAG depends on topological order, not BFS order
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int n,m;
    cin>>n>>m;
 
    vector<int> adj[n+1];
    vector<int> indeg(n+1);
 
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
 
        adj[u].push_back(v);
        indeg[v]++;
    }
 
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(indeg[i] == 0){
            q.push(i);
        }
    }
 
    vector<int> ans;
    while(!q.empty()){
        int node = q.front();
        q.pop();
 
        ans.push_back(node);
 
        for(auto & it : adj[node]){
            indeg[it]--;
            if(indeg[it]==0){
                q.push(it);
            }
        }
    }
    
    // if(ans.size() == n){
    //     for(auto & it : ans){
    //         cout<<it<<" ";
    //     }
    // }
    // else{
    //     cout<<"IMPOSSIBLE\n";
    // }
 
    vector<int> dis(n+1,0);
    dis[1] = 1;
 
    vector<int> par(n+1,-1);
 
    bool flg = 0;
    for(int i=0; i<ans.size();i++){
        int node = ans[i];
        if(node == 1){
            flg = 1;
        }
        if(flg && dis[node] != 0){
            for(auto & it : adj[node]){
                if(dis[it] < dis[node] + 1){
                    dis[it] = dis[node] + 1;
                    par[it] = node;
                }
            }
        }
    }
 
    if(dis[n] == 0){
        cout<<"IMPOSSIBLE";
    }
    else{
        cout<<dis[n]<<"\n";
        vector<int> ans;
        int curr = n;
        while(curr != 1){
            ans.push_back(curr);
            curr = par[curr];
        }
        ans.push_back(1);
        reverse(ans.begin(),ans.end());
        for(auto & it : ans){
            cout<<it<<" ";
        }
    }
 
    return 0;
}