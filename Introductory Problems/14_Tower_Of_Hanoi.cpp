#include<bits/stdc++.h>
using namespace std;

//aditya verma:https://www.youtube.com/watch?v=l45md3RYX7c

//s->source, d->destination, h->helper
void toh(int s, int d, int h, int n){//toh basically prints how we transfer n disks from s->d
    if(n == 1){
        cout<<s<<" "<<d<<endl;
        return;
    }
    toh(s,h,d,n-1);//move n-1 disks from s->h
    cout<<s<<" "<<d<<endl;
    toh(h,d,s,n-1);//move n-1 disks from h->d
}

int main(){
    int n;
    cin>>n;
    cout<<pow(2,n)-1<<endl;
    toh(1,3,2,n);

    return 0;
}