/*
* author: jamie
* email: jinjiedeng.jjd@gmail.com
*/
#include <iostream>
#include <vector>

uint64_t CalculateInversionPairsByBubbleSort (std::vector<uint64_t>& A)
{
  uint64_t count {};
  for (auto last {std::prev(A.end())}; last != A.begin(); --last)
  {
    auto is_swapped {false};
    for (auto it {A.begin()}; it != last; ++it)
    {
      if (*std::next(it) < *it)
      {
        is_swapped = true;
        ++count;
        std::swap(*it, *std::next(it));
      }
    }
    if (!is_swapped) { break; }
  }
  return count;
}

int main ()
{
  uint64_t n {};
  std::cin >> n;
  std::vector<uint64_t> A(n);
  for (auto& A_i : A) { std::cin >> A_i; }
  /* only for small n */
  std::cout << CalculateInversionPairsByBubbleSort(A) << "\n";
  return 0;
}

/*
* author: redleaf
* email: redleaf23477@gapp.nthu.edu.tw
*/
#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
using Iter = vector<int>::iterator;

LL bubble(Iter L, Iter R) {
    size_t len = R - L;
    LL ans = 0;
    for (size_t t = 0; t < len; t++) {
        for (Iter it = L + 1; it < R; it++) {
            if (*it < *(it-1)) {
                swap(*it, *(it-1));
                ans += 1;
            }
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    cout << bubble(arr.begin(), arr.end()) << "\n";
}