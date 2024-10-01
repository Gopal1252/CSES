#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> med = {-1};
set<vector<ll>> bot,top;
ll bsum = 0,tsum = 0;


void fix(){
    ll m  = 1 + bot.size() + top.size();
    if(bot.size() < (m-1)/2){//(m-1)/2 and not m/2 since we want the smaller of the elements as the median
        bot.insert(med);
        bsum += med[0];

        med = *top.begin();

        top.erase(med);
        tsum -= med[0];
    }
    if(bot.size() > (m-1)/2){
        top.insert(med);
        tsum += med[0];

        med = *--bot.end();

        bot.erase(med);
        bsum -= med[0];
    }
}

void add(vector<ll> v){
    if(med[0] == -1){
        med = v;
        return;
    }
    if(v < med){
        bot.insert(v);
        bsum += v[0];
    }
    else{
        top.insert(v);
        tsum += v[0];
    }
    fix();
}

void rem(vector<ll> v){
    if(v == med){
        med = *top.begin();
        top.erase(med);
        tsum -= med[0];
    }
    else if(v<med){
        bot.erase(v);
        bsum -= v[0];
    }
    else{
        top.erase(v);
        tsum -= v[0];
    }
    fix();
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n,k;
    cin>>n>>k;

    vector<ll> v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i];
    }

    if(k == 1){
        for(ll i=0;i<n;i++){
            cout<<0<<" ";
        }
        return 0;
    }

    for(ll i=0;i<k-1;i++){
        add({v[i],i});
    }

    for(ll i=k-1;i<n;i++){
        add({v[i],i});
        cout<< abs((ll)(bot.size())*med[0] - bsum) + abs((ll)(top.size())*med[0] - tsum)<<" ";
        rem({v[i-k+1],i-k+1});
    }

    return 0;
}