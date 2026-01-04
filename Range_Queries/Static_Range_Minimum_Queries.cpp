#include<bits/stdc++.h>
using namespace std;
 
vector<int> tree;
 
void build(vector<int>& arr, int start, int end, int ind){
    if(start == end){
        tree[ind] = arr[start];
        return;
    }
 
    int mid = (start + end)/2;
 
    build(arr, start, mid, 2*ind);
    build(arr, mid + 1, end, 2*ind + 1);
    tree[ind] = min(tree[2*ind], tree[(2*ind)+1]);
}
 
int query(vector<int>& arr, int start, int end, int l, int r, int ind){
    if(l<=start && r>=end){
        return tree[ind];
    }
 
    if(l>end || r<start){
        return INT_MAX;
    }
 
    int mid = (start + end)/2;
    return min(query(arr,start,mid,l,r, 2*ind), query(arr,mid+1,end,l,r, 2*ind + 1));
}
 
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int n,q;
    cin>>n>>q;
 
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
 
    tree.resize(4*n,0);
 
    build(v,0,n-1,1);
 
    while(q--){
        int a,b;
        cin>>a>>b;
 
        cout<<query(v,0,n-1,a-1,b-1,1)<<"\n";
    }
    
    return 0;
}