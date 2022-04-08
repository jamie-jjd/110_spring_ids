/*
* author: jamie
* email: jinjiedeng.jjd@gmail.com
*/
#include <iostream>
#include <queue>
#include <vector>

int main ()
{
  uint64_t n, k;
  std::cin >> n >> k;
  std::priority_queue<uint64_t, std::vector<uint64_t>, std::greater<uint64_t>> min_heap_k;
  for (uint64_t i {}, revenue; i != k; ++i)
  {
    std::cin >> revenue;
    min_heap_k.push(revenue);
  }
  std::priority_queue<uint64_t, std::vector<uint64_t>, std::greater<uint64_t>> min_heap_2k;
  for (uint64_t i {k}, revenue; i != 2 * k; ++i)
  {
    std::cin >> revenue;
    min_heap_k.push(revenue);
    min_heap_2k.push(min_heap_k.top());
    min_heap_k.pop();
  }
  std::cout << min_heap_k.top() << " " << min_heap_2k.top() << "\n";
  for (uint64_t i {2 * k}, revenue; i != n; ++i)
  {
    std::cin >> revenue;
    if (min_heap_k.top() < revenue)
    {
      min_heap_k.push(revenue);
      min_heap_2k.push(min_heap_k.top());
      min_heap_k.pop();
      min_heap_2k.pop();
    }
    else if (min_heap_2k.top() < revenue)
    {
      min_heap_2k.push(revenue);
      min_heap_2k.pop();
    }
    std::cout << min_heap_k.top() << " " << min_heap_2k.top() << "\n";
  }
  return 0;
}