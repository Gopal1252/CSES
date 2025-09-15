#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int>& t, vector<int>& vis, vector<int>& pathVis, vector<int>& ans){
    vis[node] = 1;
    pathVis[node] = 1;

    int nxt = t[node];

    if(!vis[nxt]){
        dfs(nxt,t,vis,pathVis,ans);
        if(ans[node] == 0){//need to check the condition in order to avoid incrementing for nodes which are themselves a part of the cycle
            ans[node] = ans[nxt] + 1;
        }
    }
    else{
        if(pathVis[nxt]){
            int sz = 1;
            int curr = t[nxt];
            while(curr != nxt){
                sz++;
                curr = t[curr];
            }

            ans[curr] = sz;
            curr = t[curr];
            while(curr != nxt){
                ans[curr] = sz;
                curr = t[curr];
            }
        }
        else{
            ans[node] = ans[nxt] + 1;
        }
    } 

    pathVis[node] = 0;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;

    vector<int> t(n+1);
    for(int i=1;i<=n;i++){
        cin>>t[i]; 
    }

    vector<int> vis(n+1), pathVis(n+1), ans(n+1);

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,t,vis,pathVis,ans);
        }
    }

    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";


    return 0;
}