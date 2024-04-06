#include<bits/stdc++.h>
using namespace std;

//TLE
//Brute force recursion
// set<int> st;
// void ways(int ind, int sum, vector<int>& v){
//     if(ind == v.size()){
//         if(sum != 0) st.insert(sum);
//         return;
//     }

//     ways(ind + 1,sum,v);
//     ways(ind+1,sum+v[ind],v);
// }

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;

    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];

    // ways(0,0,v);
    // cout<<st.size()<<"\n";
    // for(auto & it : st) cout<<it<<" ";

    //sir's solution
    //T.C: 
    // set<int> s;
    // for(int i=0;i<n;i++){
    //     set<int> t;
    //     t.insert(v[i]);
    //     for(auto & x : s){
    //         t.insert(x + v[i]);
    //     }
    //     for(auto & x : t){
    //         s.insert(x);
    //     }
    // }
    // cout<<s.size()<<"\n";
    // for(auto & it : s){
    //     cout<<it<<" ";
    // }
    // cout<<"\n";

    //sir's 2nd solution with iterative dp
    //dp[i] -> 0/1 tells whether the sum = i is possible or not
    int max_sum = accumulate(v.begin(),v.end(),0);
    vector<int> dp(max_sum+1,0);
    dp[0] = 1;//since if we don't take any element, then this sum = 0 is possible (although we don't have to provide in the answer as per the question, but we need this for solving the question)

    for(int i=0; i<n; i++){
        for(int j=max_sum; j>=0; j--){//necessary to from max_sum to 0, won't work if go from 0 to max_sum as then we might end up taking an element more than once {dry run to understand better}
            if(v[i]<=j)
                if(dp[j-v[i]]) dp[j] = 1;
            // if(dp[j]){//also works
            //     dp[j+v[i]] = 1;
            // }
        }
    }

    vector<int> ans;
    for(int i=1;i<=max_sum;i++){//not starting from 0 since in example, we see 0 isn't mentioned
        if(dp[i]) ans.push_back(i);
        // cout<<dp[i]<<" ";
    }
    cout<<ans.size()<<"\n";
    for(int i=0; i<ans.size();i++) cout<<ans[i]<<" ";


    return 0;
}   