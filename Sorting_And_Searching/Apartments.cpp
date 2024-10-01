#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n,m,k;
    cin>>n>>m>>k;

    vector<ll> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    vector<ll> b(m);
    for(int i=0;i<m;i++) cin>>b[i];

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    int i = 0, j = 0;

    int ans = 0;
    while(i<n && j<m){
        if(a[i]-k <= b[j] && b[j] <= a[i]+k){
            i++;
            j++;
            ans++;
        }
        else if(b[j] < a[i]-k){
            j++;
        }
        else if(b[j] > a[i]-k){
            i++;
        }
    }
    cout<<ans<<"\n";






    return 0;
}