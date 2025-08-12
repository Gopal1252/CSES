//must do this question after this:
//https://leetcode.com/problems/difference-between-maximum-and-minimum-price-sum/description/
#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9+10;

void dfs(int node, int par, vector<vector<int>>& g, vector<int>& dis){
    for(auto & it : g[node]){
        if(it == par) continue;
        dis[it] = dis[node]+1;
        dfs(it,node,g,dis);
    }
}

void bfs(int start, vector<vector<int>>& g, vector<int>& dis){
    queue<int> q;
    q.push(start);
    dis[start] = 0;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto & it : g[node]){
            if(dis[it] == INF){
                dis[it] = dis[node]+1;
                q.push(it);
            }
        }
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

    vector<int> dis1(n,INF), dis2(n,INF);
    bfs(x1,g,dis1);
    bfs(x2,g,dis2);

    for(int i=0;i<n;i++){
        cout<<max(dis1[i],dis2[i])<<" ";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    solve();

    return 0;
}