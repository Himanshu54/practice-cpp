#include <iostream>
#include <stdlib.h>
#include <vector>
#include <queue>
/*
A Class implementing bredth first search
*/

int bfs(std::vector<std::vector<int>> &Adj,int n,int s){

    std::queue <int> q;
    std::vector <bool> used(n);
    std::vector <int> p(n), d(n);

    q.push(s);
    used[s] = true;
    p[s] = -1;
    d[s] = 0;

    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int u:Adj[v]){
            if(!used[u]){
                q.push(u);
                used[u] = true;
                d[u] = d[v] + 1;
                p[u] =v;
            }
        }
    }
}

