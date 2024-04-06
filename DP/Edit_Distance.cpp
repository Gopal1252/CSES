#include<bits/stdc++.h>
using namespace std;

//basically converting s1 to s2
//accepted (striver's solution)
int minDist(int i, int j, string& s1, string& s2, vector<vector<int>>& dp){
    if(i<0) return j+1;
    if(j<0) return i+1;

    if(dp[i][j] != -1) return dp[i][j];

    if(s1[i] == s2[j]){//we need not take any step/do any operation in this case, so this method would be the min edit distance
        return dp[i][j] = minDist(i-1,j-1,s1,s2,dp);
    }

    int ans = 1+ minDist(i,j-1,s1,s2,dp);//adding a character matching s2[j] in s1 at ith index
    ans = min(ans, 1 + minDist(i-1,j-1,s1,s2,dp));//replace the character at ith index in s1 to s2[j]
    ans = min(ans, 1 + minDist(i-1,j,s1,s2,dp));//deleting the character at s1[i] 
    
    return dp[i][j] = ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string s1,s2;
    cin>>s1>>s2;
    int n = s1.size();
    int m = s2.size();
    // vector<vector<int>> dp(n,vector<int>(m,-1));
    // cout<<minDist(n-1,m-1,s1,s2,dp);

    //iterative (striver)
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));//dp[i][j] stores the edit distance of s1 and s2 if s1 is considered till the length i and s2 till the length j (remember not index)

    //base cases
    for(int i=0; i<=n; i++) dp[i][0] = i;
    for(int j=0; j<=m; j++) dp[0][j] = j;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
            else{
                dp[i][j] = 1 + min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
            }
        }
    }
    cout<<dp[n][m];

    return 0;
}