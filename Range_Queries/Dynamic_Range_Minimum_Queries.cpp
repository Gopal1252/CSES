#include<bits/stdc++.h>
using namespace std;
 
vector<int> tree;
 
void build(vector<int>& arr, int start, int end, int ind){
    if(start == end){
        tree[ind] = arr[start];
        return;
    }
 
    int mid = (start + end)/2;
    build(arr,start,mid,2*ind);
    build(arr,mid+1,end,2*ind+1);
    tree[ind] = min(tree[2*ind],tree[2*ind+1]);
}
 
void update(vector<int>& arr, int start, int end, int ind, int pos, int val){
    if(start == end){
        arr[pos] = val;
        tree[ind] = arr[pos];
        return;
    }
 
    int mid = (start + end)/2;
 
    if(pos <= mid){
        update(arr,start,mid,2*ind,pos,val);
    }
    else{
        update(arr,mid+1,end,2*ind+1,pos,val);
    }
    tree[ind] = min(tree[2*ind],tree[2*ind+1]);
}
 
int query(vector<int>& arr, int start, int end, int l, int r, int ind){
    //complete overlap
    if(l<=start && end<=r){
        return tree[ind];
    }
 
    //no overlap
    if(end<l || start>r){
        return INT_MAX;
    }
 
    int mid = (start + end)/2;
    return min(query(arr,start,mid,l,r,2*ind),query(arr,mid+1,end,l,r,2*ind+1));
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int n,q;
    cin>>n>>q;
 
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
 
    tree.resize(4*n);
    build(arr,0,n-1,1);
 
    while(q--){
        int t,a,b;
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