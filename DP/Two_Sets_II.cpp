#include<bits/stdc++.h>
using namespace std;
//simple but interesting
//due to MOD, dividing at the end by 2 is not giving me correct answer
//see the editorial for this problem here: https://codeforces.com/blog/entry/70018
//basically, to avoid counting a pair of subsets twice, we keep the last element in one subset
//so we never take the last element in our subset
const int M = 1e9+7;

int ways(int ind, int sum, int n, vector<vector<int>>& dp){
    if(ind == n){
        if(sum == 0) return 1;
        else return 0;
    }

    if(dp[ind][sum] != -1) return dp[ind][sum];

    int ans = 0;
    ans = ways(ind+1,sum,n,dp);
    if(sum>=ind){
        ans = (ans + 0LL + ways(ind+1,sum-ind,n,dp))%M;
    }

    return dp[ind][sum] = ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;

    int sum = (n*(n+1))/2;

    if(sum%2 != 0){
        cout<<0<<"\n";
        return 0;
    }

    sum/=2;

    vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));//dp[i][j] stores the number of ways to make sum = j using elements from i to n

    cout<<ways(1,sum,n,dp)<<"\n";

    return 0;
}
