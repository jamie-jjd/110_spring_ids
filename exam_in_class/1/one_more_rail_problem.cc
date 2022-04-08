/*
* author: jamie
* email: jinjiedeng.jjd@gmail.com
*/
#include <iostream>
#include <deque>

int main ()
{
  uint64_t m;
  std::cin >> m;
  while (m--)
  {
    uint64_t n;
    std::cin >> n;
    std::deque<uint64_t> A, B, S;
    for (uint64_t i {}, a; i != n; ++i) { std::cin >> a; A.push_back(a); }
    for (uint64_t i {}, b; i != n; ++i) { std::cin >> b; B.push_back(b); }
    while (!A.empty())
    {
      S.push_back(A.front()); A.pop_front();
      while (!S.empty() && (S.front() == B.front() || S.back() == B.front()))
      {
        if (S.front() == B.front())               { S.pop_front(); B.pop_front(); }
        if (!S.empty() && S.back() == B.front())  { S.pop_back();  B.pop_front(); }
      }
    }
    std::cout << ((B.empty()) ? "YES" : "NO") << "\n";
  }
  return 0;
}