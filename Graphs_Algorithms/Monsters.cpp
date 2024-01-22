#include<bits/stdc++.h>
using namespace std;
//What I did?
//1)do multisource bfs for all monsters, so for all locations, we get the shortest distance from the nearest monster
//2)then we do bfs for the A element all find the shortest distance of all the elments from A
//3) If we can reach an exit point(any point on boundry) before a the closest monster, then we have an answer, otherwise no
//4) Once we get even a single such location, we trace back the route
//I was storing the route strings in queue, which lead to making a copy of the same everytime i pushed into queue and was getting TLE for one testcase, so tracing back i viable
const int INF = 1e9+10;
int sx,sy;//start coordinates
void printRoute(int ex, int ey, vector<vector<string>>& route){
    int x = ex;
    int y = ey;
    string ans = "";
    while(!(x == sx && y == sy)){
        ans+=route[x][y];
        if(route[x][y] == "R"){
            y-=1;
        }
        else if(route[x][y] == "L"){
            y+=1;
        }
        else if(route[x][y] == "U"){
            x+=1;
        }
        else{
            x-=1;
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int n,m;
    cin>>n>>m;
 
    vector<pair<int,int>> monsters;//stores all coordinates of monsters
    vector<pair<int,int>> exit;//stores all coordinates of exit points
    vector<string> lab(n);//stores labyrinth
    for(int i=0;i<n;i++){
        cin>>lab[i];
        for(int j=0;j<m;j++){
            if(lab[i][j] == 'A'){
                sx = i;
                sy = j;
            } 
            if(lab[i][j] == 'M'){
                monsters.push_back({i,j});
            }
        }
    }
 
    if(sx == 0 || sx == n-1 || sy==0 || sy==m-1){//checking if the starting point is at the border itself
        cout<<"YES\n";
        cout<<0<<"\n";
        return 0;
    }
 
    vector<vector<int>> distM(n+1,vector<int>(m+1,INF));//will store the shortest distance of each cell from monsters
    vector<vector<int>> distA(n+1,vector<int>(m+1,INF));//will store the shortest distance of each cell from starting point
 
    vector<vector<int>> vis(n+1,vector<int>(m+1));
    vector<pair<int,int>> mov = {{-1,0},{0,-1},{1,0},{0,1}};
    vector<string> dir = {"U","L","D","R"};
 
    queue<pair<int,int>> q;
    for(int i=0;i<monsters.size();i++){
        int x = monsters[i].first;
        int y = monsters[i].second;
        q.push({x,y});
        distM[x][y] = 0;
        vis[x][y] = 1;
    }
 
    while(!q.empty()){
        auto node = q.front();
        q.pop();
 
        int x = node.first;
        int y = node.second;
 
        for(int i=0;i<4;i++){
            int nx = x + mov[i].first;
            int ny = y + mov[i].second;
 
            if(nx<0 || ny<0 || nx>=n || ny>=m || lab[nx][ny] == '#') continue;
 
            if(vis[nx][ny]) continue;
 
            q.push({nx,ny});
            distM[nx][ny] = distM[x][y]+1;
            vis[nx][ny] = 1;
        }
    }
 
    queue<pair<int,int>> q1;
    q1.push({sx,sy});
    vector<vector<int>> vis1(n+1,vector<int>(m+1));
    vis1[sx][sy] = 1;
    distA[sx][sy] = 0;
 
    vector<vector<string>> route(n+1,vector<string>(m+1)); //route[i][j] stores the direction we moved in order to come here
    while(!q1.empty()){
        auto node = q1.front();
        q1.pop();
 
        int x = node.first;
        int y = node.second;
 
        for(int i=0;i<4;i++){
            int nx = x + mov[i].first;
            int ny = y + mov[i].second;
 
            if(nx<0 || ny<0 || nx>=n || ny>=m || lab[nx][ny] == '#' || lab[nx][ny] == 'M') continue;
 
            if(vis1[nx][ny]) continue;
 
            if(distA[x][y]+1 < distM[nx][ny]){//monsters move optimally, so if any moster can reach any location before us, then we won't enter here
                q1.push({nx,ny});
                distA[nx][ny] = distA[x][y]+1;
                vis1[nx][ny] = 1;
                route[nx][ny] = dir[i];
                if(nx == 0 || nx == n-1 || ny==0 || ny==m-1){
                    cout<<"YES\n";
                    cout<<distA[nx][ny]<<"\n";
                    printRoute(nx,ny,route);
                    return 0;
                }
            }
        }
    }
    cout<<"NO";
 
    return 0;
}