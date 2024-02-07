#include<bits/stdc++.h>
using namespace std;
//although can be done without string hashing (using simply 2 pointers), I did with string hashing
const int M = 1e9+7;

int binExp(int a, int b){
    int ans = 1;
    while(b){
        if(b&1){
            ans = (ans * 1LL * a)%M;
        }
        a = (a*1LL*a)%M;
        b>>=1;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string s;
    cin>>s;

    int n = s.size();
    vector<int> hash;
    int hsh = 0;
    for(int i=0;i<s.size();i++){
        hsh = (hsh*1LL*31 + (s[i]-'a'+1))%M;
        hash.push_back(hsh);
    }
    for(int i=0;i<n-1;i++){
        int j = n-1-i;
        int hash2 = (hash[n-1] - (hash[j-1]*1LL*binExp(31,n-j))%M + M)%M;
        if(hash[i] == hash2) cout<<i+1<<" ";
    }

    return 0;
}