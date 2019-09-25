#include <iostream>
#include <queue>
#include <stdlib.h>
#include <vector>

int bfs(std::vector<std::vector<int>> &Adj, int n, int s) {

  std::queue<int> q;
  std::vector<bool> used(n);
  std::vector<int> p(n), d(n);

  q.push(s);
  used[s] = true;
  p[s] = -1;
  d[s] = 0;

  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int u : Adj[v]) {
      if (!used[u]) {
        q.push(u);
        used[u] = true;
        d[u] = d[v] + 1;
        p[u] = v;
      }
    }
  }
  return 0;
}

int main(){
    std::vector < std::vector <int>> adj;
    int s = 0;
    int n = 5;

    for(int i =0;i<n;i++){
        std::vector <int> r;
        adj.push_back(r);
    }

    adj[0].push_back(1);
    adj[0].push_back(4);
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[3].push_back(5);

    bfs(adj,n,s);

    return 0;
}
