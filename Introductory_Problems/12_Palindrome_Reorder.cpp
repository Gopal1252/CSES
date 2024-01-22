#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin>>s;
    map<char,int> mp;
    for(int i=0;i<s.size();i++){
        mp[s[i]]++;
    }
    int cnt = 0;
    string ans;
    char ch;
    int chCnt = 0;
    for(auto it : mp){
        if(it.second%2 == 0){
            for(int i=0;i<it.second/2;i++){
                ans += it.first;
            }
        }
        else{
            cnt++;
            ch = it.first;
            chCnt = it.second;
        }
    }

    if(cnt > 1){
        cout<<"NO SOLUTION";
        return;
    }
    else if(cnt == 0){
        string temp = ans;
        reverse(temp.begin(),temp.end());
        ans = ans+temp;
        cout<<ans;
        return;
    }
    else{
        for(int i=0;i<chCnt/2;i++){
            ans+=ch;
        }
        string temp = ans;
        reverse(temp.begin(),temp.end());
        ans = ans+ch+temp;
        cout<<ans;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    solve();


    return 0;
}