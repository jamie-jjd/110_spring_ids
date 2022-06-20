/*
* author: jamie
* email: jinjiedeng.jjd@gmail.com
*/
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

bool IsConnected (std::vector<std::vector<uint64_t>> const& adj)
{
  std::vector<uint64_t> stack;
  std::vector<bool> is_in_stack(adj.size());
  stack.emplace_back(0); is_in_stack[0]= true;
  while (!stack.empty())
  {
    auto u {stack.back()}; stack.pop_back();
    for (auto v : adj[u])
    {
      if (!is_in_stack[v])
      {
        stack.emplace_back(v); is_in_stack[v] = true;
      }
    }
  }
  return (std::accumulate(is_in_stack.begin(), is_in_stack.end(), 0ULL) == adj.size());
}

bool IsAllEvenDegree (std::vector<std::vector<uint64_t>> const& adj)
{
  return (std::count_if(adj.begin(), adj.end(), [&] (auto& list) { return (list.size() % 2 == 1); }) == 0);
}

bool IsExistedEulerCircuit (std::vector<std::vector<uint64_t>> const& adj)
{
  return (IsConnected(adj) && IsAllEvenDegree(adj));
}

int main ()
{
  uint64_t T; std::cin >> T;
  while (T--)
  {
    uint64_t n, m; std::cin >> n >> m;
    std::vector<std::vector<uint64_t>> adj(n);
    while (m--)
    {
      uint64_t u, v; std::cin >> u >> v;
      adj[u].emplace_back(v);
      adj[v].emplace_back(u);
    }
    std::cout << ((IsExistedEulerCircuit(adj) ? "yes" : "no")) << "\n";
  }
  return 0;
}