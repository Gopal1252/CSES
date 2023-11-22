#include<bits/stdc++.h>
using namespace std;

#define ll long long

//took hint from this video:
//https://www.youtube.com/watch?v=HQmiQ6Sd_OE
void solve(){
    ll x,y;
    cin>>x>>y;
    if(x>y){
        //in rows->
            //if x is even -> first element is x^2
            //also then element is -> x^2 - (y-1)
            if(x%2 == 0){
                cout<<(x*x) - (y-1);
                cout<<endl;
                return;
            }
            //if x is odd -> first element is (x-1)^2+1
            //also then element is -> (x-1)^2 + 1 + (y-1) 
            else{
                cout<<((x-1)*(x-1)) + 1 + (y-1);
                cout<<endl;
                return;
            }
    }
    else{
        //in columns->
            //if y is odd -> first element is y^2
            //also thhen element is y^2 - (x-1)
            if(y%2 != 0){
                cout<<(y*y) - (x-1);
                cout<<endl;
                return;
            }
            //if y is even -> first element is (y-1)^2 + 1
            //also then element is -> (y-1)^2 + 1 + (x-1)
            else{
                cout<<((y-1)*(y-1)) + 1 + (x-1);
                cout<<endl;
                return;
            }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        solve();
    }


    return 0;
}