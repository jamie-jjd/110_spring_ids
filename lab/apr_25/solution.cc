/*
* author: jamie
* email: jinjiedeng.jjd@gmail.com
*/
#include <deque>
#include <iostream>
#include <numeric>
#include <vector>

/* topological sort (with queue) */
bool IsDAG (std::vector<std::vector<uint64_t>> const& graph)
{
  std::vector<uint64_t> in_degree(graph.size());
  for (auto& tos : graph)
  {
    for (auto to : tos) { ++in_degree[to]; }
  }
  std::deque<uint64_t> queue;
  for (uint64_t i {1}; i != graph.size(); ++i)
  {
    if (in_degree[i] == 0) { queue.push_back(i); }
  }
  while (!queue.empty())
  {
    auto from {queue.front()}; queue.pop_front();
    for (auto to : graph[from])
    {
      if (--in_degree[to] == 0) { queue.push_back(to); }
    }
  }
  return (std::accumulate(in_degree.begin(), in_degree.end(), 0ULL) == 0);
}

/* iterative version */
// void DFS
// (
//   std::vector<std::vector<uint64_t>> const& graph,
//   std::vector<uint64_t>& finished_time,
//   uint64_t source
// )
// {
//   static std::vector<bool> is_forward(graph.size(), true);
//   static uint64_t time {1};
//   std::deque<uint64_t> stack;
//   stack.push_back(source);
//   while (!stack.empty())
//   {
//     auto from {stack.back()};
//     if (is_forward[from])
//     {
//       is_forward[from] = false;
//       for (auto to : graph[from])
//       {
//         if (finished_time[to] == 0) { stack.push_back(to); }
//       }
//     }
//     else
//     {
//       if (finished_time[from] == 0) { finished_time[from] = time++; }
//       stack.pop_back();
//     }
//   }
//   return;
// }

/* recursive version */
// void DFS
// (
//   std::vector<std::vector<uint64_t>> const& graph,
//   std::vector<uint64_t>& finished_time,
//   uint64_t from
// )
// {
//   static std::vector<bool> is_forward(graph.size(), true);
//   static uint64_t time {1};
//   is_forward[from] = false;
//   for (auto to : graph[from])
//   {
//     if (is_forward[to]) { DFS(graph, finished_time, to); }
//   }
//   finished_time[from] = time++;
//   return;
// }

/* topological sort (DFS) */
// bool IsDAG (std::vector<std::vector<uint64_t>> const& graph)
// {
//   std::vector<uint64_t> finished_time(graph.size());
//   for (uint64_t source {1}; source != graph.size(); ++source)
//   {
//     if (finished_time[source] == 0) { DFS(graph, finished_time, source); }
//   }
//   bool is_DAG {true};
//   for (uint64_t from {1}; from != graph.size(); ++from)
//   {
//     for (auto to : graph[from]) { is_DAG &= (finished_time[to] < finished_time[from]); }
//   }
//   return is_DAG;
// }

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
  }
  std::cout << (IsDAG(graph) ? "yes" : "no");
  return 0;
}