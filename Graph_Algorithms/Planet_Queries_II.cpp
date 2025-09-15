#include<bits/stdc++.h>
using namespace std;

//functional graphs
//for understanding what's a functional graph, see usaco guide {link in next line}
//https://usaco.guide/problems/cses-1160-planets-queries-ii/solution

//chatGPT's take:
//https://chatgpt.com/share/68c69f7b-b3f4-8013-a55f-c8de59fd03c6

const int mxN = 2e5+10;
vector<int> vis(mxN);
vector<int> adj(mxN,0);
vector<int> component(mxN,-1);//component id for each node
vector<int> dist_to_cycle(mxN,-1);//distance of a node from the cycle {equal to 0 for cycle nodes}
vector<int> cycle_pos(mxN,-1); //stores position of a node in the cycle
vector<int> cycle_size(mxN,0);//stores the size of each cycle
int n,q;
int comp_id = 0;

void dfs(int node, vector<int>& stack, vector<int>& index, vector<bool>& in_stack){
    vis[node] = 1;
    index[node] = stack.size();//index[node] stores the index of node in the stack
    stack.push_back(node);
    in_stack[node] = 1;

    int nxt = adj[node];

    if(!vis[nxt]){
        dfs(nxt,stack,index,in_stack);
    }
    else if(in_stack[nxt]){//found a cycle
        comp_id++;
        int sz = stack.size() - index[nxt];//size of cycle
        cycle_size[comp_id] = sz;

        for(int i=index[nxt];i<stack.size();i++){
            int cyc_node = stack[i];
            component[cyc_node] = comp_id;
            dist_to_cycle[cyc_node] = 0;
            cycle_pos[cyc_node] = i - index[nxt];
        }
    }

    in_stack[node] = false;
    stack.pop_back();
}

bool actuallyReaching(int a, int b, int diff, vector<vector<int>>& binJump){
    for(int i=0;i<=31;i++){
        if(diff&(1<<i)){
            a = binJump[i][a];
        }
    }
    return (a == b);
}

int getCycleNode(int a, int diff, vector<vector<int>>& binJump){
    for(int i=0;i<=31;i++){
        if(diff&(1<<i)){
            a = binJump[i][a];
        }
    }
    return a;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n>>q;

    for(int i=1;i<=n;i++){
        cin>>adj[i];
    }

    //detect all cycles and assign the components
    vector<int> stack;
    vector<int> index(n+1,-1);

    vector<bool> in_stack(n+1);

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,stack,index,in_stack);
        }
    }

    //assign distances for treee nodes

    for(int i=1;i<=n;i++){
        if(component[i] == -1){
            int cur = i;
            vector<int> path;
            while(component[cur] == -1){
                path.push_back(cur);
                cur = adj[cur];
            }
            int comp = component[cur];
            int d = dist_to_cycle[cur] + 1;
            for(int j=path.size()-1;j>=0;j--){
                int node = path[j];
                dist_to_cycle[node] = d++;
                component[node] = comp;
            }
        }
    }

    vector<vector<int>> binJump(32,vector<int>(n+1,0));
    for(int i=1;i<=n;i++){
        binJump[0][i] = adj[i];
    }

    for(int j=1;j<=31;j++){
        for(int i=1;i<=n;i++){
            binJump[j][i] = binJump[j-1][binJump[j-1][i]];
        }
    }

    while(q--){
        int a,b;
        cin>>a>>b;

        if(component[a] != component[b]){//in different components
            cout<<-1<<"\n";
            continue;
        }

        if(dist_to_cycle[a] >= dist_to_cycle[b]){//possible to reach b only in this case
            int diff = dist_to_cycle[a] - dist_to_cycle[b];

            if(dist_to_cycle[b] == 0 && dist_to_cycle[a] > 0){//tree node to cycle node
                int to_cycle = dist_to_cycle[a];
                int pos_a = cycle_pos[getCycleNode(a,to_cycle,binJump)];
                int pos_b = cycle_pos[b];
                int sz = cycle_size[component[a]];
                int cycle_steps = (pos_b - pos_a + sz)%sz;
                cout<<to_cycle + cycle_steps<<"\n";
            }
            else if(dist_to_cycle[b] == 0 && dist_to_cycle[a] == 0){//both are a part of the cycle
                int pos_a = cycle_pos[a];
                int pos_b = cycle_pos[b];
                int sz = cycle_size[component[a]];
                int cycle_steps = (pos_b - pos_a + sz)%sz;
                cout<<cycle_steps<<"\n";
            }
            else if(dist_to_cycle[b]>0){//both in tree
                if(actuallyReaching(a,b,diff,binJump)){//check if in same tree or different tree
                    cout<<diff<<"\n";
                }
                else{
                    cout<<-1<<"\n";
                }
            }
            else{
                cout<<-1<<"\n";
            }
        }
        else{
            cout<<-1<<"\n";
        }
    }


    return 0;
}