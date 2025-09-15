#include<bits/stdc++.h>
using namespace std;

#define ll long long

class dsu{
public:
    vector<ll> parent, sz;

    dsu(ll n){
        sz.resize(n+1,1);
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

    dsu ds(n+1);

    ll comps = n, mxSize = 1;

    for(ll i=0;i<m;i++){
        ll u,v;
        cin>>u>>v;

        u = ds.ultPar(u);
        v = ds.ultPar(v);

        if(u == v){
            cout<<comps<<" "<<mxSize<<"\n";
            continue;
        }

        ds.merge(u,v);

        comps--;
        mxSize = max(mxSize,max(ds.sz[u],ds.sz[v]));
        cout<<comps<<" "<<mxSize<<"\n";
    }

    return 0;
}