#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;

    vector<int> v(n+1);
    vector<int> pos(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
        pos[v[i]] = i;
    }
    int ans = 1;
    for(int i=1;i<n;i++){
        if(pos[i]>pos[i+1]) ans++;//answer is equal to number of inversions considering pairwise consecutive numbers
    }
    cout<<ans<<"\n";

    return 0;
}