/*
* author: Jamie
* email : jinjiedeng.jjd@gmail.com
*/
#include <algorithm>
#include <iostream>
#include <vector>

void RespondQueries
(
  std::vector<uint64_t>& A,
  std::vector<std::pair<uint64_t, uint64_t>>& queries
)
{
  std::sort(A.begin(), A.end());
  for (auto const& query : queries)
  {
    auto& operation_id {std::get<0>(query)};
    auto& key {std::get<1>(query)};
    if (operation_id == 1) // search
    {
      if (std::binary_search(A.begin(), A.end(), key)) { std::cout << "1\n"; }
      else                                             { std::cout << "0\n"; }
    }
    else if (operation_id == 2) // predecessor
    {
      auto it {std::lower_bound(A.begin(), A.end(), key)};
      if (it != A.begin()) { std::cout << *std::prev(it) << "\n"; }
      else                 { std::cout << "0\n"; }
    }
    else if (operation_id == 3) // successor
    {
      auto it {std::upper_bound(A.begin(), A.end(), key)};
      if (it != A.end()) { std::cout << *it << "\n"; }
      else               { std::cout << "0\n"; }
    }
  }
  return;
}

int main ()
{
  uint64_t n {};
  std::cin >> n;
  std::vector<uint64_t> A(n);
  for (auto& A_i : A) { std::cin >> A_i; }
  uint64_t m {};
  std::cin >> m;
  std::vector<std::pair<uint64_t, uint64_t>> queries(m);
  for (auto& query : queries) { std::cin >> std::get<0>(query) >> std::get<1>(query); }
  RespondQueries(A, queries);
  return 0;
}