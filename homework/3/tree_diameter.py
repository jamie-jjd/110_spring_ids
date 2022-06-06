# author: jamie
# email: jinjiedeng.jjd@gmail.com
from collections import deque

def FarthestNode (adj, parent_u, u):
    queue = deque()
    queue.append((parent_u, u, 0))
    while len(queue):
        parent_u, u, d = queue.popleft()
        for v in adj[u]:
            if v != parent_u:
                queue.append((u, v, d + 1))
    return u, d

# find both end of longest path
if __name__ == "__main__":
    n = int(input())
    adj = [[] for _ in range(n + 1)]
    for _ in range(n - 1):
        u, v = map(int, input().split())
        adj[u].append(v)
        adj[v].append(u)
    # for any node, say 1, one of two ends of the longest path in the tree is the farthest node from v, say u
    u, _ = FarthestNode(adj, 0, 1)
    # the other end of the longest path in the tree is the farthest node from u
    _, d = FarthestNode(adj, 0, u)
    print(d)

# author: jamie
# email: jinjiedeng.jjd@gmail.com
def Diameter (adj, parent_u, u):
    height = [0 for _ in range(len(adj))]
    diameter = [0 for _ in range(len(adj))]
    stack = [(parent_u, u, 0)]
    while len(stack):
        parent_u, u, i = stack.pop()
        if i != len(adj[u]):
            v = adj[u][i]
            stack.append((parent_u, u, i + 1))
            if v != parent_u:
                stack.append((u, v, 0))
        else:
            height_2nd = 0
            for v in adj[u]:
                if v != parent_u:
                    if height[u] < 1 + height[v]:
                        height[u], height_2nd = 1 + height[v], height[u]
                    elif height_2nd < 1 + height[v]:
                        height_2nd = 1 + height[v]
                    if diameter[u] < diameter[v]:
                        diameter[u] = diameter[v]
            if diameter[u] < height[u] + height_2nd:
                diameter[u] = height[u] + height_2nd
    return diameter[1]

# find middle node in the longest path
if __name__ == "__main__":
    n = int(input())
    adj = [[] for _ in range(n + 1)]
    for _ in range(n - 1):
        u, v = map(int, input().split())
        adj[u].append(v)
        adj[v].append(u)
    print(Diameter(adj, 0, 1))