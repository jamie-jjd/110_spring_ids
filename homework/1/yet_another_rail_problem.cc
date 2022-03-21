/*
* author: redleaf
* email: redleaf23477@gapp.nthu.edu.tw
*/
#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

bool solve(int n, vector<int> &arr) {
    queue<int> q;
    int i = 1;
    for (auto x : arr) {
        if (!q.empty() && x == q.front()) {
            q.pop();
        } else {
            for (; i != x; i++) {
                if (i > n) return false;
                q.emplace(i);
            }
            i++;
        }
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
        cout << (solve(n, arr)? "YES\n" : "NO\n");
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
    std::deque<uint64_t> queue;
    bool is_possible {true};
    uint64_t k {1};
    for (uint64_t i {}; i != n && is_possible; ++i)
    {

      while (k <= n && k != a[i] && (queue.empty() || queue.front() != a[i])) { queue.push_back(k), ++k; }
      if (k == a[i])                  { ++k; }
      else if (queue.front() == a[i]) { queue.pop_front(); }
      else                            { is_possible = false; }
    }
    std::cout << ((is_possible) ? "YES" : "NO") << "\n";
  }
  return 0;
}