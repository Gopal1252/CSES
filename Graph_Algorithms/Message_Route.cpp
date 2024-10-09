#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9+7;

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

    vector<int> vis(n);
    vector<int> dis(n,INF);
    vector<int> path(n);

    queue<int> q;
    q.push(0);
    vis[0] = 1;
    dis[0] = 1;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto & it : adj[node]){
            if(!vis[it]){
                vis[it] = 1;
                q.push(it);
                dis[it] = dis[node] + 1;
                path[it] = node;
            }
        }
    }

    if(dis[n-1] == INF){
        cout<<"IMPOSSIBLE\n";
    }
    else{
        cout<<dis[n-1]<<"\n";
        vector<int> ans;
        ans.push_back(n-1);
        int curr = n-1;
        while(curr != 0){
            ans.push_back(path[curr]);
            curr = path[curr];
        }
        reverse(ans.begin(),ans.end());
        for(auto & it : ans){
            cout<<it+1<<" ";
        }
        cout<<"\n";
    }


    return 0;
}