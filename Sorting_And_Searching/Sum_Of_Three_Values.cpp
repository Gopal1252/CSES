#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n,x;
    cin>>n>>x;

    vector<vector<int>> v(n,vector<int>(2,0));
    for(int i=0;i<n;i++){
        cin>>v[i][0];
        v[i][1] = i;
    }

    sort(v.begin(),v.end());

    for(int i=0;i<n;i++){
        int sum = x - v[i][0];
        int j=i+1,k=n-1;
        while(j<k){
            if(v[j][0]+v[k][0] == sum){
                cout<<v[i][1]+1<<" "<<v[j][1]+1<<" "<<v[k][1]+1<<"\n";
                return 0;
            }
            else if(v[j][0]+v[k][0]>sum){
                k--;
            }
            else{
                j++;
            }
        }
    }
    cout<<"IMPOSSIBLE\n";

    return 0;
}