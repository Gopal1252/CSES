#include<bits/stdc++.h>
using namespace std;
//https://www.geeksforgeeks.org/cses-solutions-nested-ranges-check/
static bool cmp(vector<int>& v1, vector<int>& v2){
    if(v1[0] != v2[0]){
        return v1[0] < v2[0];
    }
    else return v1[1] > v2[1];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;

    vector<vector<int>> v;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,y,i});
    }

    sort(v.begin(),v.end(),cmp);

    vector<int> ans1(n);
    int minRgt = INT_MAX;
    for(int i=n-1;i>=0;i--){
        if(v[i][1] >= minRgt){
            ans1[v[i][2]] = 1;
        }
        minRgt = min(minRgt,v[i][1]);
    }

    vector<int> ans2(n);
    int maxRgt = INT_MIN;
    for(int i=0;i<n;i++){
        if(v[i][1] <= maxRgt){
            ans2[v[i][2]] = 1;
        }
        maxRgt = max(maxRgt,v[i][1]);
    }

    for(auto &it : ans1){
        cout<<it<<" ";
    }
    cout<<"\n";
    for(auto &it : ans2){
        cout<<it<<" ";
    }


    return 0;
}