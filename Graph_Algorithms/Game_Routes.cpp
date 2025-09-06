#include<bits/stdc++.h>
using namespace std;

const int M = 1e9+7;

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
 
    vector<int> topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();
 
        topo.push_back(node);
 
        for(auto & it : adj[node]){
            indeg[it]--;
            if(indeg[it]==0){
                q.push(it);
            }
        }
    }

    vector<int> ways(n+1);//ways[i] stores the number of ways to reach node i from node 1
    ways[1] = 1;

    for(int i=0;i<topo.size();i++){
        int node = topo[i];
        if(ways[node] == 0) continue;
        for(auto & it : adj[node]){
            ways[it] = (ways[it] + 0LL + ways[node])%M;
        }
    }

    cout<<ways[n]<<"\n";

    return 0;
}