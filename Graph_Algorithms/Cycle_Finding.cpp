#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
//bellman-ford
//see this: https://chatgpt.com/share/68b5e4d7-b548-8013-8782-0e29c310ed7e
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    ll n,m;
    cin>>n>>m;
 
    vector<vector<ll>> edges;
 
    for(ll i=0;i<m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        edges.push_back({u,v,w});
    }
 
    vector<ll> dist(n+1,1e15);
    vector<ll> par(n+1,-1);
    dist[1] = 0;
 
    for(ll i=0;i<n-1;i++){
        for(auto & it : edges){
            ll u = it[0], v = it[1], w = it[2];
            if(dist[u]+w < dist[v]){
                dist[v] = dist[u]+w;
                par[v] = u;
            }
        }
    }
 
    bool flg = 0;
    ll x = -1;
    for(auto & it : edges){
        ll u = it[0], v = it[1], w = it[2];
        if(dist[u]+w < dist[v]){
            flg = 1;
            dist[v] = dist[u]+w;
            par[v] = u;
            x = v;
        }
    }
 
    if(flg){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
        return 0;
    }
    
 
    for(ll i=0;i<n;i++){
        x = par[x];
    }
 
    ll curr = x;
    vector<ll> ans;
    do{
        ans.push_back(curr);
        curr = par[curr];
    }while(curr != x);
 
    ans.push_back(x);
    reverse(ans.begin(),ans.end());
    for(auto & it: ans){
        cout<<it<<" ";
    }
    cout<<"\n";
 
    return 0;
}