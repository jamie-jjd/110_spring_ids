/*
* author: jamie
* email: jinjiedeng.jjd@gmail.com
*/
#include <deque>
#include <iostream>
#include <vector>

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

/* iterative version (with stack) */
void PreOrder
(
  std::vector<std::vector<uint64_t>> const& binary_tree,
  uint64_t middle,
  std::deque<uint64_t>& order
)
{
  std::vector<uint64_t> stack;
  stack.push_back(middle);
  while (!stack.empty())
  {
    middle = stack.back(); stack.pop_back();
    order.push_back(middle);
    if (binary_tree[middle][1]) { stack.push_back(binary_tree[middle][1]); }
    if (binary_tree[middle][0]) { stack.push_back(binary_tree[middle][0]); }
  }
  return;
}

/* recursive version */
// void PreOrder
// (
//   std::vector<std::vector<uint64_t>> const& binary_tree,
//   uint64_t middle,
//   std::deque<uint64_t>& order
// )
// {
//   order.push_back(middle);
//   if (binary_tree[middle][0]) { PreOrder(binary_tree, binary_tree[middle][0], order); }
//   if (binary_tree[middle][1]) { PreOrder(binary_tree, binary_tree[middle][1], order); }
//   return;
// }

/* iterative version (with stack) */
void InOrder
(
  std::vector<std::vector<uint64_t>> const& binary_tree,
  uint64_t middle,
  std::deque<uint64_t>& order
)
{
  std::vector<uint64_t> stack;
  std::vector<bool> is_forward(binary_tree.size(), true);
  stack.push_back(middle);
  while (!stack.empty())
  {
    middle = stack.back(); stack.pop_back();
    if (is_forward[middle])
    {
      if (binary_tree[middle][1]) { stack.push_back(binary_tree[middle][1]); }
      stack.push_back(middle); is_forward[middle] = false;
      if (binary_tree[middle][0]) { stack.push_back(binary_tree[middle][0]); }
    }
    else { order.push_back(middle); }
  }
  return;
}

/* iterative version (without stack): morris traversal */
// void InOrder
// (
//   std::vector<std::vector<uint64_t>>& binary_tree,
//   uint64_t middle,
//   std::deque<uint64_t>& order
// )
// {
//   uint64_t prev {};
//   while (middle)
//   {
//     if (binary_tree[middle][0]) // left child exists
//     {
//       { // find predecessor of middle
//         prev = binary_tree[middle][0];
//         while (binary_tree[prev][1] && binary_tree[prev][1] != middle) { prev = binary_tree[prev][1]; }
//       }
//       if (binary_tree[prev][1] == 0) // right child of predecessor of middle is empty
//       {
//         binary_tree[prev][1] = middle; // temporarily set right child of predecessor of middle as middle
//         middle = binary_tree[middle][0]; // move to left child
//       }
//       else // left subtree of middle are traversed
//       {
//         middle = binary_tree[prev][1]; // retrieve middle
//         binary_tree[prev][1] = 0; // reset right child of predecessor of middle as empty
//         order.push_back(middle); // output middle
//         middle = binary_tree[middle][1]; // move to right child
//       }
//     }
//     else // no left child
//     {
//       order.push_back(middle); // output middle
//       middle = binary_tree[middle][1]; // move to right
//     }
//   }
// }

/* recursive version */
// void InOrder
// (
//   std::vector<std::vector<uint64_t>> const& binary_tree,
//   uint64_t middle,
//   std::deque<uint64_t>& order
// )
// {
//   if (binary_tree[middle][0]) { InOrder(binary_tree, binary_tree[middle][0], order); }
//   order.push_back(middle);
//   if (binary_tree[middle][1]) { InOrder(binary_tree, binary_tree[middle][1], order); }
//   return;
// }

/* iterative version (with stack) */
void PostOrder
(
  std::vector<std::vector<uint64_t>> const& binary_tree,
  uint64_t middle,
  std::deque<uint64_t>& order
)
{
  std::vector<uint64_t> stack;
  stack.push_back(middle);
  while (!stack.empty())
  {
    auto middle {stack.back()}; stack.pop_back();
    order.push_front(middle);
    if (binary_tree[middle][0]) { stack.push_back(binary_tree[middle][0]); }
    if (binary_tree[middle][1]) { stack.push_back(binary_tree[middle][1]); }
  }
  return;
}

/* recursive version */
// void PostOrder
// (
//   std::vector<std::vector<uint64_t>> const& binary_tree,
//   uint64_t middle,
//   std::deque<uint64_t>& order
// )
// {
//   if (binary_tree[middle][0]) { PostOrder(binary_tree, binary_tree[middle][0], order); }
//   if (binary_tree[middle][1]) { PostOrder(binary_tree, binary_tree[middle][1], order); }
//   order.push_back(middle);
//   return;
// }

void LevelOrder
(
  std::vector<std::vector<uint64_t>> const& binary_tree,
  uint64_t middle,
  std::deque<uint64_t>& order
)
{
  std::deque<uint64_t> queue;
  queue.push_back(middle);
  while (!queue.empty())
  {
    middle = queue.front(); queue.pop_front();
    order.push_back(middle);
    if (binary_tree[middle][0]) { queue.push_back(binary_tree[middle][0]); }
    if (binary_tree[middle][1]) { queue.push_back(binary_tree[middle][1]); }
  }
  return;
}

int main ()
{
  uint64_t n;
  std::cin >> n;
  std::vector<std::vector<uint64_t>> binary_tree(n + 1, std::vector<uint64_t>(2));
  std::vector<uint64_t> in_degree(n + 1);
  for (uint64_t i {1}; i != n; ++i)
  {
    uint64_t from, to, is_right;
    std::cin >> from >> to >> is_right;
    binary_tree[from][is_right] = to;
    ++in_degree[to];
  }
  uint64_t root {};
  for (uint64_t i {1}; i <= n; ++i)
  {
    if (in_degree[i] == 0) { root = i; }
  }
  std::deque<uint64_t> order;
  for (auto Order : {PreOrder, InOrder, PostOrder, LevelOrder})
  {
    order.clear();
    Order(binary_tree, root, order);
    std::cout << order << "\n";
  }
  return 0;
}