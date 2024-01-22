#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int M = 1e9+7;

int binExp(int a, int b){
    int ans = 1;
    while(b){
        if(b&1){
            ans = (ans*1LL*a)%M;
        }
        a = (a*1LL*a)%M;
        b>>=1;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;
    cout<<binExp(2,n);


    return 0;
}