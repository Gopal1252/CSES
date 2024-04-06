#include<bits/stdc++.h>
using namespace std;

const int M = 1e9+7;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;
    vector<string> v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    if(v[0][0] == '*'){
        cout<<0<<"\n";
        return 0;
    }

    vector<vector<int>> dp(n,vector<int>(n,0));//dp[i][j] stores the number of paths from 0,0 to i,j
    dp[0][0] = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(v[i][j] != '*'){
                if(i>0){
                    dp[i][j] = (dp[i][j] + 0LL +dp[i-1][j])%M;
                }
                if(j>0){
                    dp[i][j] = (dp[i][j] + 0LL + dp[i][j-1])%M;
                }
            }
        }
    }
    cout<<dp[n-1][n-1]<<"\n";


    return 0;
}