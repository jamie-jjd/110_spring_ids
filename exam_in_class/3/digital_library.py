# author: jamie
# email: jinjiedeng.jjd@gmail.com
class Node:
    def __init__ (self, key):
        self.key = key
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
                    parent = node
                    node = node.left
                elif key > node.key:
                    parent = node
                    node = node.right
                else:
                    if node.left:
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

if __name__ == "__main__":
    n, m = map(int, input().split())
    B = [0]
    B.extend(map(int, input().split()))
    q = int(input())
    type_user = [BinarySearchTree() for _ in range(n + 1)]
    user_type = [BinarySearchTree() for _ in range(m + 1)]
    for _ in range(q):
        uid, tid = map(int, input().split())
        if not user_type[uid].Search(tid):
            if B[tid]:
                B[tid] -= 1
                user_type[uid].Insert(tid)
                type_user[tid].Insert(uid)
            else:
                revoked_uid = type_user[tid].Successor(uid) if uid < type_user[tid].Max() else type_user[tid].Max()
                user_type[revoked_uid].Delete(tid)
                user_type[uid].Insert(tid)
                type_user[tid].Delete(revoked_uid)
                type_user[tid].Insert(uid)
        print(user_type[uid].Size())
    for types in user_type[1:]:
        if types.Empty():
            print(0)
        else:
            rental_status = []
            while not types.Empty():
                min = types.Min()
                rental_status.append(min)
                types.Delete(min)
            print(" ".join(map(str, rental_status)))