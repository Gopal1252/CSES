#include<bits/stdc++.h>
using namespace std;

#define ll long long
//read post and then see video
//https://codeforces.com/blog/entry/86912
//https://www.youtube.com/watch?v=_JXb1AjcPlU

void solve(){
    ll n;
    cin>>n;
    ll sum = (n*(n+1))/2;
    vector<int> v1,v2;
    if(sum%2 != 0){
        cout<<"NO"<<endl;
        return;
    }
    else{
        cout<<"YES"<<endl;
        if(n%2 == 0){//basically the case where n%4 = 0
            int i = 1;
            for(i=1;i<=n/4;i++){
                v1.push_back(i);
                v1.push_back(n-i+1);
            }
            for(i=i;i<n-i+1;i++){
                v2.push_back(i);
                v2.push_back(n-i+1);
            }
        }
        else{//basically the case where n%4 = 3 or n is of tyype 4k+3
            v1.push_back(1);
            v1.push_back(2);
            v2.push_back(3);
            int i = 1;
            for(i=1;i<=n/4;i++){
                v1.push_back(i+3);
                v1.push_back(n-i+1);
            }
            for(i=i;i+3<n-i+1;i++){
                v2.push_back(i+3);
                v2.push_back(n-i+1);
            }
        }
    }

    cout<<v1.size()<<endl;
    for(int i=0;i<v1.size();i++){
        cout<<v1[i]<<" ";
    }
    cout<<endl;
    cout<<v2.size()<<endl;
    for(int i=0;i<v2.size();i++){
        cout<<v2[i]<<" ";
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    solve();


    return 0;
}