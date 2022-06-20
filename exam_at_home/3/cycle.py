# author: jamie
# email: jinjiedeng.jjd@gmail.com
from collections import deque

def MinCycle (adj):
    min_cycle_length = len(adj) + 1
    for s in range(len(adj)):
        stack, distance = [], [0] * len(adj)
        stack.append([s, 0])
        while len(stack):
            u, i = stack.pop()
            if i != len(adj[u]):
                stack.append([u, i + 1])
                v = adj[u][i]
                if distance[v]:
                    cycle_length = distance[u] + 1 - distance[v]
                    if cycle_length < min_cycle_length: min_cycle_length = cycle_length
                else:
                    distance[v] = distance[u] + 1
                    stack.append([v, 0])
            else:
                distance[u] = 0
    return min_cycle_length if min_cycle_length != len(adj) + 1 else 0

if __name__ == "__main__":
    n, m = map(int, input().split())
    adj = [[] for _ in range(n)]
    for _ in range(m):
        u, v = map(int, input().split())
        adj[u].append(v)
    print(MinCycle(adj))