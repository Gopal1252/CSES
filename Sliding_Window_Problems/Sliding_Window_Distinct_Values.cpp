#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    map<int,int> mp;
    int dupCnt = 0;
    for(int i=0;i<k-1;i++){
        cin>>v[i];
        if(mp[v[i]] > 0){//there already exist some instances
            dupCnt++;
        }
        mp[v[i]]++;
    }
    for(int i=k-1;i<n;i++){
        cin>>v[i];
        if(mp[v[i]] > 0){
            dupCnt++;
        }
        mp[v[i]]++;
        cout<<k-dupCnt<<" ";

        mp[v[i-k+1]]--;
        if(mp[v[i-k+1]]){//if some instances left, then the deleted element was a duplicate
            dupCnt--;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    solve();

    return 0;
}