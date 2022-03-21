/*
* author: jamie
* email: jinjiedeng.jjd@gmail.com
*/
#include <iostream>
#include <vector>

int main ()
{
  uint64_t n, m;
  std::cin >> n >> m;
  std::vector<std::vector<uint64_t>> friends(n + 1); // adjacency list
  while (m--)
  {
    uint64_t x, y;
    std::cin >> x >> y;
    friends[x].push_back(y);
    friends[y].push_back(x);
  }
  uint64_t max_sum {};
  for (uint64_t x {1}; x <= n; ++x)
  {
    auto is_friend_of_friend_of_x {std::vector<bool>(n + 1)};
    for (auto y : friends[x])
    {
      for (auto z : friends[y])
      {
        is_friend_of_friend_of_x[z] = (x != z);
      }
    }
    uint64_t sum {};
    for (uint64_t z {1}; z <= n; ++z)
    {
      if (is_friend_of_friend_of_x[z]) { sum += z; }
    }
    if (max_sum < sum) { max_sum = sum; }
  }
  std::cout << max_sum;
  return 0;
}

int main ()
{
  uint64_t n, m;
  std::cin >> n >> m;
  std::vector<std::vector<bool>> is_friend(n + 1, std::vector<bool>(n + 1)); // adjacency matrix
  while (m--)
  {
    uint64_t x, y;
    std::cin >> x >> y;
    is_friend[x][y] = is_friend[y][x] = true;
  }
  uint64_t max_sum {};
  for (uint64_t x {1}; x <= n; ++x)
  {
    auto is_friend_of_friend_of_x {std::vector<bool>(n + 1)};
    for (uint64_t y {1}; y <= n; ++y)
    {
      if (is_friend[x][y])
      {
        for (uint64_t z {1}; z <= n; ++z)
        {
          if (is_friend[y][z]) { is_friend_of_friend_of_x[z] = (x != z); }
        }
      }
    }
    uint64_t sum {};
    for (uint64_t z {1}; z <= n; ++z)
    {
      if (is_friend_of_friend_of_x[z]) { sum += z; }
    }
    if (max_sum < sum) { max_sum = sum; }
  }
  std::cout << max_sum;
  return 0;
}

/*
* author: redleaf
* email: redleaf23477@gapp.nthu.edu.tw
*/
#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    int n, m; cin >> n >> m;
    // adjacency matrix
    vector<vector<bool>> graph(n, vector<bool>(n, false));
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        graph[u][v] = graph[v][u] = true;
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        vector<bool> vis(n, false);
        for (int u = 0; u < n; u++) if (graph[i][u]) {
            for (int v = 0; v < n; v++) if (graph[u][v]) {
                vis[v] = true;
            }
        }
        vis[i] = false;
        int sum = 0;
        for (int j = 0; j < n; j++) {
            if (vis[j]) sum += j+1;
        }
        ans = max(ans, sum);
    }

    cout << ans << "\n";
}

int main() {
    int n, m; cin >> n >> m;
    // adjacency list
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        vector<bool> vis(n, false);
        for (auto u : graph[i]) {
            for (auto v : graph[u]) {
                vis[v] = true;
            }
        }
        int sum = 0;
        vis[i] = false;
        for (int j = 0; j < n; j++) {
            if (vis[j]) sum += j+1;
        }
        ans = max(sum, ans);
    }
    cout << ans << endl;
}