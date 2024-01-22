#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;
    long long tot = (n * 1LL * (n+1))/2;
    long long sum = 0;
    for(int i=0;i<n-1;i++){
        int x;
        cin>>x;
        sum += x;
    }

    cout<<tot-sum<<endl;

    return 0;
}