#include<bits/stdc++.h>
using namespace std;

void dfs(int node, int par, vector<vector<int>>& g, vector<int>& isTaken, int& ans){

    bool isAvailable = false;
    for(auto & it : g[node]){
        if(it == par) continue;
        dfs(it,node,g,isTaken,ans);
        if(isTaken[it] == 0){
            isAvailable = true;
        }
    }
    if(isAvailable){
        isTaken[node] = 1;
        ans++;
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

    int ans = 0;
    vector<int> isTaken(n);
    dfs(0,-1,g,isTaken,ans);
    cout<<ans<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    solve();

    return 0;
}