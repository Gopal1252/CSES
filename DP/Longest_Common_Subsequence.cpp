#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>& a, vector<int>& b){
    int n = a.size();
    int m = b.size();

    vector<vector<int>> dp(n,vector<int>(m,0));
    //dp[i][j] stores the length of the lcs if considering elements till indicies i and j only

    bool flg = 0;
    for(int i=0;i<n;i++){
        if(a[i] == b[0]){
            flg = 1;
        }
        if(flg){
            dp[i][0] = 1;
        }
    }
    flg = 0;
    for(int i=0;i<m;i++){
        if(a[0] == b[i]){
            flg = 1;
        }
        if(flg){
            dp[0][i] = 1;
        }
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            dp[i][j] = max(dp[i-1][j-1] + (a[i] == b[j]),max(dp[i-1][j],dp[i][j-1]));
        }
    }

    cout<<dp[n-1][m-1]<<"\n";

    vector<int> ans;
    int i = n-1, j = m-1;
    while(i>0 && j>0){
        if(a[i] == b[j]){
            ans.push_back(a[i]);
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    while(i>=0){
        if(a[i] == b[0]){
            ans.push_back(a[i]);
            i = -1;
            j = -1;
        }
        else{
            i--;
        }
    }
    while(j>=0){
        if(a[0] == b[j]){
            ans.push_back(b[j]);
            i = -1;
            j = -1;
        }
        else{
            j--;
        }
    }

    reverse(ans.begin(),ans.end());
    for(auto & it : ans){
        cout<<it<<" ";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n,m;
    cin>>n>>m;
    vector<int> v1(n), v2(m);
    for(int i=0;i<n;i++){
        cin>>v1[i];
    }
    for(int j=0;j<m;j++){
        cin>>v2[j];
    }

    solve(v1,v2);

    return 0;
}