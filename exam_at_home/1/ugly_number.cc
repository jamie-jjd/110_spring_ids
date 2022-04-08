/*
* author: wang-yang
* email: tnst92002@gmail.com
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    vector<ll> ug {0};
    pq.emplace(1);
    while (ug.size() <= 10000) {
        ll nxt = pq.top();
        pq.pop();
        if (nxt == ug.back()) continue;
        ug.emplace_back(nxt);
        pq.emplace(nxt * 2);
        pq.emplace(nxt * 3);
        pq.emplace(nxt * 5);
    }
    int N, k;
    cin >> N;
    while (N--) {
        cin >> k;
        cout << ug[k] << '\n';
    }
}

/*
* author: jamie
* email: jinjiedeng.jjd@gmail.com
*/
#include <algorithm>
#include <iostream>
#include <vector>

int main ()
{
  uint64_t Q;
  std::cin >> Q;
  std::vector<uint64_t> Ks(Q);
  for (auto& k : Ks) { std::cin >> k; }
  auto max_k {*max_element(Ks.begin(), Ks.end())};
  std::vector<uint64_t> ugly_number(max_k + 1);
  auto it {std::next(ugly_number.begin())};
  auto it_2 {it}, it_3 {it}, it_5 {it};
  *it++ = 1;
  while (it != ugly_number.end())
  {
    auto x_2 {*it_2 * 2}, x_3 {*it_3 * 3}, x_5 {*it_5 * 5};
    auto min {std::min(x_2, std::min(x_3, x_5))};
    *it++ = min;
    if (min == x_2) { ++it_2; }
    if (min == x_3) { ++it_3; }
    if (min == x_5) { ++it_5; }
  }
  for (auto k : Ks) { std::cout << ugly_number[k] << "\n"; }
  return 0;
}