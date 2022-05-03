/*
* author: jamie
* email: jinjiedeng.jjd@gmail.com
*/
#include <deque>
#include <iostream>
#include <vector>

bool IsBipartite (std::vector<std::vector<uint64_t>> const& graph)
{
  std::vector<bool> color(graph.size());
  std::vector<bool> is_in_deque(graph.size());
  std::deque<uint64_t> queue;
  queue.push_back(1);
  is_in_deque[1] = true;
  while (!queue.empty())
  {
    auto from {queue.front()}; queue.pop_front();
    for (auto to : graph[from])
    {
      if (!is_in_deque[to])
      {
        color[to] = !color[from];
        queue.push_back(to);
        is_in_deque[to] = true;
      }
      else if (color[from] == color[to]) { return false; }
    }
  }
  return true;
}

int main ()
{
  uint64_t V, E;
  std::cin >> V >> E;
  std::vector<std::vector<uint64_t>> graph(V + 1);
  while (E--)
  {
    uint64_t from, to;
    std::cin >> from >> to;
    graph[from].push_back(to);
    graph[to].push_back(from);
  }
  std::cout << (IsBipartite(graph) ? "YES" : "NO");
  return 0;
}