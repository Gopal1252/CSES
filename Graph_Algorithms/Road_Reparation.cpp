#include<bits/stdc++.h>
using namespace std;

#define ll long long

//Minimum Spanning Tree

class dsu{
public:
    vector<ll> parent, sz;

    dsu(ll n){
        sz.resize(n+1,0);
        parent.resize(n+1);
        for(ll i=0;i<=n;i++){
            parent[i] = i;
        }
    }

    ll ultPar(ll v){
        if(v == parent[v]) return v;
        return parent[v] = ultPar(parent[v]);
    }

    void merge(ll u, ll v){
        u = ultPar(u);
        v = ultPar(v);

        if(u == v) return;

        if(sz[u] < sz[v]){
            parent[u] = v;
            sz[v] += sz[u];
        }
        else{
            parent[v] = u;
            sz[u] += sz[v];
        }
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n,m;
    cin>>n>>m;

    dsu ds(n);

    vector<vector<ll>> v;

    for(ll i=0;i<m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        v.push_back({c,a,b});
    }

    sort(v.begin(),v.end());

    ll totCost = 0;

    for(ll i=0;i<m;i++){
        ll cost = v[i][0];
        ll a = v[i][1], b = v[i][2];

        if(ds.ultPar(a) == ds.ultPar(b)) continue;

        totCost += cost;

        ds.merge(a,b);
    }

    ll par = -1;

    for(ll i=1;i<=n;i++){
        ll currPar = ds.ultPar(i);
        if(currPar != par){
            if(par == -1){
                par = currPar;
            }
            else{
                cout<<"IMPOSSIBLE\n";
                return 0;
            }
        }
    }
    cout<<totCost<<"\n";

    

    return 0;
}