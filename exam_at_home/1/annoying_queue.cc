/*
* author: jamie
* email: jinjiedeng.jjd@gmail.com
*/
#include <deque>
#include <iostream>
#include <vector>

int main ()
{
  int64_t n, m;
  std::cin >> n >> m;
  std::vector<int64_t> count_enqueue(n), count_dequeue(n);
  std::deque<int64_t> queue;
  while (m--)
  {
    int64_t op, id;
    std::cin >> op;
    if (op == 0)
    {
      std::cin >> id;
      queue.push_back(id);
      ++count_enqueue[id];
    }
    else if (op == 1)
    {
      while (!queue.empty() && !(count_enqueue[queue.front()] == 1 && count_dequeue[queue.front()] == 0))
      {
        --count_enqueue[queue.front()];
        --count_dequeue[queue.front()];
        queue.pop_front();
      }
      if (!queue.empty())
      {
        std::cout << queue.front() << "\n";
        --count_enqueue[queue.front()];
        queue.pop_front();
      }
      else
      {
        std::cout << "-1\n";
      }
    }
    else
    {
      std::cin >> id;
      ++count_dequeue[id];
    }
  }
  return 0;
}