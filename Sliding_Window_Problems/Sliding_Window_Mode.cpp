#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    map<int,int> mp;
    multiset<pair<int,int>> st;
    for(int i=0;i<k-1;i++){
        cin>>v[i];
        auto it = st.find({mp[v[i]],-1*v[i]});
        if(it != st.end()){
            st.erase(it);
        }
        mp[v[i]]++;
        st.insert({mp[v[i]],-1*v[i]});
    }
    
    for(int i=k-1;i<n;i++){
        cin>>v[i];
        auto it = st.find({mp[v[i]],-1*v[i]});
        if(it != st.end()){
            st.erase(it);
        }
        mp[v[i]]++;
        st.insert({mp[v[i]],-1*v[i]});

        cout<<-1*(*st.rbegin()).second<<" ";

        auto it2 = st.find({mp[v[i-k+1]],-1*v[i-k+1]});
        if(it2 != st.end()){
            st.erase(it2);
        }
        mp[v[i-k+1]]--;
        if(mp[v[i-k+1]]>0){
            st.insert({mp[v[i-k+1]],-1*v[i-k+1]});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    solve();

    return 0;
}