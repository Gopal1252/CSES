#include<bits/stdc++.h>
using namespace std;

const int M = 1e9+7;
//TC: O(6*n)
int ways(int sum, vector<int>& dp){
    if(sum == 0) return 1;

    if(dp[sum] != -1) return dp[sum];

    int ans = 0;
    for(int i=1;i<=6;i++){
        if(sum>=i){
            ans = (ans + 0LL + ways(sum-i,dp))%M;
        }
    }
    return dp[sum] = ans;
}

//iterative
int waysIter(int n){
    vector<int> dp(n+1,0);
    dp[0] = 1;//if sum = 0, then only 1 possible solution i.e not throwing any dice

    for(int i=1;i<=n;i++){
        for(int j=1; j<=6; j++){
            if(i>=j){
                dp[i] = (dp[i] + 0LL + dp[i-j])%M;
            }
        }
    }
    return dp[n];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;

    vector<int> dp(n+1,-1);
    cout<<ways(n,dp);


    return 0;
}