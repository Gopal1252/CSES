#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;
    vector<int> v(n),ans(n,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    //previouse smaller element
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && v[st.top()] >= v[i]){
            st.pop();
        }
        if(!st.empty()){
            ans[i] = st.top()+1;
        }
        st.push(i);
    }
    for(auto & it : ans){
        cout<<it<<" ";
    }

    return 0;
}