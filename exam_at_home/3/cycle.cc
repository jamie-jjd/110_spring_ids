/*
* author: wang-yang
* email: tnst92002@gmail.com
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> V[20];
int ans;
bool used[20];

void dfs(int v, int end, int step) {
    used[v] = true;
    if (step >= ans)
        return ;

    for (int u : V[v]) {
        if (u == end)
            ans = min(ans, step);
        if (!used[u])
            dfs(u, end, step+1);
    }
}

int main() {
    int n, m;

    cin >> n >> m;
    while (m--) {
        int s, t;
        cin >> s >> t;
        V[s].push_back(t);
    }

    ans = INT_MAX;
    for (int i=0;i<n;++i) {
        memset(used, 0, sizeof(used));
        dfs(i, i, 1);
    }

    if (ans == INT_MAX)
        cout << 0 << '\n';
    else
        cout << ans << '\n';
}

/*
* author: jamie
* email: jinjiedeng.jjd@gmail.com
*/
#include <iostream>
#include <vector>

uint64_t MinCycle (std::vector<std::vector<uint64_t>> const& adj, uint64_t u)
{
  static std::vector<uint64_t> distance(adj.size());
  auto min_len {adj.size() + 1};
  for (auto v : adj[u])
  {
    uint64_t len {min_len};
    if (distance[v])
    {
      len = distance[u] + 1 - distance[v];
    }
    else
    {
      distance[v] = distance[u] + 1;
      len = MinCycle(adj, v);
    }
    if (len < min_len) { min_len = len; }
  }
  distance[u] = 0;
  return min_len;
}

int main ()
{
  uint64_t n, m; std::cin >> n >> m;
  std::vector<std::vector<uint64_t>> adj(n);
  while (m--)
  {
    uint64_t u, v; std::cin >> u >> v;
    adj[u].emplace_back(v);
  }
  auto min_len {n + 1};
  for (uint64_t source {}; source != n; ++source)
  {
    auto len {MinCycle(adj, source)};
    if (len < min_len) { min_len = len; }
  }
  if (min_len == n + 1) { min_len = 0; }
  std::cout << min_len << "\n";
  return 0;
}