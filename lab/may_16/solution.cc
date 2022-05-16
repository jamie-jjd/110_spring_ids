/*
* author: jamie
* email: jinjiedeng.jjd@gmail.com
*/
#include <iostream>
#include <map>
#include <vector>

int main ()
{
  uint64_t n, k;
  std::cin >> n >> k;
  std::vector<uint64_t> S(n);
  std::map<uint64_t, uint64_t> map;
  for (auto& s : S) { std::cin >> s; }
  for (uint64_t i {}; i != k; ++i) { ++map[S[i]]; }
  std::cout << map.size();
  for (uint64_t i {k}; i != n; ++i)
  {
    if (--map[S[i - k]] == 0) { map.erase(S[i - k]); }
    ++map[S[i]];
    std::cout << " " << map.size();
  }
  return 0;
}