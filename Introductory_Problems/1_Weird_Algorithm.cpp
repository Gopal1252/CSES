#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long n;
    cin>>n;
    vector<long long> ans;
    while(n != 1){
        ans.push_back(n);
        if(n%2 == 0){
            n/=2;
        }
        else{
            n = n*3 + 1;
        }
    }
    ans.push_back(1);
 
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
