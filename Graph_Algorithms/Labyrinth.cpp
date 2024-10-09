#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n,m;
    cin>>n>>m;

    vector<vector<char>> grid(n,vector<char>(m));
    int si, sj, ei, ej;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
            if(grid[i][j] == 'A'){
                si = i;
                sj = j;
            }
            if(grid[i][j] == 'B'){
                ei = i;
                ej = j;
            }
        }
    }

    vector<vector<int>> vis(n,vector<int>(m,0));

    vector<pair<int,int>> mov = {{-1,0},{0,-1},{1,0},{0,1}};
    vector<char> dir = {'U','L','D','R'};
    vector<vector<char>> path(n,vector<char>(m,'0'));
    vector<vector<int>> d(n,vector<int>(m,0));

    queue<pair<int,int>> q;
    q.push({si,sj});
    vis[si][sj] = 1;

    while(!q.empty()){
        int ci = q.front().first;
        int cj = q.front().second;
        q.pop();

        for(int k=0;k<4;k++){
            int di = ci + mov[k].first;
            int dj = cj + mov[k].second;
            if(di>=0 && di<n && dj>=0 && dj<m && !vis[di][dj] && grid[di][dj] != '#'){
                vis[di][dj] = 1;
                path[di][dj] = dir[k];//stores the direction taken to reach this index
                d[di][dj] = k;//stores the index of mov taken to reach this index
                q.push({di,dj});
                if(di == ei && dj == ej){
                    cout<<"YES\n";
                    string ans = "";
                    while(!(si == ei && sj == ej)){
                        ans.push_back(path[ei][ej]);
                        int dd = d[ei][ej];
                        ei -= mov[dd].first;
                        ej -= mov[dd].second;
                    }
                    reverse(ans.begin(),ans.end());
                    cout<<ans.length()<<"\n";
                    cout<<ans<<"\n";
                    return 0;
                }
            }
        }
    }
    cout<<"NO\n";

    return 0;
}