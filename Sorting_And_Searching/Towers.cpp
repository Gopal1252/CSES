#include<bits/stdc++.h>
using namespace std;
//longest increasing subsequence problem (in disguise)
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    vector<int> tow;

    for(int i=0;i<n;i++){
        if(tow.empty()) tow.push_back(v[i]);
        else{
            int ind = upper_bound(tow.begin(),tow.end(),v[i]) - tow.begin();
            if(ind == tow.size()){
                tow.push_back(v[i]);
            }
            else{
                tow[ind] = v[i];
            }
        }
    }
    cout<<tow.size()<<"\n";

    return 0;
}