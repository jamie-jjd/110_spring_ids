/*
* author: jamie
* email: jinjiedeng.jjd@gmail.com
*/
#include <algorithm>
#include <deque>
#include <iostream>

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
  Iterator first_post,
  Iterator last_post,
  Iterator first_in,
  Iterator last_in,
  std::deque<uint64_t>& pre_order
)
{
  if (first_post != last_post)
  {
    pre_order.push_back(*std::prev(last_post));
    auto middle_in {std::find(first_in, last_in, *std::prev(last_post))};
    auto middle_post {std::next(first_post, std::distance(first_in, middle_in))};
    Reconstruct(first_post, middle_post, first_in, middle_in, pre_order);
    Reconstruct(middle_post, std::prev(last_post), std::next(middle_in), last_in, pre_order);
  }
  return;
}

/* direct post- + in- to pre- order */
int main ()
{
  uint64_t n;
  std::cin >> n;
  std::deque<uint64_t> post_order(n);
  for (auto& key : post_order) { std::cin >> key; }
  std::deque<uint64_t> in_order(n);
  for (auto& key : in_order) { std::cin >> key; }
  std::deque<uint64_t> pre_order;
  Reconstruct(post_order.begin(), post_order.end(), in_order.begin(), in_order.end(), pre_order);
  std::cout << pre_order << "\n";
  return 0;
}

/*
* author: jamie
* email: jinjiedeng.jjd@gmail.com
*/
#include <algorithm>
#include <deque>
#include <iostream>

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
    auto middle_in {std::find(first_in, last_in, *first_pre)};
    auto middle_pre {std::next(++first_pre, std::distance(first_in, middle_in))};
    Reconstruct(middle_pre, last_pre, std::next(middle_in), last_in, post_order);
    Reconstruct(first_pre, middle_pre, first_in, middle_in, post_order);
  }
  return;
}

/* reuse pre- + in- to post- order to achieve post- + in- to pre- order */
int main ()
{
  uint64_t n;
  std::cin >> n;
  std::deque<uint64_t> post_order(n);
  for (auto& key : post_order) { std::cin >> key; }
  std::reverse(post_order.begin(), post_order.end());
  std::deque<uint64_t> in_order(n);
  for (auto& key : in_order) { std::cin >> key; }
  std::reverse(in_order.begin(), in_order.end());
  std::deque<uint64_t> pre_order;
  Reconstruct(post_order.begin(), post_order.end(), in_order.begin(), in_order.end(), pre_order);
  std::reverse(pre_order.begin(), pre_order.end());
  std::cout << pre_order << "\n";
  return 0;
}