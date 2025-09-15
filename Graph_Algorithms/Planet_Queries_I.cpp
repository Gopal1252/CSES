#include<bits/stdc++.h>
using namespace std;

//binary lifting/jumping

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n,q;
    cin>>n>>q;

    vector<vector<int>> t(32,vector<int>(n));
    for(int i=0;i<n;i++){
        cin>>t[0][i];
        t[0][i]--;
    }

    for(int j=1;j<=31;j++){
        for(int i=0;i<n;i++){
            t[j][i] = t[j-1][t[j-1][i]];
        }
    }

    while(q--){
        int x,k;
        cin>>x>>k;
        x--;

        for(int i=0;i<=31;i++){
            if(k&(1<<i)){
                x = t[i][x];
            }
        }
        cout<<x+1<<"\n";
    }

    return 0;
}