#include<bits/stdc++.h>
using namespace std;

//now TC: O(n*L) {the trie will terminate after at most L (length of largest word)}
//when were doing s.substr(i,n-i) ->TC : O(n*n)
//For non optimized Trie (TLE) -> TC : O(n*n*n)
//When not at all using Trie (using set) -> TC : O(n*n*log(k))

const int M = 1e9+7;

class TrieNode{
public:
    vector<TrieNode*> links;
    bool isEnd;

    TrieNode(){
        links = vector<TrieNode*>(26,nullptr);
        isEnd = false;
    }

    void setEnd(){
        isEnd = true;
    }

    bool containsKey(char ch){
        return links[ch-'a'] != nullptr;
    }

    TrieNode* get(char ch){
        return links[ch-'a'];
    }

    void put(char ch, TrieNode* node){
        links[ch-'a'] = node;
    }

};

class Trie{
public:
    TrieNode* root;

    Trie(){
        root = new TrieNode();
    }

    void insert(string& s){
        TrieNode* temp = root;
        for(int i=0;i<s.size();i++){
            if(!temp->containsKey(s[i])){
                temp->put(s[i],new TrieNode());
            }
            temp = temp->get(s[i]);
        }
        temp->setEnd();
    }

    void calc(string& s, int startInd, vector<int>& dp){
        TrieNode* temp = root;
        for(int i=startInd;i<s.size();i++){
            if(temp->containsKey(s[i])){
                temp = temp->get(s[i]);
                if(temp->isEnd){
                    dp[i] = (dp[i] + 0LL + ((startInd-1>=0)?dp[startInd-1]:1))%M;//base case handled via ternary condition (for when i=0) {since i-1 will become -ve (-1)}
                }
            }
            else{
                return;
            }
        }
    }
};


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string s;
    cin>>s;

    int k;
    cin>>k;

    int n = s.size();

    Trie t;

    for(int i=0;i<k;i++){
        string x;
        cin>>x;
        t.insert(x);
    }

    vector<int> dp(n);//dp[i] stores the number of ways to make the string till length i
    
    for(int i=0;i<n;i++){
        t.calc(s,i,dp);
    }
    cout<<dp[n-1]<<"\n";


    return 0;
}