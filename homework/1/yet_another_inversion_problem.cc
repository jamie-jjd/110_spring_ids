/*
* author: redleaf
* email: redleaf23477@gapp.nthu.edu.tw
*/
#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

LL solve1(vector<int> &A, vector<int> &B, vector<int> &C) {
    auto a = A.begin(), b = B.begin(), c = C.begin();
    LL ans = 0;
    while (a != A.end() && b != B.end() && c != C.end()) {
        if (*b < *a && *b < *c) {
            ans += (A.end() - a) * (C.end() - c);
            b++;
        } else if (*a < *c) {
            a++;
        } else {
            c++;
        }
    }
    return ans;
}

LL solve2(vector<int> &A, vector<int> &B, vector<int> &C) {
    LL ans = 0;
    for (auto b : B) {
        LL part_a = A.end() - upper_bound(A.begin(), A.end(), b);
        LL part_c = C.end() - upper_bound(C.begin(), C.end(), b);
        ans += part_a * part_c;
    }
    return ans;
}

int main() {
    int na, nb, nc; cin >> na >> nb >> nc;
    vector<int> A(na), B(nb), C(nc);
    for (auto &x : A) cin >> x;
    for (auto &x : B) cin >> x;
    for (auto &x : C) cin >> x;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());
    cout << solve1(A, B, C) << "\n";
//    cout << solve2(A, B, C) << "\n";
}

/*
* author: jamie
* email: jinjiedeng.jjd@gmail.com
*/
#include <algorithm>
#include <iostream>
#include <vector>

uint64_t CalculateTuples
(
  std::vector<uint64_t> const& A,
  std::vector<uint64_t> const& B,
  std::vector<uint64_t> const& C
)
{
  uint64_t count {};
  auto A_it {A.begin()}, B_it {B.begin()}, C_it {C.begin()};
  while (A_it != A.end() && B_it != B.end() && C_it != C.end())
  {
    if (*A_it > *B_it && *B_it < *C_it)
    {
      count += std::distance(A_it, A.end()) * std::distance(C_it, C.end());
      ++B_it;
    }
    else if (*A_it < *C_it) { ++A_it; }
    else                    { ++C_it; }
  }
  return count;
}

int main ()
{
  uint64_t n_a {}, n_b {}, n_c {};
  std::cin >> n_a >> n_b >> n_c;
  std::vector<uint64_t> A(n_a), B(n_b), C(n_c);
  for (auto& a : A) { std::cin >> a; }
  for (auto& b : B) { std::cin >> b; }
  for (auto& c : C) { std::cin >> c; }
  std::sort(A.begin(), A.end());
  std::sort(B.begin(), B.end());
  std::sort(C.begin(), C.end());
  std::cout << CalculateTuples(A, B, C) << "\n";
  return 0;
}