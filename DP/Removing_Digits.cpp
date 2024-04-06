#include<bits/stdc++.h>
using namespace std;
//dp[i] --> stores the minimum number of steps required to convert i to 0
int minSteps(int num, vector<int>& dp){
    if(num == 0) return 0;

    if(dp[num] != -1) return dp[num];

    int ans = INT_MAX;
    int temp = num;
    while(temp){
        int dig = temp%10;
        temp = temp/10;
        if(dig != 0){
            ans = min(ans,1+minSteps(num-dig,dp));
        }
    }
    return dp[num] = ans;
}

void iterative(){
    int n;
    cin>>n;

    vector<int> dp(n+1,INT_MAX);
    dp[0] = 0;//number of steps required to reach 0 from 0 is 0

    for(int i=1;i<=n;i++){
        int temp = i;
        while(temp){
            int dig = temp%10;
            temp = temp/10;
            if(dig != 0){
                dp[i] = min(dp[i],1+dp[i-dig]);
            }
        }
    }
    cout<<dp[n]<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    iterative();

    // int n;
    // cin>>n;
    // vector<int> dp(n+1,-1);
    // cout<<minSteps(n,dp);

    return 0;
}