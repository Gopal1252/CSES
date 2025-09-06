#include<bits/stdc++.h>
using namespace std;

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
    
    if(ans.size() == n){
        for(auto & it : ans){
            cout<<it<<" ";
        }
    }
    else{
        cout<<"IMPOSSIBLE\n";
    }

    return 0;
}