#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;

    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    //find median, avg won't work
    sort(v.begin(),v.end());
    ll median = v[(n-1)/2];
    ll ans = 0;
    for(int i=0;i<n;i++){
        ans += abs(median-v[i]);
    }
    cout<<ans<<"\n";

    return 0;
}