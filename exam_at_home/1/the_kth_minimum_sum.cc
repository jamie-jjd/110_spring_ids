/*
* author: wang-yang
* email: tnst92002@gmail.com
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> v(M), w(M);
    for (int i=0;i<M;++i)
        cin >> v[i];
    N--;
    while (N--) {
        for (int i=0;i<M;++i)
            cin >> w[i];
        using tii = tuple<int,int>;
        priority_queue<tii, vector<tii>, greater<tii>> pq;
        for (int i=0;i<M;++i)
            pq.emplace(v[i] + w[0], 0);
        for (int i=0;i<M;++i) {
            auto [val, pos] = pq.top();
            pq.pop();
            v[i] = val;
            if (pos + 1 < M)
                pq.emplace(val - w[pos] + w[pos+1], pos+1);
        }
    }
    for (int i=0;i <M;++i)
    {
        if (i) cout << ' ';
        cout << v[i] ;
    }
    cout << '\n';
}

/*
* author: jamie
* email: jinjiedeng.jjd@gmail.com
*/
#include <iostream>
#include <queue>
#include <vector>

std::ostream& operator<< (std::ostream& out, std::vector<uint64_t> const& v)
{
  if (!v.empty())
  {
    auto it {v.begin()};
    std::cout << *it++;
    while (it != v.end()) { out << " " << *it++; }
  }
  return out;
}

int main ()
{
  uint64_t n, m;
  std::cin >> n >> m;
  std::vector<std::vector<uint64_t>> arrays(n, std::vector<uint64_t>(m));
  for (auto& array : arrays)
  {
    for (uint64_t i {1}; i <= m; ++i) { std::cin >> array[i]; }
    for (uint64_t i {m}; i > 0; --i) { array[i] -= array[i - 1]; }
  }
  using ElementType = std::pair<uint64_t, std::vector<uint64_t>>;
  std::priority_queue<ElementType, std::vector<ElementType>, std::greater<ElementType>> min_heap;
  uint64_t sum {}, count {m};
  std::vector<uint64_t> prev_indexes(n), sums;
  for (uint64_t i {}; i != n; ++i) { sum += arrays[i][1]; }
  min_heap.push(std::make_pair(sum, std::vector<uint64_t>(n, 1)));
  while (count)
  {
    auto sum {std::get<0>(min_heap.top())};
    auto indexes {std::get<1>(min_heap.top())};
    min_heap.pop();
    if (prev_indexes != indexes)
    {
      sums.push_back(sum);
      for (uint64_t j {}; j != n; ++j)
      {
        ++indexes[j];
        min_heap.push(std::make_pair(sum + arrays[j][indexes[j]], indexes));
        --indexes[j];
      }
      prev_indexes = indexes;
      --count;
    }
  }
  std::cout << sums << "\n";
  return 0;
}