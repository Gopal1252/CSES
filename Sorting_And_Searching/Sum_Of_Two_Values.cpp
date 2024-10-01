#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;

    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v.push_back({b,a});
    }
    sort(v.begin(),v.end());
    int curr = 0;
    int ans = 0;
    for(int i=0;i<n;i++){
        if(curr <= v[i].second){
            ans++;
            curr = v[i].first;
        }
    }
    cout<<ans<<"\n";

    return 0;
}