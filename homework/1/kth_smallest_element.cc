/*
* author: redleaf
* email: redleaf23477@gapp.nthu.edu.tw
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> KthElements(int k, int n, vector<int> a) {
    priority_queue<int> pq;
    vector<int> ans;

    for(int i=0; i < n; ++i) {
        if (i < k) {
            pq.push(a[i]);
            if ((int)pq.size() == k) {
                ans.emplace_back(pq.top());
            }
        } else {
            if (a[i] < pq.top()) {
                pq.push(a[i]);
                pq.pop();
            }
            ans.emplace_back(pq.top());
        }
    }
    return ans;
}

int main() {
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;

    vector<int> res = KthElements(k, n, arr);

    for (size_t i = 0; i < res.size(); i++) {
        cout << res[i] << " \n"[i+1 == res.size()];
    }
    return 0;
}

/*
* author: jamie
* email: jinjiedeng.jjd@gmail.com
*/
#include <iostream>
#include <queue>

std::ostream& operator<< (std::ostream& out, std::vector<uint64_t> const& v)
{
  if (!v.empty())
  {
    auto it {v.begin()};
    out << *it++;
    while (it != v.end()) { out << " " << *it++; }
  }
  out << "\n";
  return out;
}

int main ()
{
  uint64_t n {}, k {};
  std::cin >> n >> k;
  std::priority_queue<uint64_t, std::vector<uint64_t>, std::less<uint64_t>> max_heap;
  std::vector<uint64_t> kth_smallest_elements;
  for (uint64_t i {}, a {}; i != k; ++i)
  {
    std::cin >> a;
    max_heap.push(a);
  }
  kth_smallest_elements.push_back(max_heap.top());
  for (uint64_t i {k}, a {}; i != n; ++i)
  {
    std::cin >> a;
    if (a < max_heap.top())
    {
      max_heap.pop();
      max_heap.push(a);
    }
    kth_smallest_elements.push_back(max_heap.top());
  }
  std::cout << kth_smallest_elements;
  return 0;
}