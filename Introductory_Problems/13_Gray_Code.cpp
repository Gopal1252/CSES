#include<bits/stdc++.h>
using namespace std;

//https://www.youtube.com/watch?v=KOD2BFauQbA
//https://www.japlslounge.com/posts/cses/gray_code/1.htm
//https://leetcode.com/problems/gray-code/submissions/1084457871/

void gray(int n,vector<string>& v){
    if(n == 1){
        v.push_back("0");
        v.push_back("1");
        return;
    }

    gray(n-1,v);
    int sz = v.size();

    for(int i = sz-1;i>=0;i--){
        v.push_back(v[i]);
    }
    for(int i=0;i<sz;i++){
        v[i] = '0' + v[i];
    }
    for(int i=sz;i<v.size();i++){
        v[i] = '1' + v[i]; 
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n;
    cin>>n;
    vector<string> v;
    gray(n,v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }

    return 0;
}