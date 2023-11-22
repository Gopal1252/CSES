#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    ll a,b;
    cin>>a>>b;
    if(a == 0 && b == 0){
       cout<<"YES"<<endl;
       return;
    }
    if(a == 0 || b == 0){
        cout<<"NO"<<endl;
        return;
    }
    if((a+b)%3 != 0){
        cout<<"NO"<<endl;
    }
    else{
        int c = max(a,b);
        if(abs(a-b) > c/2){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}