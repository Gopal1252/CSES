#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    int ans = 0;
    int curr  = 1;
    int ch = s[0];
    for(int i=1;i<s.size();i++){
        if(s[i] == ch){
            curr++;
        }
        else{
            if(curr>ans){
                ans = curr;
            }
            ch = s[i];
            curr = 1;
        }
    }
    if(curr>ans){
        ans = curr;
    }
    cout<<ans;

    return 0;
}