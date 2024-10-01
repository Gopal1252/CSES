#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;

    queue<int> q;
    for(int i=1;i<=n;i++) q.push(i);

    bool f = 0;
    while(!q.empty()){
        if(f){
            cout<<q.front()<<" ";
            q.pop();
        }
        else{
            q.push(q.front());
            q.pop();
        }
        f = !f;
    }

    return 0;
}