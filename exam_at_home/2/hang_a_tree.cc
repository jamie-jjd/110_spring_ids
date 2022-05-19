/*
* author: wang-yang
* email: tnst92002@gmail.com
*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> V;
vector<int> sz;

int N;
int dfs(int v, int pa) {
    int all = 1;
    for (int u: V[v])
        if (u!=pa) {
            int subsz = dfs(u, v);
            sz[v] = max(sz[v], subsz);
            all += subsz;
        }
    sz[v] = max(sz[v], N - all);
    return all;
}

int main() {
    cin >> N;

    V.resize(N);
    sz.resize(N, 0);

    for (int i=0;i<N-1;++i) {
        int s, t;
        cin >> s >> t;
        V[s].emplace_back(t);
        V[t].emplace_back(s);
    }
    dfs(0, 0);

    int ans = *min_element(sz.begin(), sz.end());
    for (int i=0;i<N;++i) {
        if (ans == sz[i]) {
            cout << i << '\n';
        }
    }
}

/*
* author: jamie
* email: jinjiedeng.jjd@gmail.com
*/
#include <algorithm>
#include <iostream>
#include <vector>

void CalculateMaxSubtreeSize
(
  std::vector<std::vector<uint64_t>> const& tree,
  std::vector<uint64_t>& max_subtree_size,
  uint64_t parent_from,
  uint64_t from
)
{
  static std::vector<uint64_t> tree_size(tree.size(), 1);
  for (auto to : tree[from])
  {
    if (to != parent_from)
    {
      CalculateMaxSubtreeSize(tree, max_subtree_size, from, to);
      tree_size[from] += tree_size[to];
      if (max_subtree_size[from] < tree_size[to]) { max_subtree_size[from] = tree_size[to]; }
    }
  }
  if (max_subtree_size[from] < (tree.size() - tree_size[from]))
  {
    max_subtree_size[from] = (tree.size() - tree_size[from]);
  }
  return;
}

int main ()
{
  uint64_t n;
  std::cin >> n;
  std::vector<std::vector<uint64_t>> tree(n);
  for (uint64_t i {1}; i != n; ++i)
  {
    uint64_t from, to;
    std::cin >> from >> to;
    tree[from].push_back(to);
    tree[to].push_back(from);
  }
  std::vector<uint64_t> max_subtree_size(n);
  CalculateMaxSubtreeSize(tree, max_subtree_size, n, 0);
  uint64_t min {*std::min_element(std::begin(max_subtree_size), std::end(max_subtree_size))};
  for (uint64_t i {}; i != n; ++i)
  {
    if (max_subtree_size[i] == min) { std::cout << i << "\n"; }
  }
  return 0;
}