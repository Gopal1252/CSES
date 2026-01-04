#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll dp[20][10][2][2];
//dp[ind][prev][limit][started] returns the number of ways to fill indices from ind till last 
//such that we get a number where no adjacent elements are the same and prev is the previous digit taken
//limit tells whether prefix is same as higher limit so far and started tells whether we have
//encountered leading zeroes only so far
//need started since for a number like 005, need to make sure that 1st and 2nd zeror, though adjacent not rule out the number, it should be counted
ll solve(ll ind, ll prev, ll limit, ll started,string& hl){
    if(ind == hl.size()){
        return 1;
    }

    if(dp[ind][prev][limit][started] != -1) return dp[ind][prev][limit][started];

    ll hP = (limit == 1)? hl[ind]-'0' : 9;

    ll ansHere = 0;

    for(ll x=0;x<=hP;x++){
        if(started && x == prev){
            continue;
        }
        ansHere += solve(ind+1,x,limit&(x == hP),started|(x>0),hl);
    }
    return dp[ind][prev][limit][started] = ansHere;
}
void solve(){
    long long a,b;
    cin>>a>>b;

    string strA = (a == 0) ? "0" : to_string(a-1);
    string strB = to_string(b);

    memset(dp,-1,sizeof(dp));
    ll hi = solve(0,0,1,0,strB);
    if(a == 0){
        cout<<hi<<"\n";
        return;
    }

    memset(dp,-1,sizeof(dp));
    ll lo = solve(0,0,1,0,strA);

    // cout<<hi<<"\n"<<lo<<"\n";

    cout<<hi-lo<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    solve();

    return 0;
}