/*
* author: wang-yang
* email: tnst92002@gmail.com
*/
#include <bits/stdc++.h>
using namespace std;

int isp[10000] = {0};
bool isPrime(int v) {
    if (isp[v] == 0) {
        bool check = true;
        for (int i=2;i*i<=v;++i)
            if (v%i == 0)
                check = false;
        
        isp[v] = check ? 1 : -1;
    }

    return isp[v] == 1;
}

int bfs(int a, int b) {
    vector<int> dist(10000, -1);
    queue<int> qu;

    if (a==b) return 0;

    qu.emplace(a);
    dist[a] = 0;

    while (!qu.empty()) {
        int v = qu.front();
        qu.pop();
       
        for (int i=0;i<4;++i) {
            string tmp = to_string(v);
            for (int j=0;j<=9;++j) {
                if (i==0 && j==0) continue;
                if (tmp[i] - '0' == j) continue;

                tmp[i] = j + '0';
                int u = stoi(tmp);
                if (!isPrime(u)) continue;
                if (dist[u] != -1) continue;

                dist[u] = dist[v] + 1;
                if (u == b)
                     return dist[b];

                qu.emplace(u);
            }
        }
    }

    return dist[b];
}

int main() {
    int T;
    int a, b;

    cin >> T;
    while (T--) {
        cin >> a >> b;
        int ans = bfs(a, b);

        if (ans == -1) cout << "Impossible\n";
        else cout << ans << '\n';
    }
}

/*
* author: jamie
* email: jinjiedeng.jjd@gmail.com
*/
#include <deque>
#include <iostream>
#include <vector>

void CreatePrimeTable (std::vector<bool>& is_prime)
{
  is_prime.resize(10'000, true);
  is_prime[0] = is_prime[1] = false;
  for (uint64_t i {2}; i != 10'000; ++i)
  {
    if (is_prime[i])
    {
      for (uint64_t multiple {i * i}; multiple < 10'000; multiple += i)
      {
        is_prime[multiple] = false;
      }
    }
  }
  return;
}

uint64_t MinStep (std::vector<bool> const& is_prime, uint64_t p, uint64_t q)
{
  std::deque<uint64_t> queue;
  std::vector<uint64_t> distance(is_prime.size(), is_prime.size());
  queue.emplace_back(p); distance[p] = 0;
  while (!queue.empty())
  {
    auto u {queue.front()}; queue.pop_front();
    if (u == q) { return distance[u]; }
    for (uint64_t base {1'000}; base; base /= 10)
    {
      uint64_t prefix_base {base * 10};
      uint64_t prefix {(u / prefix_base) * prefix_base}, suffix {u % base};
      uint64_t digit {(u % prefix_base) / base};
      for (uint64_t d {}; d != 10; ++d)
      {
        if (d != digit && !(base == 1'000 && d == 0))
        {
          auto v {prefix + d * base + suffix};
          if (is_prime[v] && distance[u] + 1 < distance[v])
          {
            distance[v] = distance[u] + 1;
            queue.emplace_back(v);
          }
        }
      }
    }
  }
  return is_prime.size();
}

int main ()
{
  uint64_t T; std::cin >> T;
  while (T--)
  {
    uint64_t p, q; std::cin >> p >> q;
    std::vector<bool> is_prime;
    CreatePrimeTable(is_prime);
    auto min_step {MinStep(is_prime, p, q)};
    if (min_step == is_prime.size()) { std::cout << "Impossible\n"; }
    else                             { std::cout << min_step << "\n"; }
  }
  return 0;
}