/*
* author: jamie
* email: jinjiedeng.jjd@gmail.com
*/
#include <iostream>
#include <memory>

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
  bool Size () const;
  void Insert (uint64_t key);
  void Delete (uint64_t key);
  bool Search (uint64_t key) const;
  uint64_t Min () const;
  uint64_t Max () const;
  uint64_t Predecessor (uint64_t key) const;
  uint64_t Successor (uint64_t key) const;
  uint64_t Rank (uint64_t key) const;
  uint64_t Select (uint64_t k) const;

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

uint64_t BinarySearchTree::Predecessor (uint64_t key) const
{
  Node* pred {};
  Node* node {root_.get()};
  while (node)
  {
    if (key <= node->key) { node = node->left.get(); }
    else                  { pred = node; node = node->right.get(); }
  }
  if (pred) { return pred->key; }
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

uint64_t BinarySearchTree::Rank (uint64_t key) const
{
  uint64_t rank {};
  Node* node {root_.get()};
  while (node)
  {
    if (key < node->key) { node = node->left.get(); }
    else if (key > node->key)
    {
      rank += (node->left_subtree_size + 1);
      node = node->right.get();
    }
    else { return rank + (node->left_subtree_size + 1); }
  }
  return 0;
}

uint64_t BinarySearchTree::Select (uint64_t k) const
{
  uint64_t rank {};
  Node *node {root_.get()};
  while (node)
  {
    rank += (node->left_subtree_size + 1);
    if (k < rank)
    {
      rank -= (node->left_subtree_size + 1);
      node = node->left.get();
    }
    else if (k > rank) { node = node->right.get(); }
    else               { return node->key; }
  }
  return 0;
}

int main ()
{
  uint64_t m;
  std::cin >> m;
  std::string type;
  uint64_t key, k;
  BinarySearchTree bst;
  while (m--)
  {
    std::cin >> type;
    if (type == "insert")
    {
      std::cin >> key;
      bst.Insert(key);
    }
    else if (type == "delete")
    {
      std::cin >> key;
      bst.Delete(key);
    }
    else if (type == "search")
    {
      std::cin >> key;
      std::cout << bst.Search(key) << "\n";
    }
    else if (type == "min")
    {
      std::cout << bst.Min() << "\n";
    }
    else if (type == "max")
    {
      std::cout << bst.Max() << "\n";
    }
    else if (type == "predecessor")
    {
      std::cin >> key;
      std::cout << bst.Predecessor(key) << "\n";
    }
    else if (type == "successor")
    {
      std::cin >> key;
      std::cout << bst.Successor(key) << "\n";
    }
    else if (type == "rank")
    {
      std::cin >> key;
      std::cout << bst.Rank(key) << "\n";
    }
    else if (type == "select")
    {
      std::cin >> k;
      std::cout << bst.Select(k) << "\n";
    }
  }
  return 0;
}