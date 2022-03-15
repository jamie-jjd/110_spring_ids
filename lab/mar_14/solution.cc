/*
* author: jamie
* email: jinjiedeng.jjd@gmail.com
*/
#include <deque>
#include <iostream>
#include <vector>

int main ()
{
  uint64_t n, m;
  std::cin >> n >> m;
  std::vector<std::deque<uint64_t>> barrels(n + 1);
  while (m--)
  {
    uint64_t op, i, j, k;
    std::cin >> op;
    if (op) // retrieve
    {
      std::cin >> j >> k;
      if (j) // the-1-end
      {
        std::cout << barrels[k].back() << "\n";
        barrels[k].pop_back();
      }
      else // the-0-end
      {
        std::cout << barrels[k].front() << "\n";
        barrels[k].pop_front();
      }
    }
    else // store
    {
      std::cin >> i >> j >> k;
      if (j) { barrels[k].push_back(i); } // the-1-end
      else   { barrels[k].push_front(i); } // the-0-end
    }
  }
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
    int m; cin >> m;
    vector<deque<int>> deq(n);
    while (m--) {
        int op; cin >> op;
        if (op == 0) {
            int i, j, k; cin >> i >> j >> k;
            if (j == 0) deq[k-1].emplace_front(i);
            else deq[k-1].emplace_back(i);
        } else {
            int j, k; cin >> j >> k;
            if (j == 0) {
                cout << deq[k-1].front() << "\n";
                deq[k-1].pop_front();
            } else {
                cout << deq[k-1].back() << "\n";
                deq[k-1].pop_back();
            }
        }
    }
}