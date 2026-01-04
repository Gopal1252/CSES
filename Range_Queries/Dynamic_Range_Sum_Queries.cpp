#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
vector<ll> tree;
 
void build(vector<ll>& arr, ll start, ll end, ll ind){
    if(start == end){
        tree[ind] = arr[start];
        return;
    }
 
    ll mid = (start + end)/2;
    build(arr, start, mid, 2*ind);
    build(arr, mid + 1, end, 2*ind + 1);
    tree[ind] = tree[2*ind] + tree[2*ind + 1];
}
 
void update(vector<ll>& arr, ll start, ll end, ll ind, ll pos, ll value){
    if(start == end){
        arr[pos] = value;
        tree[ind] = arr[pos];
        return;
    }
 
    ll mid = (start + end)/2;
 
    if(pos <= mid){
        update(arr,start,mid,2*ind,pos,value);
    }
    else{
        update(arr,mid+1,end,2*ind+1,pos,value);
    }
    tree[ind] = tree[2*ind] + tree[2*ind + 1];
}
 
ll query(vector<ll>& arr, ll start, ll end, ll l, ll r, ll ind){
    //complete overlapp
    if(l<=start && end<=r){
        return tree[ind];
    }
 
    //no overlap
    if(end<l || r<start){
        return 0;
    }
 
    ll mid = (start + end)/2;
    return query(arr,start,mid,l,r,2*ind) + query(arr,mid+1,end,l,r,2*ind+1);
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    ll n,q;
    cin>>n>>q;
 
    vector<ll> arr(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
 
    tree.resize(4*n);
 
    build(arr,0,n-1,1);
 
    while(q--){
        ll t,a,b;
        cin>>t>>a>>b;
 
        if(t == 1){
            update(arr,0,n-1,1,a-1,b);
        }
        else{
            cout<<query(arr,0,n-1,a-1,b-1,1)<<"\n";
        }
    }
 
    return 0;
}