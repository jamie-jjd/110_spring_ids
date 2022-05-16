/*
* author: jamie
* email: jinjiedeng.jjd@gmail.com
*/
#include <deque>
#include <iostream>
#include <vector>

void CalculateMaxIndex
(
  std::vector<std::vector<uint64_t>> const& graph,
  std::vector<uint64_t>& max_index,
  uint64_t s
)
{
  std::vector<bool> is_in_deque(graph.size());
  std::vector<uint64_t> distance(graph.size());
  std::deque<uint64_t> queue;
  queue.emplace_back(s); is_in_deque[s] = true;
  while (!queue.empty())
  {
    auto from {queue.front()}; queue.pop_front();
    for (auto to : graph[from])
    {
      if (!is_in_deque[to])
      {
        queue.emplace_back(to); is_in_deque[to] = true;
        distance[to] = distance[from] + 1;
        if (max_index[distance[to]] < to) { max_index[distance[to]] = to; }
      }
    }
  }
  {
    max_index[0] = s;
    for (uint64_t i {}; i != graph.size(); ++i)
    {
      if (distance[i] == 0 && max_index[0] < i) { max_index[0] = i; }
    }
  }
  return;
}

int main ()
{
  uint64_t n, m, s;
  std::cin >> n >> m >> s;
  std::vector<std::vector<uint64_t>> graph(n + 1);
  while (m--)
  {
    uint64_t from, to;
    std::cin >> from >> to;
    graph[from].push_back(to);
    graph[to].push_back(from);
  }
  std::vector<uint64_t> max_index(n);
  CalculateMaxIndex(graph, max_index, s);
  for (uint64_t i {}, d; i != n; ++i)
  {
    std::cin >> d;
    std::cout << max_index[d] << " ";
  }
  return 0;
}