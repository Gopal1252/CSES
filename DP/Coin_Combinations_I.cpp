#include<bits/stdc++.h>
using namespace std;

const int M = 1e9+7;

//dp[i] --> stores the number of ways to make the sum i
//T.C: --> O(sum) * O(v.size()) = O(sum*v.size())
int ways(int sum, vector<int>& v, vector<int>& dp){
    if(sum == 0) return 1;

    if(dp[sum] != -1) return dp[sum];

    int ans = 0;
    for(int i=0;i<v.size(); i++){
        if(sum>=v[i]){
            ans = (ans + 0LL + ways(sum-v[i],v,dp))%M;
        }
    }
    return dp[sum] = ans;
} 

// T.C: O(sum*n)
void iterative(int sum, vector<int>& v){
    int n = v.size();

    vector<int> dp(sum+1,0);
    dp[0] = 1;//one way to make sum = 0 i.e. not take any coin

    for(int i = 1; i<=sum; i++){
        for(int j=0; j<v.size(); j++){
            if(i>=v[j]){
                dp[i] = (dp[i] + 0LL + dp[i-v[j]])%M;
            }
        }
    }
    cout<<dp[sum];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n,x;
    cin>>n>>x;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    iterative(x,v);

    // vector<int> dp(x+1,-1);
    // cout<<ways(x,v,dp);

    return 0;
}