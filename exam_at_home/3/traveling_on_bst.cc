/*
* author: jamie
* email: jinjiedeng.jjd@gmail.com
*/
#include <iostream>
#include <set>

int main ()
{
  uint64_t n, key; std::cin >> n;
  std::set<uint64_t> set;
  while (n--) { std::cin >> key; set.insert(key); }
  for (auto key : set) { std::cout << key << "\n"; }
  return 0;
}