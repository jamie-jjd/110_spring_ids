#
# author: jamie
# email: jinjiedeng.jjd@gmail.com
#
from collections import deque

### iterative version (with stack) ###
def PreOrder (binary_tree, middle, order):
    stack = [middle]
    while len(stack):
        middle = stack[-1]
        stack.pop()
        order.append(middle)
        if binary_tree[middle][1]: stack.append(binary_tree[middle][1])
        if binary_tree[middle][0]: stack.append(binary_tree[middle][0])

### recursive version ###
# def PreOrder (binary_tree, middle, order):
#     order.append(middle)
#     if binary_tree[middle][0]: PreOrder(binary_tree, binary_tree[middle][0], order)
#     if binary_tree[middle][1]: PreOrder(binary_tree, binary_tree[middle][1], order)

### iterative version (with stack) ###
def InOrder (binary_tree, middle, order):
    is_forward = [True] * len(binary_tree)
    stack = [middle]
    while len(stack):
        middle = stack[-1]
        stack.pop()
        if is_forward[middle]:
            if binary_tree[middle][1]: stack.append(binary_tree[middle][1])
            stack.append(middle)
            is_forward[middle] = False
            if binary_tree[middle][0]: stack.append(binary_tree[middle][0])
        else: order.append(middle)

### iterative version (without stack): morris traversal ###
# def InOrder (binary_tree, middle, order):
#   while middle:
#     if binary_tree[middle][0]: # left child exists
#         # find predecessor of middle
#         prev = binary_tree[middle][0]
#         while binary_tree[prev][1] and binary_tree[prev][1] != middle: prev = binary_tree[prev][1]
#         if binary_tree[prev][1] == 0: # right child of predecessor of middle is empty
#             binary_tree[prev][1] = middle # temporarily set right child of predecessor of middle as middle
#             middle = binary_tree[middle][0] # move to left child
#         else: # left subtree of middle are traversed
#             middle = binary_tree[prev][1] # retrieve middle
#             binary_tree[prev][1] = 0 # reset right child of predecessor of middle as empty
#             order.append(middle) # output middle
#             middle = binary_tree[middle][1] # move to right child
#     else: # no left child
#         order.append(middle) # output middle
#         middle = binary_tree[middle][1] # move to right

### recursive version ###
# def InOrder (binary_tree, middle, order):
#     if binary_tree[middle][0]: InOrder(binary_tree, binary_tree[middle][0], order)
#     order.append(middle)
#     if binary_tree[middle][1]: InOrder(binary_tree, binary_tree[middle][1], order)

### iterative version (with stack) ###
def PostOrder (binary_tree, middle, order):
    stack = [middle]
    while (len(stack)):
        middle = stack[-1]
        stack.pop()
        order.appendleft(middle)
        if binary_tree[middle][0]: stack.append(binary_tree[middle][0])
        if binary_tree[middle][1]: stack.append(binary_tree[middle][1])

### recursive version ###
# def PostOrder (binary_tree, middle, order):
#     if binary_tree[middle][0]: PostOrder(binary_tree, binary_tree[middle][0], order)
#     if binary_tree[middle][1]: PostOrder(binary_tree, binary_tree[middle][1], order)
#     order.append(middle)

def LevelOrder (binary_tree, middle, order):
    queue = deque()
    queue.append(middle)
    while len(queue):
        middle = queue[0]
        queue.popleft()
        order.append(middle)
        if binary_tree[middle][0]: queue.append(binary_tree[middle][0])
        if binary_tree[middle][1]: queue.append(binary_tree[middle][1])

if __name__ == "__main__":
    n = int(input())
    binary_tree = [[0, 0] for _ in range(n + 1)]
    in_degree = [0] * (n + 1)
    for i in range(1, n):
        u, v, b = list(map(int, input().split()))
        binary_tree[u][b] = v
        in_degree[v] += 1
    for i in range(1, n + 1):
        if in_degree[i] == 0:
            root = i
    for Order in [PreOrder, InOrder, PostOrder, LevelOrder]:
        order = deque()
        Order(binary_tree, root, order)
        print(" ".join(map(str, order)))