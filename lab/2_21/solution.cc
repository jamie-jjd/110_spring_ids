/*
* author: Jamie
* email : jinjiedeng.jjd@gmail.com
*/
std::vector<long> RespondQueries
(
  long n,
  std::vector<long> A,
  long m,
  std::vector<std::vector<long>> queries
)
{
  std::vector<long> responses;
  std::sort(A.begin(), A.end());
  for (auto const& query : queries)
  {
    auto operation_id {query[0]};
    auto key {query[1]};
    if (operation_id == 1) // search
    {
      if (std::binary_search(A.begin(), A.end(), key)) { responses.push_back(1); }
      else                                             { responses.push_back(0); }
    }
    else if (operation_id == 2) // predecessor
    {
      auto it {std::lower_bound(A.begin(), A.end(), key)};
      if (it != A.begin()) { responses.push_back(*std::prev(it)); }
      else                 { responses.push_back(0); }
    }
    else if (operation_id == 3) // successor
    {
      auto it {std::upper_bound(A.begin(), A.end(), key)};
      if (it != A.end()) { responses.push_back(*it); }
      else               { responses.push_back(0); }
    }
    else { break; }
  }
  return responses;
}
