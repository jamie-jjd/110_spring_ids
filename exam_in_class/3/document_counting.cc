/*
* author: jamie
* email: jinjiedeng.jjd@gmail.com
*/
#include <iostream>
#include <map>
#include <set>

int main ()
{
  uint64_t n; std::cin >> n;
  std::map<std::string, std::set<uint64_t>> inverted_index;
  for (uint64_t i {}; i != n; ++i)
  {
    uint64_t m_i; std::cin >> m_i;
    while (m_i--)
    {
      std::string word; std::cin >> word;
      inverted_index[word].insert(i);
    }
  }
  uint64_t q; std::cin >> q;
  while (q--)
  {
    std::string word; std::cin >> word;
    std::cout << inverted_index[word].size() << "\n";
  }
  return 0;
}