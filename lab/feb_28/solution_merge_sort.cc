/*
* author: jamie
* email: jinjiedeng.jjd@gmail.com
*/
#include <algorithm>
#include <iostream>
#include <vector>

template <typename Iterator>
uint64_t CustomizedMerge (Iterator begin, Iterator middle, Iterator end, Iterator buffer_begin, Iterator buffer_end)
{
  uint64_t count {};
  auto left_it {begin}, right_it {middle}, buffer_it {buffer_begin};
  while (left_it != middle && right_it != end)
  {
    if (*right_it < *left_it)
    {
      count += std::distance(left_it, middle);
      *buffer_it++ = *right_it++;
    }
    else { *buffer_it++ = *left_it++; }
  }
  while (left_it != middle) { *buffer_it++ = *left_it++; }
  while (right_it != end)   { *buffer_it++ = *right_it++; }
  std::copy(buffer_begin, buffer_end, begin);
  return count;
}

template <typename Iterator>
uint64_t CalculateInversionPairsByMergeSort (Iterator begin, Iterator end, Iterator buffer_begin, Iterator buffer_end)
{
  uint64_t count {};
  auto size {std::distance(begin, end)};
  if (size > 1)
  {
    auto middle {std::next(begin, size / 2)};
    auto buffer_middle {std::next(buffer_begin, size / 2)};
    count += CalculateInversionPairsByMergeSort(begin, middle, buffer_begin, buffer_middle);
    count += CalculateInversionPairsByMergeSort(middle, end, buffer_middle, buffer_end);
    count += CustomizedMerge(begin, middle, end, buffer_begin, buffer_end);
  }
  return count;
}

int main ()
{
  uint64_t n {};
  std::cin >> n;
  std::vector<uint64_t> A(n);
  for (auto& A_i : A) { std::cin >> A_i; }
  /* for large n */
  std::vector<uint64_t> B(n);
  std::cout << CalculateInversionPairsByMergeSort(A.begin(), A.end(), B.begin(), B.end()) << "\n";
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

LL dc(Iter L, Iter R) {
    if (R - L <= 1) {
        return 0;
    }
    auto M = L + (R - L) / 2;
    LL ans = dc(L, M) + dc(M, R);
    auto it = L, jt = M;
    static vector<int> buff;
    buff.clear();
    while (it < M && jt < R) {
        if (*it < *jt) buff.emplace_back(*it), it++;
        else {
            ans += M - it;
            buff.emplace_back(*jt), jt++;
        }
    }
    for (; it < M; it++) buff.emplace_back(*it);
    for (; jt < R; jt++) buff.emplace_back(*jt);
    copy(buff.begin(), buff.end(), L);
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    cout << dc(arr.begin(), arr.end()) << "\n";
}