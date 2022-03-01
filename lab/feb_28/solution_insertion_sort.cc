/*
* author: jamie
* email: jinjiedeng.jjd@gmail.com
*/
#include <iostream>
#include <vector>

uint64_t CalculateInversionPairsByInsertionSort (std::vector<uint64_t>& A)
{
  uint64_t count {};
  for (auto it {std::next(A.begin())}; it != A.end(); ++it)
  {
    for (auto rit {it}; rit != A.begin() && *rit < *std::prev(rit); --rit)
    {
      ++count;
      std::swap(*rit, *std::prev(rit));
    }
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
  std::cout << CalculateInversionPairsByInsertionSort(A) << "\n";
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

LL insertion(Iter L, Iter R) {
    LL ans = 0;
    for (Iter it = L + 1; it < R; it++) {
        int buff = *it;
        Iter jt = it - 1;
        while (jt >= L && *jt > buff) {
            *(jt + 1) = *jt;
            ans += 1;
            jt--;
        }
        *(jt + 1) = buff;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    cout << insertion(arr.begin(), arr.end()) << "\n";
}