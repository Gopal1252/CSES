#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n,m;
    cin>>n>>m;

    vector<int> v(n+1);
    vector<int> pos(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
        pos[v[i]] = i;
    }
    int ans = 1;
    for(int i=1;i<n;i++){
        if(pos[i]>pos[i+1]) ans++;//answer is equal to number of inversions considering pairwise consecutive numbers
    }

    set<pair<int,int>> upd;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        // cout<<a<<" "<<b<<"\n";
        if(v[a]+1<=n){
            upd.insert({v[a],v[a]+1});
        }
        if(v[a]-1>=1){
            upd.insert({v[a]-1,v[a]});
        }
        if(v[b]+1<=n){
            upd.insert({v[b],v[b]+1});
        }
        if(v[b]-1>=1){
            upd.insert({v[b]-1,v[b]});
        }

        for(auto it : upd){
            ans -= (pos[it.first] > pos[it.second]);
        }

        swap(v[a],v[b]);
        pos[v[a]] = a;
        pos[v[b]] = b;

        for(auto it : upd){
            ans += (pos[it.first] > pos[it.second]);
        }

        cout<<ans<<"\n";

        upd.clear();
    }



    return 0;
}