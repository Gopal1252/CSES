#include<bits/stdc++.h>
using namespace std;
//just simple 0-1 knapsack

//dp[ind][money] --> gives the maximum number of pages that can be bought with the money = money if we consider all the books till the index = ind
//T.C: O(n*x) + recursion stack overhead
//TLE
int maxPages(int ind, int money, vector<int>& prices, vector<int>& pages, vector<vector<int>>& dp){
    if(money == 0) return 0;
    if(ind == prices.size()) return 0;

    if(dp[ind][money] != -1) return dp[ind][money];

    int ans = maxPages(ind+1,money,prices,pages,dp);//not taking the current book
    if(prices[ind]<=money){
        ans = max(ans,pages[ind] + maxPages(ind+1,money-prices[ind],prices,pages,dp));
    }
    return dp[ind][money] = ans;
}
//dp[ind][money] --> gives the maximum number of pages that can be bought with the money = money if we consider all the books till the index = ind
//T.C: O(n*x)
//(I) --> basically filling the dp table top to bottom (and left to right)
void iterative(){//Accepted (saw striver's dp)
   int n,x;
    cin>>n>>x;

    vector<int> prices(n), pages(n);
    for(int i=0;i<n;i++) cin>>prices[i];
    for(int i=0;i<n;i++) cin>>pages[i];

    vector<vector<int>> dp(n,vector<int>(x+1,0));

    for(int i=0;i<=x;i++){//we do this step separately becoz in th below loop, we do dp[i-1][j], so we need to start from i = 1 and here we fill dp array for i = 0
        if(prices[0] <= i){
            dp[0][i] = pages[0];//if only taking the 0th element then if the available money is greater than the price of the 0th element, then dp[0][i] = pages[0]
        }
    }

    for(int i = 1; i<n; i++){
        for(int j = 1; j<=x; j++){
            dp[i][j] = dp[i-1][j];
            if(prices[i] <= j){
                dp[i][j] = max(dp[i][j],pages[i] + dp[i-1][j - prices[i]]);
            }
        }
    }
    cout<<dp[n-1][x]<<"\n";
}

//dp[ind][money] -> stores the max no. of pages that can be bought if we consider all the books between index = ind to n-1
//(I) -> basically filling the table bottom to top (and left to right)
void iterative2(){
    int n,x;
    cin>>n>>x;

    vector<int> prices(n), pages(n);
    for(int i=0;i<n;i++) cin>>prices[i];
    for(int i=0;i<n;i++) cin>>pages[i];

    vector<vector<int>> dp(n+1,vector<int>(x+1,0));

    for(int i=n-1;i>=0;i--){
        for(int j=1;j<=x;j++){
            dp[i][j] = dp[i+1][j];
            if(prices[i] <= j){
                dp[i][j] = max(dp[i][j],pages[i] + dp[i+1][j - prices[i]]);
            }
        }
    }
    cout<<dp[0][x]<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    iterative();

    // int n,x;
    // cin>>n>>x;

    // vector<int> prices(n), pages(n);
    // for(int i=0; i<n;i++) cin>>prices[i];
    // for(int i=0; i<n;i++) cin>>pages[i];

    // vector<vector<int>> dp(n+1,vector<int>(x+1,-1));
    // cout<<maxPages(0,x,prices,pages,dp)<<"\n";




    return 0;
}