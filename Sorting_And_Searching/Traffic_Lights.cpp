#include<bits/stdc++.h>
using namespace std;

#define ll long long


//william lin's solution
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int x,n;
    cin>>x>>n;

    map<int,int> mp;//store the counts of different lengths
    set<int> st;//stores all the positions where traffic lights are available (or the end points)
    st.insert(0);
    st.insert(x);
    mp[x] = 1;
    vector<int> v(2e5+1);
    for(int i=0;i<n;i++){
        cin>>v[i];
        //find the passage in which the current traffic light is installed
        auto it = st.lower_bound(v[i]);
        int r = *it;
        --it;
        int l = *it;

        mp[r-l]--;
        if(!mp[r-l]){
            mp.erase(r-l);
        }
        st.insert(v[i]); 
        mp[v[i]-l]++;
        mp[r-v[i]]++;
        cout<<((--mp.end())->first)<<" ";
    }

    return 0;
}