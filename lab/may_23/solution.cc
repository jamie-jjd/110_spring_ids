/*
* author: jamie
* email: jinjiedeng.jjd@gmail.com
*/
#include <iostream>
#include <string>
#include <unordered_map>

int main ()
{
  std::string N;
  std::cin >> N;
  uint64_t m, k;
  std::cin >> m >> k;
  std::unordered_map<std::string, uint64_t> table;
  for (uint64_t i {}; i <= N.size() - k; ++i) { ++table[N.substr(i, k)]; }
  while (m--)
  {
    std::string key;
    std::cin >> key;
    if (table.find(key) != table.end()) { std::cout << table[key] << "\n"; }
    else                                { std::cout << "0\n"; }
  }
  return 0;
}

/*
* author: jamie
* email: jinjiedeng.jjd@gmail.com
*/
#include <iostream>
#include <map>
int main ()
{
  std::string N;
  std::cin >> N;
  uint64_t m, k;
  std::cin >> m >> k;
  std::map<uint64_t, uint64_t> table;
  for (uint64_t i {}, key {}; i != N.size(); ++i)
  {
    // this is equivalent to key = ((key * 2) + (N[i] - '0')) % 2^k
    key = ((key << 1) | (N[i] - '0')) & ((1ULL << k) - 1);
    if (i >= k - 1) { ++table[key]; }
  }
  while (m--)
  {
    std::string B;
    uint64_t key {};
    std::cin >> B;
    for (auto b : B) { key = (key << 1) | (b - '0'); }
    if (table.find(key) != table.end()) { std::cout << table[key] << "\n"; }
    else                                { std::cout << "0\n"; }
  }
  return 0;
}