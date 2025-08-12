#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n,q;
    cin>>n>>q;

    vector<long long> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
        if(i>0){
            v[i] += v[i-1];
        }
    }

    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;

        a--;b--;
        cout<<v[b] - ((a>0)?v[a-1]:0)<<"\n";
    }


    return 0;
}