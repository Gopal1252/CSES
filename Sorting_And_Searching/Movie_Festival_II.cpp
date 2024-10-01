#include<bits/stdc++.h>
using namespace std;

//if no one has completed their movie, give it to new person
//else give it to someone who has just finished their movie 
 
//this is william lin's solution
//similar to room allocation problem
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int n,k;
    cin>>n>>k;
 
    vector<vector<int>> v(n,vector<int>(3,0));
    for(int i=0;i<n;i++){
        cin>>v[i][1]>>v[i][0];//save the end time and start time {endtime,starttime} of moview
    }
 
    sort(v.begin(),v.end());//sort the movies in increasing order of their endtime
    set<vector<int>> st;//stores {end_time,index} of the ith movie
 
    int ans = 0;
    for(int i=0;i<n;i++){        
        //basically give the movie to the person who has just completed the movie {highest endtime}
        //this is si because there can be some other movie with an even lower start time
        //so, optimally give movie to the person who finished last
        auto it = st.lower_bound({v[i][1]+1});//find the lowest end_time > current movie's start time
        if(it != st.begin()){//if there is some movie whose end_time is <= current movie's time start time, then the same person can continue to watch this movie as well
            --it;
            st.erase(it);
        }
 
        if(st.size() < k){
            st.insert({v[i][0],i});
            ans++;
        }
    }
    cout<<ans<<"\n";
 
 
    return 0;
}