/*
* author: jamie
* email: jinjiedeng.jjd@gmail.com
*/
#include <iostream>
#include <set>

// solution using multiset
int main ()
{
  uint64_t N, C;
  std::cin >> N >> C;
  std::multiset<uint64_t> calories;
  for (uint64_t i {}, c; i != N; ++i) { std::cin >> c; ++calories.insert(c); }
  uint64_t count {};
  while (calories.size() > 1)
  {
    auto it_min {calories.begin()};
    auto it_max {std::prev(calories.end())};
    if (*it_min + *it_max <= C) { ++count; calories.erase(it_min); }
    else if (*it_max <= C)      { ++count; }
    calories.erase(it_max);
  }
  if (!calories.empty() && *calories.begin() <= C) { ++count; }
  std::cout << count;
}

#include <algorithm>
#include <iostream>
#include <vector>

// solution using sorted vector and two pointers
int main ()
{
  uint64_t N, C;
  std::cin >> N >> C;
  std::vector<uint64_t> calories(N);
  for (auto& c : calories) { std::cin >> c; }
  std::sort(calories.begin(), calories.end());
  uint64_t count {};
  auto it_min {calories.begin()};
  auto it_max {std::prev(calories.end())};
  while (it_min < it_max)
  {
    if (*it_min + *it_max <= C) { ++count; ++it_min; }
    else if (*it_max <= C)      { ++count; }
    --it_max;
  }
  if (it_min == it_max && *it_max <= C) { ++count; }
  std::cout << count;
}