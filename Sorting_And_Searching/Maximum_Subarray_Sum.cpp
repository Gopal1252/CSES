#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;

    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    //kadane's algo for max subarray sum

    ll currSum = v[0];
    ll maxSum = v[0];
    for(int i=1;i<n;i++){
        //either start a new subarray of continue with existing one
        currSum = max(v[i]*1ll,currSum+v[i]);
        maxSum = max(maxSum,currSum);
    }
    cout<<maxSum<<"\n";
    

    return 0;
}