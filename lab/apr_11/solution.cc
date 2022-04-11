/*
* author: jamie
* email: jinjiedeng.jjd@gmail.com
*/
#include <deque>
#include <iostream>
#include <vector>

void BFS
(
  std::vector<std::vector<uint64_t>> const& graph,
  std::vector<bool>& is_in_deque,
  uint64_t source
)
{
  std::deque<uint64_t> queue;
  queue.push_back(source); is_in_deque[source] = true;
  while (!queue.empty())
  {
    auto from {queue.front()}; queue.pop_front(); // this line is the only difference from DFS
    for (auto to : graph[from])
    {
      if (!is_in_deque[to])
      {
        is_in_deque[to] = true;
        queue.push_back(to);
      }
    }
  }
  return;
}

void DFS
(
  std::vector<std::vector<uint64_t>> const& graph,
  std::vector<bool>& is_in_deque,
  uint64_t source
)
{
  std::deque<uint64_t> stack;
  stack.push_back(source); is_in_deque[source] = true;
  while (!stack.empty())
  {
    auto from {stack.back()}; stack.pop_back(); // this line is the only difference from BFS
    for (auto to : graph[from])
    {
      if (!is_in_deque[to])
      {
        is_in_deque[to] = true;
        stack.push_back(to);
      }
    }
  }
  return;
}

uint64_t CountConnectedComponetns (std::vector<std::vector<uint64_t>> const& graph)
{
  uint64_t count {};
  std::vector<bool> is_in_deque(graph.size());
  for (uint64_t source {1}; source != graph.size(); ++source)
  {
    if (!is_in_deque[source])
    {
      ++count;
      /* either BFS or DFS works */
      BFS(graph, is_in_deque, source);
      // DFS(graph, is_in_deque, source);
    }
  }
  return count;
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
    graph[from].push_back(to);
    graph[to].push_back(from);
  }
  std::cout << CountConnectedComponetns(graph);
}