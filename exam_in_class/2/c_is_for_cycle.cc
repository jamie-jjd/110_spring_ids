/*
* author: redleaf
* email: redleaf23477@gapp.nthu.edu.tw
*/
#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n, m; cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }
    vector<bool> vis(n, false);
    vector<int> stk;
    function<bool(int,int)> dfs = [&](int u, int pa) {
        vis[u] = true;
        stk.emplace_back(u);
        for (auto v : graph[u]) {
            if (v == pa) continue;
            if (vis[v]) {
                auto i = find(stk.begin(), stk.end(), v) - stk.begin();
                cout << stk.size() - i << "\n";
                for (; i < stk.size(); i++) {
                    cout << stk[i] + 1 << " ";
                }
                cout << "\n";
                return true;
            } else {
                if (dfs(v, u)) return true;
            }
        }
        stk.pop_back();
        return false;
    };
    bool ans = false;
    for (int i = 0; i < n && !ans; i++) {
        if (!vis[i]) {
            ans = dfs(i, i);
        }
    }
    if (!ans) {
        cout << "IMPOSSIBLE\n";
    }
}

/*
* author: jamie
* email: jinjiedeng.jjd@gmail.com
*/
#include <iostream>
#include <vector>

bool IsCycleExisted
(
  std::vector<std::vector<uint64_t>> const& graph,
  std::vector<bool>& is_visited,
  uint64_t parent_from,
  uint64_t from,
  std::vector<uint64_t>& cycle
)
{
  static uint64_t detected_node {};
  is_visited[from] = true;
  for (auto to : graph[from])
  {
    if (!is_visited[to])
    {
      if (IsCycleExisted(graph, is_visited, from, to, cycle))
      {
        if (detected_node)
        {
          if (from == detected_node) { detected_node = 0; }
          cycle.push_back(from);
        }
        return true;
      }
    }
    else if (to != parent_from)
    {
      detected_node = to;
      cycle.push_back(from);
      return true;
    }
  }
  return false;
}

int main ()
{
  uint64_t n, m;
  std::cin >> n >> m;
  std::vector<std::vector<uint64_t>> graph(n + 1);
  while (m--)
  {
    uint64_t from, to;
    std::cin >> from >> to;
    graph[from].emplace_back(to);
    graph[to].emplace_back(from);
  }
  std::vector<bool> is_visited(n + 1);
  std::vector<uint64_t> cycle;
  for (uint64_t source {1}; source != graph.size(); ++source)
  {
    if (!is_visited[source])
    {
      if (IsCycleExisted(graph, is_visited, 0, source, cycle)) { break; }
    }
  }
  if (!cycle.empty())
  {
    std::cout << cycle.size() << "\n";
    for (auto v : cycle) { std::cout << v << " "; }
  }
  else { std::cout << "IMPOSSIBLE"; }
  return 0;
}