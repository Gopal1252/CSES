#include<bits/stdc++.h>
using namespace std;

set<string> ans;
void solve(string s, int mask,string curr){
    if(pow(2,s.size())-1 == mask){
        ans.insert(curr);
        return;
    }
    for(int i=0;i<s.size();i++){
        if((mask & (1<<i)) == 0){
            solve(s,mask|(1<<i),curr+s[i]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string s;
    cin>>s;
    solve(s,0,"");
    cout<<ans.size()<<endl;
    for(auto st : ans){
        cout<<st<<endl;
    }

    //or using the inbuilt next_permutation function

    // sort(s.begin(),s.end());
    // vector<string> ans;
    // do{
    //     ans.push_back(s);
    // }while(next_permutation(s.begin(),s.end()));

    // cout<<ans.size()<<"\n";
    // for(string a : ans){
    //     cout<<a<<"\n";
    // }


    return 0;
}