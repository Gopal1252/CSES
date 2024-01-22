#include<bits/stdc++.h>
using namespace std;

#define ll long long

//vid->https://www.youtube.com/watch?v=U_IcRW4hXNU

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++){
        ll ways = ((i*i)*((i*i)-1))/2;
        ll attack = 2*(2*(i-1)*(i-2));//(2*(n-1)*(n-2)) are the number of boxes
        cout<<ways-attack<<'\n';
    }


    return 0;
}