/*
* author: redleaf
* email: redleaf23477@gapp.nthu.edu.tw
*/
#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

struct Node {
    int data;
    unique_ptr<Node> lchild, rchild;
    Node(int d, unique_ptr<Node> l, unique_ptr<Node> r) : data(d), lchild(move(l)), rchild(move(r)) {}
};

unique_ptr<Node> build_tree(int l, int r, const vector<int> &arr) {
    if (r < l) return nullptr;
    int mid;
    for (mid = l+1; mid <= r; mid++) {
        if (arr[mid] > arr[l]) break;
    }
    return make_unique<Node>(arr[l],
            build_tree(l+1, mid-1, arr),
            build_tree(mid, r, arr));
}

void dfs1(const unique_ptr<Node> &tree) {
    // in-order
    if (tree->lchild) dfs1(tree->lchild);
    cout << tree->data << " ";
    if (tree->rchild) dfs1(tree->rchild);
}

void dfs2(const unique_ptr<Node> &tree) {
    // post-order
    if (tree->lchild) dfs2(tree->lchild);
    if (tree->rchild) dfs2(tree->rchild);
    cout << tree->data << " ";
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    unique_ptr<Node> tree = build_tree(0, n-1, arr);

    dfs1(tree);
    cout << "\n";
    dfs2(tree);
    cout << "\n";
}

/*
* author: jamie
* email: jinjiedeng.jjd@gmail.com
*/
#include <algorithm>
#include <iostream>
#include <deque>

std::ostream& operator<< (std::ostream& out, std::deque<uint64_t> const& v)
{
  if (!v.empty())
  {
    auto it {v.begin()};
    out << *it++;
    while (it != v.end()) { out << " " << *it++; }
  }
  return out;
}

template <typename Iterator>
void Reconstruct
(
  Iterator first_pre,
  Iterator last_pre,
  Iterator first_in,
  Iterator last_in,
  std::deque<uint64_t>& post_order
)
{
  if (first_pre != last_pre)
  {
    post_order.push_front(*first_pre);
    auto middle_in {std::lower_bound(first_in, last_in, *first_pre)};
    auto middle_pre {std::next(first_pre, 1 + std::distance(first_in, middle_in))};
    Reconstruct(middle_pre, last_pre, std::next(middle_in), last_in, post_order);
    Reconstruct(std::next(first_pre), middle_pre, first_in, middle_in, post_order);
  }
  return;
}

int main ()
{
  uint64_t N;
  std::cin >> N;
  std::deque<uint64_t> pre_order(N);
  for (auto& key : pre_order) { std::cin >> key; }
  std::deque<uint64_t> in_order(pre_order);
  std::sort(in_order.begin(), in_order.end());
  std::deque<uint64_t> post_order;
  Reconstruct(pre_order.begin(), pre_order.end(), in_order.begin(), in_order.end(), post_order);
  std::cout << in_order << "\n";
  std::cout << post_order << "\n";
  return 0;
}