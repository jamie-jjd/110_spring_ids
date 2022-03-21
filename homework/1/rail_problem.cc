/*
* author: redleaf
* email: redleaf23477@gapp.nthu.edu.tw
*/
#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

bool solve(int n, vector<int> &arr) {
    stack<int> s;
    for (int i = 0, a = 1; i < n; i++) {
        while (s.empty() || s.top() != arr[i]) {
            if (a > n) return false;
            s.emplace(a++);
        }
        s.pop();
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> arr(n);
        for (auto &x : arr) cin >> x;
        if (solve(n, arr)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

/*
* author: jamie
* email: jinjiedeng.jjd@gmail.com
*/
#include <deque>
#include <iostream>
#include <vector>

int main ()
{
  uint64_t T {};
  std::cin >> T;
  while (T--)
  {
    uint64_t n {};
    std::cin >> n;
    std::vector<uint64_t> a(n);
    for (auto& a_i : a) { std::cin >> a_i; }
    std::deque<uint64_t> stack;
    bool is_possible {true};
    uint64_t k {1};
    for (uint64_t i {}; i != n && is_possible; ++i)
    {
      while (k <= n && k != a[i] && (stack.empty() || stack.back() != a[i])) { stack.push_back(k), ++k; }
      if (k == a[i])                 { ++k; }
      else if (stack.back() == a[i]) { stack.pop_back(); }
      else                           { is_possible = false; }
    }
    std::cout << ((is_possible) ? "YES" : "NO") << "\n";
  }
  return 0;
}