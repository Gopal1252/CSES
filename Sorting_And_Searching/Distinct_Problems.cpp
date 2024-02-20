#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;
    vector<int> v(n);
    set<int> st;
    for(int i=0;i<n;i++){
        cin>>v[i];
        st.insert(v[i]);
    }
    cout<<st.size();

    return 0;
}