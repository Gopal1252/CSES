#include<bits/stdc++.h>
using namespace std;
#define ll long long
//basically optimal game strategy

//dp[i][j] returns the maximum score that can be obtained by the current playing player if he chooses one of the indexes-> i or j 
long long maxScore(long long i, long long j, vector<long long>& v, vector<vector<long long>>& dp){
    if(i>j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    long long ans = v[i] + min(maxScore(i+2,j,v,dp),maxScore(i+1,j-1,v,dp));//if 1st player chooses i, then the 2nd player can choose i+1 or jth index element
    ans = max(ans, v[j] + min(maxScore(i+1,j-1,v,dp),maxScore(i,j-2,v,dp)));//if 1st player chooses the jth index, then the 2nd player can choose ith or the jth index element

    return dp[i][j] = ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    long long n;
    cin>>n;
    vector<long long> v(n);
    for(long long i=0;i<n;i++) cin>>v[i];

    vector<vector<long long>> dp(n,vector<long long>(n,-1));

    cout<<maxScore(0,n-1,v,dp);//max(i,j) returns the maximum score that can be obtained by the current playing player if he chooses one of the indexes-> i or j and the current playing player is player 1

    

    return 0;
}