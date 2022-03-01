/*
* author: jamie
* email: jinjiedeng.jjd@gmail.com
*/
#include <algorithm>
#include <vector>

void InsertionSort (std::vector<uint64_t>& A)
{
  for (auto it {std::next(A.begin())}; it != A.end(); ++it)
  {
    for (auto rit {it}; rit != A.begin() && *rit < *std::prev(rit); --rit)
    {
      std::swap(*rit, *std::prev(rit));
    }
  }
  return;
}

void SelectionSort (std::vector<uint64_t>& A)
{
  for (auto it {A.begin()}; it != A.end(); ++it) { std::swap(*it, *std::min_element(it, A.end())); }
  return;
}

void BubbleSort (std::vector<uint64_t>& A)
{
  for (auto last {std::prev(A.end())}; last != A.begin(); --last)
  {
    auto is_swapped {false};
    for (auto it {A.begin()}; it != last; ++it)
    {
      if (*std::next(it) < *it)
      {
        is_swapped = true;
        std::swap(*it, *std::next(it));
      }
    }
    if (!is_swapped) { break; }
  }
  return;
}

template <typename Iterator>
void MergeSort (Iterator begin, Iterator end, Iterator buffer_begin, Iterator buffer_end)
{
  auto size {std::distance(begin, end)};
  if (size > 1)
  {
    auto middle {std::next(begin, size / 2)};
    auto buffer_middle {std::next(buffer_begin, size / 2)};
    MergeSort(begin, middle, buffer_middle, buffer_end);
    MergeSort(middle, end, buffer_middle, buffer_end);
    std::merge(begin, middle, middle, end, buffer_begin);
  }
  return;
}

/*
* author: redleaf
* email: redleaf23477@gapp.nthu.edu.tw
*/
#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
using Iter = vector<int>::iterator;

void bubble(Iter L, Iter R) {
    size_t len = R - L;
    for (size_t t = 0; t < len; t++) {
        for (Iter it = L + 1; it < R; it++) {
            if (*it < *(it-1)) {
                swap(*it, *(it-1));
            }
        }
    }
    return;
}

void insertion(Iter L, Iter R) {
    for (Iter it = L + 1; it < R; it++) {
        int buff = *it;
        Iter jt = it - 1;
        while (jt >= L && *jt > buff) {
            *(jt + 1) = *jt;
            jt--;
        }
        *(jt + 1) = buff;
    }
    return;
}

void dc(Iter L, Iter R) {
    if (R - L <= 1) {
        return 0;
    }
    auto M = L + (R - L) / 2;
    dc(L, M); dc(M, R);
    auto it = L, jt = M;
    static vector<int> buff;
    buff.clear();
    while (it < M && jt < R) {
        if (*it < *jt) buff.emplace_back(*it), it++;
        else {
            buff.emplace_back(*jt), jt++;
        }
    }
    for (; it < M; it++) buff.emplace_back(*it);
    for (; jt < R; jt++) buff.emplace_back(*jt);
    copy(buff.begin(), buff.end(), L);
    return;
}