# author: jamie
# email: jinjiedeng.jjd@gmail.com
from collections import deque

def CalculateMaxWeight (reverse_adj, in_degree, weight):
    queue = deque()
    for b in range(len(reverse_adj)):
        if in_degree[b] == 0:
            queue.append(b)
    while len(queue):
        b = queue.popleft()
        for a in reverse_adj[b]:
            if weight[a] < weight[b]: weight[a] = weight[b]
            in_degree[a] -= 1
            if in_degree[a] == 0: queue.append(a)

if __name__ == "__main__":
    n, m = map(int, input().split())
    weight = list(map(int, input().split()))
    reverse_adj = [[] for _ in range(n)]
    in_degree = [0 for _ in range(n)]
    for _ in range(m):
        a, b = map(int, input().split())
        reverse_adj[b].append(a)
        in_degree[a] += 1
    CalculateMaxWeight(reverse_adj, in_degree, weight)
    print(" ".join(map(str, weight)))