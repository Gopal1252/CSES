#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n,m;
    cin>>n>>m;

    vector<int> h(n);
    set<vector<int>> st;
    for(int i=0;i<n;i++){
        cin>>h[i];
        st.insert({h[i],i});
    }

    vector<int> t(m);
    for(int i=0;i<m;i++){
        cin>>t[i];
        auto it = st.lower_bound({t[i]+1,0});
        if(it == st.begin()){
            cout<<-1<<"\n";
        }
        else{
            --it;
            cout<<(*it)[0]<<"\n";
            st.erase(it);
        }
    }

    return 0;
}