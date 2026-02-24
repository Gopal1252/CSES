#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;

    vector<int> v(n);

    map<int,int> mp;
    set<int> st;//keeps track of all the elements not in the current window, smallest of these is our MEX

    for(int i=0;i<=k;i++){
        st.insert(i);//at max the mex of a window of size k can be k
    }
    
    for(int i=0;i<k-1;i++){
        cin>>v[i];
        if(mp[v[i]] == 0){
            st.erase(v[i]);
        }
        mp[v[i]]++;
    }

    for(int i=k-1;i<n;i++){
        cin>>v[i];
        if(mp[v[i]] == 0){
            st.erase(v[i]);
        }
        mp[v[i]]++;

        cout<<*st.begin()<<" ";

        mp[v[i-k+1]]--;
        if(mp[v[i-k+1]] == 0){
            st.insert(v[i-k+1]);
        }
    }

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    solve();

    return 0;
}