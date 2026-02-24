//https://codeforces.com/blog/entry/142846 (look at ngu_dot 's comment)
//discussion with claude --> https://claude.ai/share/f2082460-0f22-4a32-8fda-931892024835

//Main idea --> compute the OR of any window in O(1) by some prefix-suffix pre-computation
//The harder to understand part --> divide the array into blocks of size k (last block can be of size < k)
//then for each block, get prefix and suffix XOR
//then for any window of size k, spanning from i-k+1 to i, that window's OR --> suffOr[i-k+1] | pref[i]
//The reason for dividing the array into blocks of size k is that then the window will always fall into at max 2 blocks
//the suffixOR will get the left portion and the prefixOr will get the right portion
#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    ll n,k;
    cin>>n>>k;
    ll x,a,b,c;
    cin>>x>>a>>b>>c;

    vector<ll> v(n);

    ll ansXor = 0;
    vector<ll> prefOr(n), suffOr(n);
    for(ll i=0;i<n;i++){
        if(i == 0){
            v[i] = x;
            
        }
        else{
            v[i] = ((v[i-1]*a)%c + b)%c;
        }

        if(i%k == 0){
            prefOr[i] = v[i];
        }
        else{
            prefOr[i] = prefOr[i-1]|v[i];
        }
    }
    for(ll i=n-1;i>=0;i--){
        if(i == n-1 || i%k == 0){
            suffOr[i] = v[i];
        }
        else{
            suffOr[i] = suffOr[i+1]|v[i];
        }
    }
    for(ll i=0;i<n;i++){
        if(i>=k-1){
            ansXor = ansXor ^ (suffOr[i-k+1] | prefOr[i]);
        }
    }
    cout<<ansXor<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    solve();

    return 0;
}