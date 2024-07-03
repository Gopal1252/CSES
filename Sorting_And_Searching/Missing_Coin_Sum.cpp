#include <bits/stdc++.h>
using namespace std;
#define ll long long
//similar:
//https://leetcode.com/problems/patching-array/description/
//https://leetcode.com/problems/minimum-number-of-coins-to-be-added/description/
//https://leetcode.com/problems/maximum-number-of-consecutive-values-you-can-make/description/
int main() {
    ll n;
    cin>>n;
    
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    sort(v.begin(),v.end());
    
    ll ans = 1;
    for(int i= 0; i<n; i++){
        if(v[i] > ans){
            cout<<ans;
            return 0;
        }
        ans += v[i];
    }
    cout<<ans;

    return 0;
}
