#include<bits/stdc++.h>
using namespace std;

//this is william lin's solution
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;

    vector<vector<int>> v(n,vector<int>(3,0));
    for(int i=0;i<n;i++){
        cin>>v[i][1]>>v[i][0];
        v[i][2] = i;
    }

    sort(v.begin(),v.end());

    vector<int> ans(n);
    set<vector<int>> st;//stores {departure_time,index} of the ith customer

    for(int i=0;i<n;i++){
        auto it = st.lower_bound({v[i][1]});//find the lowest departure time >= current's arrival time
        if(it != st.begin()){//if there is someone with a lower departure time, then just take their room
            --it;
            ans[v[i][2]] = (*it)[1];
            st.erase(it);
        }
        else{
            ans[v[i][2]] = st.size();//require a new room
        }
        st.insert({v[i][0],ans[v[i][2]]});
    }

    cout<<st.size()<<"\n";
    for(auto & it : ans){
        cout<<it+1<<" ";
    }
    cout<<"\n";



    return 0;
}