/*
* author: redleaf
* email: redleaf23477@gapp.nthu.edu.tw
*/

#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    int n, q; cin >> n >> q;
    vector<vector<int>> graph(n);
    for (int u = 0; u < n; u++) {
        int m; cin >> m;
        while (m--) {
            int v; cin >> v;
            graph[u].emplace_back(v);
        }
    }

    vector<int> dep(n, 0);
    int installed_num = 0;
    vector<int> is_installed(n, 0);  // 0: uninstalled, 1: user installed, 2: system installed

    function<int(int)> install = [&](int u) {
        is_installed[u] = 2;
        installed_num += 1;
        int ans = 1;
        for (auto v : graph[u]) {
            dep[v] += 1;
            if (is_installed[v] == 0) ans += install(v);
        }
        return ans;
    };
    function<int(int)> remove = [&](int u) {
        if (dep[u] != 0 || is_installed[u] == 1) return 0;
        is_installed[u] = 0;
        installed_num -= 1;
        int ans = 1;
        for (auto v : graph[u]) {
            dep[v] -= 1;
            ans += remove(v);
        }
        return ans;
    };

    while (q--) {
        string cmd; cin >> cmd;
        if (cmd[0] == 'I') {
            int p; cin >> p;
            cout << install(p) << "\n";
            is_installed[p] = 1;
        } else if (cmd[0] == 'R') {
            int p; cin >> p;
            if (dep[p] == 0) {
                is_installed[p] = 2;
                cout << remove(p) << "\n";
            } else {
                cout << 0 << "\n";
            }
        } else {
            cout << installed_num;
            for (int p = 0; p < n; p++) if (is_installed[p] != 0) {
                cout << " " << p;
            }
            cout << "\n";
        }
    }
}

/*
* author: jamie
* email: jinjiedeng.jjd@gmail.com
*/
#include <deque>
#include <iostream>
#include <set>
#include <vector>

uint64_t Install
(
  std::vector<std::vector<uint64_t>> const& adj,
  std::set<uint64_t>& user_installed,
  std::set<uint64_t>& auto_installed,
  std::vector<uint64_t>& in_degree,
  uint64_t x
)
{
  uint64_t count {};
  std::deque<uint64_t> queue;
  user_installed.insert(x);
  queue.emplace_back(x);
  while (!queue.empty())
  {
    ++count;
    auto u {queue.front()}; queue.pop_front();
    for (auto& v : adj[u])
    {
      if (user_installed.count(v) == 0 && auto_installed.count(v) == 0)
      {
        auto_installed.insert(v);
        queue.emplace_back(v);
      }
      ++in_degree[v];
    }
  }
  return count;
}

uint64_t Remove
(
  std::vector<std::vector<uint64_t>> const& adj,
  std::set<uint64_t>& user_installed,
  std::set<uint64_t>& auto_installed,
  std::vector<uint64_t>& in_degree,
  uint64_t x
)
{
  uint64_t count {};
  std::deque<uint64_t> queue;
  if (in_degree[x] == 0)
  {
    if (user_installed.count(x))      { user_installed.erase(x); }
    else if (auto_installed.count(x)) { auto_installed.erase(x); }
    queue.emplace_back(x);
    while (!queue.empty())
    {
      ++count;
      auto u {queue.front()}; queue.pop_front();
      for (auto v : adj[u])
      {
        --in_degree[v];
        if (auto_installed.count(v) && in_degree[v] == 0)
        {
          auto_installed.erase(v);
          queue.emplace_back(v);
        }
      }
    }
  }
  return count;
}

int main ()
{
  uint64_t n, q; std::cin >> n >> q;
  std::vector<std::vector<uint64_t>> adj(n);
  std::vector<uint64_t> in_degree(n);
  for (uint64_t u {}; u != n; ++u)
  {
    uint64_t m; std::cin >> m;
    while (m--)
    {
      uint64_t v; std::cin >> v;
      adj[u].emplace_back(v);
    }
  }
  std::set<uint64_t> user_installed, auto_installed;
  while (q--)
  {
    std::string operation;
    uint64_t x;
    std::cin >> operation;
    if (operation == "INSTALL")
    {
      std::cin >> x;
      std::cout << Install(adj, user_installed, auto_installed, in_degree, x) << "\n";
    }
    else if (operation == "REMOVE")
    {
      std::cin >> x;
      std::cout << Remove(adj, user_installed, auto_installed, in_degree, x) << "\n";
    }
    else if (operation == "LIST")
    {
      auto installed {user_installed};
      for (auto x : auto_installed) { installed.insert(x); }
      std::cout << installed.size();
      for (auto x : installed) { std::cout << " " << x; }
      std::cout << "\n";
    }
  }
  return 0;
}