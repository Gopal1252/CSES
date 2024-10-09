#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> mov = {{-1,0},{1,0},{0,-1},{0,1}};
void dfs(int ii, int jj, vector<string>& v, vector<vector<int>>& vis){
    int n = v.size();
    int m = v[0].size();
    vis[ii][jj] = 1;
    for(int k=0;k<4;k++){
        int i = ii + mov[k].first;
        int j = jj + mov[k].second;
        if(i>=0 && i<n && j>=0 && j<m && !vis[i][j] && v[i][j] != '#'){
            dfs(i,j,v,vis);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n,m;
    cin>>n>>m;
    
    vector<string> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    vector<vector<int>> vis(n,vector<int>(m));

    int ans = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && v[i][j] == '.'){
                dfs(i,j,v,vis);
                ans++;
            }
        }
    }
    cout<<ans<<"\n";

    return 0;
}