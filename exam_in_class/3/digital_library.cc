/*
* author: jamie
* email: jinjiedeng.jjd@gmail.com
*/
#include <iostream>
#include <set>
#include <vector>

int main ()
{
  uint64_t n, m; std::cin >> n >> m;
  std::vector<uint64_t> B(n + 1);
  for (uint64_t tid {1}; tid != B.size(); ++tid) { std::cin >> B[tid]; }
  uint64_t q; std::cin >> q;
  std::vector<std::set<uint64_t>> type_user(n + 1), user_type(m + 1);
  while (q--)
  {
    uint64_t uid, tid; std::cin >> uid >> tid;
    if (user_type[uid].count(tid) == 0)
    {
      if (B[tid] == 0)
      {
        auto revoked_uid {(uid < *type_user[tid].rbegin()) ? *type_user[tid].upper_bound(uid) : *type_user[tid].rbegin()};
        user_type[revoked_uid].erase(tid);
        type_user[tid].erase(revoked_uid);
      } else { --B[tid]; }
      user_type[uid].insert(tid);
      type_user[tid].insert(uid);
    }
    std::cout << user_type[uid].size() << "\n";
  }
  for (uint64_t uid {1}; uid != user_type.size(); ++uid)
  {
    if (user_type[uid].size())
    {
      auto it {user_type[uid].begin()};
      std::cout << *it++;
      while (it != user_type[uid].end()) { std::cout << " " << *it++; }
    }
    else { std::cout << "0"; }
    std::cout << "\n";
  }
  return 0;
}

/*
* author: jamie
* email: jinjiedeng.jjd@gmail.com
*/
#include <iostream>
#include <memory>
#include <vector>

struct Node
{
  Node (uint64_t k = 0): key {k}, left_subtree_size {} {}

  uint64_t key;
  uint64_t left_subtree_size;
  std::unique_ptr<Node> left;
  std::unique_ptr<Node> right;
};

class BinarySearchTree
{
public:

  bool Empty () const;
  uint64_t Size () const;
  void Insert (uint64_t key);
  void Delete (uint64_t key);
  bool Search (uint64_t key) const;
  uint64_t Min () const;
  uint64_t Max () const;
  uint64_t Successor (uint64_t key) const;

private:

  void DeletePredecessorInstead (Node* node);

  std::unique_ptr<Node> root_;
  uint64_t size_;

};

bool BinarySearchTree::Empty () const
{
  return (root_ == nullptr);
}

uint64_t BinarySearchTree::Size () const
{
  return size_;
}

void BinarySearchTree::Insert (uint64_t key)
{
  if (!Search(key))
  {
    ++size_;
    if (!root_) { root_ = std::make_unique<Node>(key); return; }
    Node* node {root_.get()};
    while (node)
    {
      if (key < node->key)
      {
        ++(node->left_subtree_size);
        if (node->left) { node = node->left.get(); }
        else            { node->left = std::make_unique<Node>(key); return; }
      }
      else
      {
        if (node->right) { node = node->right.get(); }
        else             { node->right = std::make_unique<Node>(key); return; }
      }
    }
  }
  return;
}

void BinarySearchTree::DeletePredecessorInstead (Node* node)
{
  Node* parent_pred {node};
  Node* pred {node->left.get()};
  while (pred->right) { parent_pred = pred; pred = pred->right.get(); }
  node->key = pred->key;
  if (parent_pred == node) { node->left.reset(pred->left.release()); }
  else                     { parent_pred->right.reset(pred->left.release()); }
  return;
}

void BinarySearchTree::Delete (uint64_t key)
{
  if (Search(key))
  {
    --size_;
    Node* parent {};
    Node* node {root_.get()};
    while (node)
    {
      if (key < node->key)
      {
        --(node->left_subtree_size);
        parent = node; node = node->left.get();
      }
      else if (key > node->key)
      {
        parent = node; node = node->right.get();
      }
      else
      {
        if (node->left)
        {
          --(node->left_subtree_size);
          DeletePredecessorInstead(node);
        }
        else
        {
          if (parent)
          {
            if (node == parent->left.get()) { parent->left.reset(node->right.release()); }
            else                            { parent->right.reset(node->right.release()); }
          }
          else { root_.reset(root_->right.release()); }
        }
        break;
      }
    }
  }
  return;
}

bool BinarySearchTree::Search (uint64_t key) const
{
  Node* node {root_.get()};
  while (node)
  {
    if (key < node->key)      { node = node->left.get(); }
    else if (key > node->key) { node = node->right.get(); }
    else                      { return true; }
  }
  return false;
}

uint64_t BinarySearchTree::Min () const
{
  Node* node {root_.get()};
  while (node && node->left) { node = node->left.get(); }
  if (node) { return node->key; }
  return 0;
}

uint64_t BinarySearchTree::Max () const
{
  Node* node {root_.get()};
  while (node && node->right) { node = node->right.get(); }
  if (node) { return node->key; }
  return 0;
}

uint64_t BinarySearchTree::Successor (uint64_t key) const
{
  Node* succ {};
  Node* node {root_.get()};
  while (node)
  {
    if (key >= node->key) { node = node->right.get(); }
    else                  { succ = node; node = node->left.get(); }
  }
  if (succ) { return succ->key; }
  return 0;
}

int main ()
{
  uint64_t n, m; std::cin >> n >> m;
  std::vector<uint64_t> B(n + 1);
  for (uint64_t tid {1}; tid != B.size(); ++tid) { std::cin >> B[tid]; }
  uint64_t q; std::cin >> q;
  std::vector<BinarySearchTree> type_user(n + 1), user_type(m + 1);
  while (q--)
  {
    uint64_t uid, tid; std::cin >> uid >> tid;
    if (!user_type[uid].Search(tid))
    {
      if (B[tid] == 0)
      {
        auto revoked_uid {(uid < type_user[tid].Max()) ? type_user[tid].Successor(uid) : type_user[tid].Max()};
        user_type[revoked_uid].Delete(tid);
        type_user[tid].Delete(revoked_uid);
      } else { --B[tid]; }
      user_type[uid].Insert(tid);
      type_user[tid].Insert(uid);
    }
    std::cout << user_type[uid].Size() << "\n";
  }
  for (uint64_t uid {1}; uid != user_type.size(); ++uid)
  {
    if (!user_type[uid].Empty())
    {
      while (!user_type[uid].Empty())
      {
        auto min {user_type[uid].Min()}; user_type[uid].Delete(min);
        std::cout << min;
        std::cout << ((user_type[uid].Empty()) ? "\n" : " ");
      }
    }
    else { std::cout << "0\n"; }
  }
  return 0;
}