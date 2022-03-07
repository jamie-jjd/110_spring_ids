/*
* author: jamie
* email: jinjiedeng.jjd@gmail.com
*/
#include <iostream>
#include <queue>
#include <vector>

int main ()
{
  uint64_t n;
  std::cin >> n;
  std::priority_queue<uint64_t, std::vector<uint64_t>, std::less<uint64_t>> max_heap;
  for (uint64_t i {}, a; i != n; ++i) { std::cin >> a; max_heap.push(a); }
  std::priority_queue<uint64_t, std::vector<uint64_t>, std::greater<uint64_t>> min_heap;
  for (uint64_t i {}, b; i != n; ++i) { std::cin >> b; min_heap.push(b); }
  for (uint64_t i {}; i != n; ++i)
  {
    auto max {max_heap.top()}; max_heap.pop();
    auto min {min_heap.top()}; min_heap.pop();
    max_heap.push(max - max / 2);
    min_heap.push(min + max / 2);
  }
  auto max {max_heap.top()}, min {min_heap.top()};
  std::cout << ((min < max) ? (max - min) : (min - max)) << "\n";
  return 0;
}

/*
* author: redleaf
* email: redleaf23477@gapp.nthu.edu.tw
*/

#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    int n; cin >> n;
    priority_queue<LL> A;
    priority_queue<LL, vector<LL>, greater<LL>> B;
    for (int i = 0; i < n; i++) {
        LL x; cin >> x; A.emplace(x);
    }
    for (int i = 0; i < n; i++) {
        LL x; cin >> x; B.emplace(x);
    }
    for (int i = 0; i < n; i++) {
        LL a = A.top(); A.pop();
        LL b = B.top(); B.pop();
        A.emplace(a - a / 2);
        B.emplace(b + a / 2);
    }
    cout << abs(A.top() - B.top()) << "\n";
}
