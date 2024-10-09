#include<bits/stdc++.h>
using namespace std;

//it doesn't always give an optimal solution (think about 5*6 rectangle)
//so now we need to use dp and look for all the ways we can make cuts
int solve(int i, int j){//greedy {didn't work}
    if(i == j) return 0;

    if(i<j) return 1 + solve(i,j-i);
    else return 1 + solve(i-j,j);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int a,b;
    cin>>a>>b;

    // cout<<solve(a,b);

    vector<vector<int>> dp(a+1, vector<int>(b+1,INT_MAX));//dp[i][j] stores the min number of moves required to make a rectangle of dimensions ixj into all squares
    for(int i=0;i<=min(a,b);i++){
        dp[i][i] = 0;//since already a rectangle
    }

    //dp[i][j] = min(1 + dp[k][j] + dp[i-k][j]) over all k from (1 to i-1) {horizontal cut}
    //dp[i][j] = min(1 + dp[i][k] + dp[i][j-k]) over all k from (1 to j-1) {vertical cut}
    //need to take the minimum of all of these

    //TC: O(n*m*(n+m))
    for(int i=0;i<=a;i++){
        for(int j=0;j<=b;j++){
            for(int k=1;k<i;k++){
                dp[i][j] = min(dp[i][j],1+dp[k][j] + dp[i-k][j]);
            }
            for(int k=1;k<j;k++){
                dp[i][j] = min(dp[i][j],1+dp[i][k] + dp[i][j-k]);
            }
        }
    }
    cout<<dp[a][b];

    return 0;
}