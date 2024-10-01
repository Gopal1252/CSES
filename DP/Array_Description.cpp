#include<bits/stdc++.h>
using namespace std;
const int M = 1e9+7;

int ways(int ind, int prev, int m, vector<int>& arr, vector<vector<int>>& dp){
    if(ind == arr.size()){
        return 1;
    }

    if(dp[ind][prev] != -1) return dp[ind][prev];

    if(arr[ind] != 0){
        if(abs(arr[ind] - prev) > 1){
            return dp[ind][prev] = 0;
        }
        else return dp[ind][prev] = ways(ind+1,arr[ind],m,arr,dp);
    }
    else{
        int ans = 0;
        ans = (ans + 0LL + ways(ind+1,prev,m,arr,dp))%M;
        if(prev>1){
            ans = (ans + 0LL + ways(ind+1,prev-1,m,arr,dp))%M;
        }
        if(prev<m){
            ans = (ans + 0LL + ways(ind+1,prev+1,m,arr,dp))%M;
        }
        return dp[ind][prev] = ans;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n,m;
    cin>>n>>m;

    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    vector<vector<int>> dp(n,vector<int>(101,-1));//dp[i][j] stores the number of ways to fill the array from index i to n-1 if the previous element was j
    if(v[0] != 0){
        cout<<ways(0,v[0],m,v,dp)<<"\n";
    }
    else{
        int ans = 0;
        for(int i=1;i<=m;i++){
            ans = (ans + 0LL + ways(1,i,m,v,dp))%M;
        }
        cout<<ans<<"\n";
    }

    return 0;
}