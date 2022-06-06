/*
* author: redleaf
* email: redleaf23477@gapp.nthu.edu.tw
*/
#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL MOD = 1e9+7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<vector<int>> graph(n);
    vector<int> indeg(n, 0);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v; u--, v--;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
        indeg[u]++, indeg[v]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indeg[i] == 1) q.emplace(i);
    }
    int ans = 1;
    vector<int> dist(n, 1);
    vector<bool> popped(n, false);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        popped[u] = true;
        for (auto v : graph[u]) {
            if (!popped[v]) {
                ans = max(ans, dist[u] + dist[v]);
                dist[v] = max(dist[v], dist[u] + 1);
                if (--indeg[v] == 1) q.emplace(v);
            }
        }
    }
    cout << ans-1 << "\n";
}

/*
* author: jamie
* email: jinjiedeng.jjd@gmail.com
*/
#include <deque>
#include <iostream>
#include <tuple>
#include <vector>

std::pair<uint64_t, uint64_t> FarthestNode
(
  std::vector<std::vector<uint64_t>> const& adj,
  uint64_t parent_from,
  uint64_t from
)
{
  std::deque<std::tuple<uint64_t, uint64_t, uint64_t>> queue;
  uint64_t d {};
  queue.emplace_back(parent_from, from, d);
  while (!queue.empty())
  {
    std::tie(parent_from, from, d) = queue.front(); queue.pop_front();
    for (auto to : adj[from])
    {
      if (to != parent_from) { queue.emplace_back(from, to, d + 1); }
    }
  }
  return std::make_pair(from, d);
}

// find both end of longest path
int main ()
{
  uint64_t n;
  std::cin >> n;
  std::vector<std::vector<uint64_t>> adj(n + 1);
  for (uint64_t i {1}; i != n; ++i)
  {
    uint64_t from, to;
    std::cin >> from >> to;
    adj[from].push_back(to);
    adj[to].push_back(from);
  }
  uint64_t node, distance;
  // for any node, say 1, one of two ends of the longest path in the tree is the farthest "node" from 1
  std::tie(node, std::ignore) = FarthestNode(adj, 0, 1);
  // the other end of the longest path in the tree is the farthest node from "node"
  std::tie(std::ignore, distance) = FarthestNode(adj, 0, node);
  std::cout << distance;
  return 0;
}