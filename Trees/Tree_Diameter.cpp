#include<bits/stdc++.h>
using namespace std;

void dfs(int node, int par, vector<vector<int>>& g, vector<int>& dis){
    for(auto & it : g[node]){
        if(it == par) continue;
        dis[it] = dis[node]+1;
        dfs(it,node,g,dis);
    }
}

void solve(){
    int n;
    cin>>n;
    vector<vector<int>> g(n,vector<int>());
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        a--,b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> dis(n);
    dfs(0,-1,g,dis);

    int x1 = -1;
    int mx = -1;
    for(int i=0;i<n;i++){
        if(mx<dis[i]){
            mx = dis[i];
            x1 = i;
        }
        dis[i] = 0;
    }

    dfs(x1,-1,g,dis);

    int x2 = -1;
    mx = -1;
    for(int i=0;i<n;i++){
        if(mx<dis[i]){
            mx = dis[i];
            x2 = i;
        }
    }

    cout<<mx<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    solve();

    return 0;
}