#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;

    vector<int> a(n);
    vector<int> b(n);
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    int i = 0, j = 0;
    int ans = 0;
    int curr = 0;
    while(i<n && j<n){
        if(a[i]<b[j]){
            curr++;
            ans = max(ans,curr);
            i++;
        }
        else if(a[i]>b[j]){
            curr--;
            j++;
        }
        else{
            i++;
            j++;
        }
    }
    while(i<n){
        curr++;
        ans = max(ans,curr);
        i++;
    }

    cout<<ans<<"\n";


    return 0;
}