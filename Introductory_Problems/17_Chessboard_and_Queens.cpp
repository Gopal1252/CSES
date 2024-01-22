#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/n-queens/description/

int ans = 0;
bool isPossible(int row, int col, vector<string>& v){
    for(int i=row-1;i>=0;i--){
        if(v[i][col] == 'Q') return false;
    }
    for(int i=row-1, j=col-1;i>=0 && j>=0;i--,j--){
        if(v[i][j] == 'Q') return false;
    }
    for(int i=row-1, j=col+1;i>=0 && j<8;i--,j++){
        if(v[i][j] == 'Q') return false;
    }
    return true;
}
void solve(int row, vector<string>& v){
    if(row == 8){
        ans++;
        return;
    }

    for(int j=0;j<8;j++){
        if(v[row][j] != '*' && isPossible(row,j,v)){
            v[row][j] = 'Q';
            solve(row+1,v);
            v[row][j] = '.';
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<string> v(8,"........");
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cin>>v[i][j];
        }
    }

    solve(0,v);
    cout<<ans;


    return 0;
}