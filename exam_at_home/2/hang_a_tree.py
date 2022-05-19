# author: jamie
# email: jinjiedeng.jjd@gmail.com
def CalculateMaxSubtreeSize (tree, max_subtree_size, tree_size):
    stack = [(-1, 0, 0)]
    while (len(stack)):
        parent_u, u, i = stack.pop()
        if i != len(tree[u]):
            stack.append((parent_u, u, i + 1))
            v = tree[u][i]
            if v != parent_u:
                stack.append((u, v, 0))
        else:
            for v in tree[u]:
                if v != parent_u:
                    tree_size[u] += tree_size[v]
                    if max_subtree_size[u] < tree_size[v]:
                        max_subtree_size[u] = tree_size[v]
            if max_subtree_size[u] < len(tree) - tree_size[u]:
                max_subtree_size[u] = len(tree) - tree_size[u]

if __name__ == "__main__":
    n = int(input())
    tree = [[] for _ in range(n)]
    for _ in range(n - 1):
        u, v = map(int, input().split())
        tree[u].append(v)
        tree[v].append(u)
    max_subtree_size = [0] * n
    tree_size = [1] * n
    CalculateMaxSubtreeSize(tree, max_subtree_size, tree_size)
    min_max_subtree_size = min(max_subtree_size)
    for i in range(n):
        if max_subtree_size[i] == min_max_subtree_size:
            print(i)