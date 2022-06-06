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
    N, C = map(int, input().split())
    calories = list(map(int, input().split()))
    count = {}
    bst = BinarySearchTree()
    for c in calories:
        bst.Insert(c)
        if c not in count: count[c] = 0
        count[c] += 1
    number_boxes = 0
    while N > 1:
        c_max, c_min = bst.Max(), bst.Min()
        if c_max + c_min <= C:
            number_boxes += 1
            count[c_min] -= 1
            N -= 1
            if count[c_min] == 0:
                bst.Delete(c_min)
        elif c_max <= C:
            number_boxes += 1
        count[c_max] -= 1
        N -= 1
        if count[c_max] == 0:
            bst.Delete(c_max)
    if N == 1 and bst.Max() <= C:
        number_boxes += 1
    print(number_boxes)

# author: jamie
# email: jinjiedeng.jjd@gmail.com
if __name__ == "__main__":
    N, C = map(int, input().split())
    calories = sorted(list(map(int, input().split())))
    number_boxes = 0
    index_min, index_max = 0, N - 1
    while index_min < index_max:
        if calories[index_min] + calories[index_max] <= C:
            number_boxes += 1
            index_min += 1
            index_max -= 1
        elif calories[index_max] <= C:
            number_boxes += 1
            index_max -= 1
        else:
            index_max -= 1
    if index_min == index_max and calories[index_max] <= C:
        number_boxes += 1
    print(number_boxes)