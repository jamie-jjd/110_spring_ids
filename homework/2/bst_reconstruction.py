# author: redleaf
# email: redleaf23477@gapp.nthu.edu.tw
import sys
sys.setrecursionlimit(150000)

class Node():
    def __init__(self, d, lchild = None, rchild = None):
        self.data = d
        self.lchild = lchild
        self.rchild = rchild

def recursive_build(l, r, arr):
    if r < l: return None
    mid = next((i for i in range(l+1, r+1) if arr[i] > arr[l]), r+1)
    return Node(arr[l],
            recursive_build(l+1, mid-1, arr),
            recursive_build(mid, r, arr))

def iterative_build(arr):
    stk = [(0, len(arr)-1)]
    res = []
    while len(stk) > 0:
        l, r = stk.pop();
        if l <= r:
            mid = next((i for i in range(l+1, r+1) if arr[i] > arr[l]), r+1)
            res.append(Node(arr[l]))
            stk.append((l+1, mid-1))
            stk.append((mid, r))
    while len(res) > 1:
        lchild = res.pop()
        rchild = res.pop()
        res[-1].lchild, res[-1].rchild = lchild, rchild
    return res[0]

def recursive_print_inorder(tree):
    if tree.lchild is not None: recursive_print_inorder(tree.lchild)
    print(tree.data, end=" ")
    if tree.rchild is not None: recursive_print_inorder(tree.rchild)

def recursive_print_postorder(tree):
    if tree.lchild is not None: recursive_print_postorder(tree.lchild)
    if tree.rchild is not None: recursive_print_postorder(tree.rchild)
    print(tree.data, end=" ")

def solve():
    N = int(input())
    arr = list(map(int, input().split()))

    tree = recursive_build(0, N-1, arr)

    recursive_print_inorder(tree)
    print()
    recursive_print_postorder(tree)
    print()

if __name__=='__main__':
    solve()

# author: jamie
# email: jinjiedeng.jjd@gmail.com
from collections import deque

def Reconstruct (pre_order, first_pre, last_pre, in_order, first_in, last_in, post_order):
    if first_pre <= last_pre:
        post_order.appendleft(pre_order[first_pre])
        middle_in = in_order.index(pre_order[first_pre])
        middle_pre = first_pre + (middle_in - first_in)
        Reconstruct(pre_order, middle_pre + 1, last_pre, in_order, middle_in + 1, last_in, post_order)
        Reconstruct(pre_order, first_pre + 1, middle_pre, in_order, first_in, middle_in - 1, post_order)

if __name__ == "__main__":
    N = int(input())
    pre_order = list(map(int, input().split()))
    in_order = sorted(pre_order)
    post_order = deque()
    Reconstruct(pre_order, 0, N - 1, in_order, 0, N - 1, post_order)
    print(" ".join(map(str, in_order)))
    print(" ".join(map(str, post_order)))