#include<bits/stdc++.h>
using namespace std;

const int M = 1e9+7;

//dp[sum] stores the number of ordered ways to make the a coin combination of total sum = sum
//Tc:O(n*sum)
void iterative(int sum, vector<int>& v){
    int n = v.size();

    vector<int> dp(sum+1,0);
    dp[0] = 1;//only one way to make sum = 0, by not taking any coin

    for(int i=0;i<n;i++){
        for(int j=0;j<=sum;j++){
            if(j>=v[i]){
                dp[j] = (dp[j] + 0LL + dp[j - v[i]])%M;
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
    for(int i=0; i<n; i++) cin>>v[i];

    iterative(x,v);

    return 0;
}

//Old LUV way ---> TLE
//dp[sum][pos] stores the number of ways to make sum with coins till position pos
//T.C: no. of states * t.c of each state
//T.C: O(x*n) * O(factors of the maximum element of v) {I}
// int ways(int sum, int pos, vector<int>& v, vector<vector<int>>& dp){
//     if(sum == 0) return 1;
//     if(pos == v.size()) return 0;

//     if(dp[sum][pos] != -1) return dp[sum][pos];

//     int ans = 0;
//     for(int i=0; i<=sum; i+=v[pos]){
//         ans = (ans + 0LL + ways(sum-i,pos+1,v,dp))%M;
//     }
//     return dp[sum][pos] = ans;
// }