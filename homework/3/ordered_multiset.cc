/*
* author: redleaf
* email: redleaf23477@gapp.nthu.edu.tw
*/
#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n; cin >> n;
    multiset<int> s;
    for (int i = 0; i < n; i++) {
        int x; cin >> x; s.insert(x);
    }
    int q; cin >> q;
    while (q--) {
        int op, x; cin >> op >> x;
        if (op == 1) {
            s.insert(x);
            cout << s.size() << "\n";
        } else if (op == 2) {
            auto it = s.find(x);
            if (it != s.end()) s.erase(it);
            cout << s.size() << "\n";
        } else if (op == 3) {
            cout << (s.count(x) != 0? "Yes\n" : "No\n");
        } else if (op == 4) {
            auto it = s.lower_bound(x);
            cout << (it == s.end()? -1 : *it) << "\n";
        } else {
            auto it = s.upper_bound(x);
            cout << (it == s.end()? -1 : *it) << "\n";
        }
    }
}

/*
* author: jamie
* email: jinjiedeng.jjd@gmail.com
*/
#include <iostream>
#include <map>

int main ()
{
  int64_t n;
  std::cin >> n;
  std::map<int64_t, int64_t> map;
  for (int64_t i {}, a; i != n; ++i) { std::cin >> a; ++map[a]; }
  int64_t q;
  std::cin >> q;
  while (q--)
  {
    int64_t op, x;
    std::cin >> op >> x;
    if (op == 1) // insert
    {
      ++map[x];
      std::cout << ++n << "\n";
    }
    else if (op == 2) // delete
    {
      if (map.find(x) != map.end())
      {
        if (--map[x] == 0) { map.erase(x); }
        --n;
      }
      std::cout << n << "\n";
    }
    else if (op == 3) // is_member
    {
      std::cout << (map.count(x) ? "Yes" : "No") << "\n";
    }
    else if (op == 4) // lower_bound
    {
      auto it {map.lower_bound(x)};
      std::cout << ((it == map.end()) ? -1 : std::get<0>(*it)) << "\n";
    }
    else if (op == 5) // upper_bound
    {
      auto it {map.upper_bound(x)};
      std::cout << ((it == map.end()) ? -1 : std::get<0>(*it)) << "\n";
    }
  }
  return 0;
}