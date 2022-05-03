/*
* author: redleaf
* email: redleaf23477@gapp.nthu.edu.tw
*/
#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n; cin >> n;
    vector<LL> arr(n);
    for (auto &x : arr) { cin >> x; }
    vector<vector<int>> graph(n);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v; u--, v--;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }
    vector<int> vis(n, false);
    function<int(int,int,int)> dfs = [&](int u, int pa, int dep) {
        vis[u] = true;
        int mxdep = dep;
        for (auto v : graph[u]) {
            if (v != pa) {
                mxdep = max(mxdep, dfs(v, u, dep+1));
                arr[u] += arr[v];
            }
        }
        return mxdep;
    };
    int dep = dfs(0, 0, 0);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " \n"[i==n-1];
    }
}

/*
* author: jamie
* email: jinjiedeng.jjd@gmail.com
*/
#include <iostream>
#include <tuple>
#include <vector>

/* iterative version */
void SubtreeWeight
(
  std::vector<std::vector<uint64_t>> const& tree,
  std::vector<uint64_t>& weight,
  uint64_t parent_from,
  uint64_t from
)
{
  std::vector<bool> is_forward(tree.size(), true);
  std::vector<std::pair<uint64_t, uint64_t>> stack;
  stack.push_back(std::make_pair(parent_from, from));
  while (!stack.empty())
  {
    std::tie(parent_from, from) = stack.back();
    if (is_forward[from])
    {
      is_forward[from] = false;
      for (auto to : tree[from])
      {
        if (to != parent_from) { stack.push_back(std::make_pair(from, to)); }
      }
    }
    else
    {
      for (auto to : tree[from])
      {
        if (to != parent_from) { weight[from] += weight[to]; }
      }
      stack.pop_back();
    }
  }
  return;
}

/* recursive version */
// void SubtreeWeight
// (
//   std::vector<std::vector<uint64_t>> const& tree,
//   std::vector<uint64_t>& weight,
//   uint64_t parent_from,
//   uint64_t from
// )
// {
//   for (auto to : tree[from])
//   {
//     if (to != parent_from)
//     {
//       SubtreeWeight(tree, weight, from, to);
//     }
//   }
//   for (auto to : tree[from])
//   {
//     if (to != parent_from) { weight[from] += weight[to]; }
//   }
//   return;
// }

int main ()
{
  uint64_t n;
  std::cin >> n;
  std::vector<uint64_t> weight(n + 1);
  for (uint64_t i {1}; i != weight.size(); ++i) { std::cin >> weight[i]; }
  std::vector<std::vector<uint64_t>> tree(n + 1);
  for (uint64_t i {1}; i != (tree.size() - 1); ++i)
  {
    uint64_t from, to;
    std::cin >> from >> to;
    tree[from].push_back(to);
    tree[to].push_back(from);
  }
  SubtreeWeight(tree, weight, 0, 1);
  for (uint64_t i {1}; i != weight.size(); ++i)
  {
    std::cout << ((i == 1) ? "" : " ") << weight[i];
  }
  return 0;
}