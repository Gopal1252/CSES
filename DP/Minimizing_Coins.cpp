#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n,x;
    cin>>n>>x;

    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    vector<int> dp(1e6+1,INT_MAX);//dp[i] stores the min number of coinst to make sum = i
    dp[0] = 0;

    for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++){
            if(i-v[j]>=0){
                dp[i] = min(dp[i] + 0LL,min(INT_MAX + 0LL, dp[i-v[j]] + 1LL));
            }
        }
    }
    if(dp[x] == INT_MAX){
        cout<<-1<<"\n";
    }
    else{
        cout<<dp[x]<<"\n";
    }

    return 0;
}