/*
* author: jamie
* email: jinjiedeng.jjd@gmail.com
*/
#include <iostream>
#include <vector>

std::ostream& operator<< (std::ostream& out, std::vector<uint64_t>& v)
{
  if (!v.empty())
  {
    auto it {v.begin()};
    out << *it++;
    while (it != v.end())
    {
      out << " " << *it++;
    }
  }
  out << "\n";
  return out;
}

std::ostream& operator<<
(
  std::ostream& out,
  std::pair<std::vector<uint64_t>::iterator, std::vector<uint64_t>::iterator> range
)
{
  auto [begin, end] {range};
  if (std::distance(begin, end) > 0)
  {
    auto it {begin};
    out << *it++;
    while (it != end)
    {
      out << " " << *it++;
    }
  }
  out << "\n";
  return out;
}

// usage 1 (container)
{
  std::vector<uint64_t> A;
  std::cout << A;
}

// usage 2 (iterator)
{
  std::vector<uint64_t> A;
  std::cout << std::make_pair(A.begin(), A.end());
}