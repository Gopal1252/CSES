#include<bits/stdc++.h>
using namespace std;

//longest increasing subsequence

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;

    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    vector<int> dp;
    for(int i=0;i<n;i++){
        if(dp.empty() || dp.back() < v[i]){
            dp.push_back(v[i]);
        }
        else{
            int ind = lower_bound(dp.begin(),dp.end(),v[i]) - dp.begin();
            dp[ind] = v[i];
        }
    }
    cout<<dp.size()<<"\n";

    return 0;
}