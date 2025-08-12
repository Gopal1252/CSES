#include<bits/stdc++.h>
using namespace std;

set<vector<int>> bot, top;
vector<int> med = {-1};

void fix(){
    int m = 1 + bot.size() + top.size();//number of elements in the window
    if(bot.size() < (m-1)/2){
        bot.insert(med);
        med = *top.begin();
        top.erase(med);
    }
    if(bot.size() > (m-1)/2){
        top.insert(med);
        med = *--bot.end();
        bot.erase(med);
    }

}

void add(vector<int> x){
    if(med[0] == -1){
        med = x;
        return;
    }
    if(x < med){
        bot.insert(x);
    }
    else{
        top.insert(x);
    }
    fix();//sets the size of the top and the bottom sets
}

void rem(vector<int> x){
    if(x == med){
        med = *top.begin();
        top.erase(med);
    }
    else if(x<med){
        bot.erase(x);
    }
    else{
        top.erase(x);
    }
    fix();
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n,k;
    cin>>n>>k;

    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    if(k == 1){
        for(int i=0;i<n;i++){
            cout<<v[i]<<" ";
        }
        return 0;
    }

    for(int i=0;i<k-1;i++){
        add({v[i],i});
    }

    for(int i=k-1;i<n;i++){
        add({v[i],i});
        cout<<med[0]<<" ";
        rem({v[i-k+1],i-k+1});
    }



    
    return 0;
}