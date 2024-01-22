#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    if(n == 1){
        cout<<1;
        return;
    }
    if(n==2 || n==3){
        cout<<"NO SOLUTION";
        return;
    }
    if(n == 4){
        cout<<"3 1 4 2";
        return;
    }
    vector<int> v(n+1);
    int x = 1;
        for(int i=1;i<=n;i+=2){
            v[i] = x;
            x++;
        }
        for(int i=2;i<=n;i+=2){
            v[i] = x;
            x++;
        }
    for(int i=1;i<=n;i++){
        cout<<v[i]<<" ";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    solve();


    return 0;
}