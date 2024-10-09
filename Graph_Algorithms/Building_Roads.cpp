#include<bits/stdc++.h>
using namespace std;

class dsu{
    public:
    vector<int> par,sz;

    dsu(int n){
        par.resize(n+1);
        sz.resize(n+1,1);
        for(int i=1;i<=n;i++){
            par[i] = i;
        }
    }

    int fpar(int v){
        if(par[v] == v) return v;
        return par[v] = fpar(par[v]);
    }

    void merge(int u, int v){
        int paru = fpar(u);
        int parv = fpar(v);
        if(paru == parv) return;

        if(sz[paru] <= sz[parv]){
            par[paru] = parv;
            sz[parv] += sz[paru];
        }
        else{
            par[parv] = paru;
            sz[paru] += sz[parv];
        }
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n,m;
    cin>>n>>m;

    dsu ds(n);


    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        ds.merge(u,v);
    }

    int ans = 0;
    vector<int> v;
    for(int i=1;i<=n;i++){
        if(ds.par[i] == i){
            ans++;
            v.push_back(i);
        }
    }
    cout<<ans-1<<"\n";
    for(int i=0;i<v.size()-1;i++){
        cout<<v[i]<<" "<<v[i+1]<<"\n";
    }


    return 0;
}