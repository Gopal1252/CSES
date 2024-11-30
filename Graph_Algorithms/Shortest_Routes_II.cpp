#include<bits/stdc++.h>
using namespace std;
//floyd warshall
#define ll long long
const ll INF = 1e18;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n,m,q;
    cin>>n>>m>>q;

    vector<vector<ll>> dist(n+1,vector<ll>(n+1,INF));

    for(int i=1;i<=n;i++){
        dist[i][i] = 0;
    }

    for(int i=0;i<m;i++){
        int u,v,z;
        cin>>u>>v>>z;

        if(z<dist[u][v]){
            dist[u][v] = z;
            dist[v][u] = z;
        }
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
            }
        }
    }

    for(int i=0;i<q;i++){
        int u,v;
        cin>>u>>v;
        if(dist[u][v] == INF){
            cout<<-1<<"\n";
        }
        else{
            cout<<dist[u][v]<<"\n";
        }
    }

    return 0;
}