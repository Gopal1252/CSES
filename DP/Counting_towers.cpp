#include<bits/stdc++.h>
using namespace std;

const int M = 1e9+7;

//see this codeforces blog's comment:
// https://codeforces.com/blog/entry/98085

//also see the image (in this folder) to understand

vector<int> dp1(1e6+1);
vector<int> dp2(1e6+1);
void solve(){
    int n;
    cin>>n;

    cout<<(dp1[n]+ 0LL + dp2[n])%M<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    dp1[1] = 1;//type 1 towers
    dp2[1] = 1;//type 2 towers

    for(int i=2;i<=1e6;i++){
        dp1[i] = ((2*1LL*dp1[i-1])%M + 0LL + dp2[i-1])%M;
        dp2[i] = (dp1[i-1] + 0LL + (4*1LL*dp2[i-1])%M)%M;
    }

    int t;
    cin>>t;
    while(t--){
        solve();
    }



    return 0;
}