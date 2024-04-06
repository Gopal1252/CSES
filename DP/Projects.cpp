#include<bits/stdc++.h>
using namespace std;
#define ll long long

//TLE {although some undescribed Runtime error was occuring on submission}
//TC: O(n*n) {in question, n is around 2*10^5, so gives tle}
//my solution
ll maxProf(ll ind, ll currInd, vector<vector<ll>>& v, vector<vector<ll>>& dp){
    if(ind == v.size()) return 0;

    if(dp[ind][currInd] != -1) return dp[ind][currInd];

    ll ans = maxProf(ind+1,currInd,v,dp);
    if(v[currInd][1]<v[ind][0]){
        ans = max(ans,v[ind][2] + maxProf(ind+1,ind,v,dp));
    }

    return dp[ind][currInd] = ans;
}

//sir's solution
//TC:O(n) * O(log(n)) {although not completely correct I think since n's value keeps changing}
//I think actually in worst case it could be log(n) + log(n-1) + log(n-2) + .... + log(2)
//I think it is in fact of the order of O(n*log(n))
ll solve(int ind, vector<vector<ll>>& v, vector<ll>& dp){
    if(ind == v.size()) return 0;

    if(dp[ind] != -1) return dp[ind];

    //can't directly use lower or upper bound due to the 2d nature of the vector

    int nextInd = v.size();//worst case
    int lo = ind+1;
    int hi = v.size()-1;

    while(hi>=lo){
        int mid = (lo + hi)/2;
        if(v[mid][0] > v[ind][1]){
            nextInd = mid;
            hi = mid-1;
        }
        else{
            lo = mid+1;
        }
    }

    return dp[ind] = max(solve(ind+1,v,dp),v[ind][2] + solve(nextInd,v,dp));//max(not taking the current element, taking the current element and moving to the next index)
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n;
    cin>>n;
    vector<vector<ll>> v(n+1,vector<ll>(3));
    for(ll i=1; i<=n; i++){
        cin>>v[i][0]>>v[i][1]>>v[i][2];
    }

    sort(v.begin(),v.end());

    // vector<vector<ll>> dp(n+1, vector<ll>(n+1,-1));
    // cout<<maxProf(1,0,v,dp);

    //Sir's 1D DP solution (Accepted)
    vector<ll> dp(n+1,-1);//dp[i] stores the maximum profit we can make by doing projects uptill index i
    //basically instead of going to every index and checking whether to take it or not, we straight away go to the next index we can take
    //since the array is sorted, we can use binary search to get to the index where (the start of that index's project)>(end of currently taken project)
    cout<<solve(0,v,dp);

    return 0;
}