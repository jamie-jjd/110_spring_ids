# author: jamie
# email: jinjiedeng.jjd@gmail.com
class Node:
    def __init__ (self, key):
        self.key = key
        self.left_subtree_size = 0
        self.left = None
        self.right = None

class BinarySearchTree:
    def __init__ (self):
        self.root = None
        self.size = 0

    def Empty (self):
        return (self.root is None)

    def Size (self):
        return self.size

    def Insert (self, key):
        if not self.Search(key):
            self.size += 1
            if self.root:
                node = self.root
                while node:
                    if key < node.key:
                        node.left_subtree_size += 1
                        if node.left:
                            node = node.left
                        else:
                            node.left = Node(key)
                            break
                    else:
                        if node.right:
                            node = node.right
                        else:
                            node.right = Node(key)
                            break
            else:
                self.root = Node(key)

    def Delete (self, key):
        if self.Search(key):
            self.size -= 1
            parent = None
            node = self.root
            while node:
                if key < node.key:
                    node.left_subtree_size -= 1
                    parent = node
                    node = node.left
                elif key > node.key:
                    parent = node
                    node = node.right
                else:
                    if node.left:
                        node.left_subtree_size -= 1
                        self.DeletePredecessorInstead(node)
                    else:
                        if parent:
                            if node == parent.left:
                                parent.left = node.right
                            else:
                                parent.right = node.right
                        else:
                            self.root = self.root.right
                    break

    def DeletePredecessorInstead (self, node):
        parent_pred = node
        pred = node.left
        while pred.right:
            parent_pred = pred
            pred = pred.right
        node.key = pred.key
        if parent_pred == node:
            parent_pred.left = pred.left
        else:
            parent_pred.right = pred.left

    def Search (self, key):
        node = self.root
        while node:
            if key < node.key:   node = node.left
            elif key > node.key: node = node.right
            else:                return True
        return False

    def Min (self):
        node = self.root
        while node and node.left: node = node.left
        return 0 if node is None else node.key

    def Max (self):
        node = self.root
        while node and node.right: node = node.right
        return 0 if node is None else node.key

    def Predecessor (self, key):
        pred = None
        node = self.root
        while node:
            if key <= node.key:
                node = node.left
            else:
                pred = node
                node = node.right
        return 0 if pred is None else pred.key

    def Successor (self, key):
        succ = None
        node = self.root
        while node:
            if key >= node.key:
                node = node.right
            else:
                succ = node
                node = node.left
        return 0 if succ is None else succ.key

    def Rank (self, key):
        rank = 0
        node = self.root
        while node:
            if key < node.key:
                node = node.left
            elif key > node.key:
                rank += node.left_subtree_size + 1
                node = node.right
            else:
                return rank + node.left_subtree_size + 1
        return 0

    def Select (self, k):
        rank = 0
        node = self.root
        while node:
            rank += node.left_subtree_size + 1
            if k < rank:
                rank -= node.left_subtree_size + 1
                node = node.left
            elif k > rank:
                node = node.right
            else:
                return node.key
        return 0

if __name__ == "__main__":
    size = 0
    bst = BinarySearchTree()
    n = int(input())
    for key in map(int, input().split()):
        bst.Insert(key)
    q = int(input())
    for _ in range(q):
        op, key = map(int, input().split())
        if op == 1: # insert
            bst.Insert(key)
            print(bst.Size())
        elif op == 2: # remove
            bst.Delete(key)
            print(bst.Size())
        elif op == 3: # is_member
            print("Yes" if bst.Search(key) else "No")
        elif op == 4: # lower_bound
            if bst.Search(key):
                print(key)
            else:
                response = bst.Successor(key)
                print(-1 if response == 0 else response)
        elif op == 5: # upper_bound
            response = bst.Successor(key)
            print(-1 if response == 0 else response)