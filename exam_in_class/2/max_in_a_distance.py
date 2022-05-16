# author: jamie
# email: jinjiedeng.jjd@gmail.com
from collections import deque

def CalculateMaxIndex (graph, max_index, s):
    is_in_deque = [False] * len(graph)
    D = [0] * len(graph)
    queue = deque()
    queue.append(s)
    is_in_deque[s] = True
    while len(queue):
        u = queue.popleft()
        for v in graph[u]:
            if not is_in_deque[v]:
                queue.append(v)
                is_in_deque[v] = True
                D[v] = D[u] + 1
                if max_index[D[v]] < v: max_index[D[v]] = v
    max_index[0] = s
    for i in range(len(graph)):
        if D[i] == 0 and max_index[0] < i: max_index[0] = i

if __name__ == "__main__":
    n, m, s = map(int, input().split())
    graph = [[] for _ in range(n + 1)]
    for _ in range(m):
        u, v = map(int, input().split())
        graph[u].append(v)
        graph[v].append(u)
    max_index = [0] * n
    CalculateMaxIndex(graph, max_index, s)
    D = list(map(int, input().split()))
    for i, d in enumerate(D):
        D[i] = max_index[d]
    print(" ".join(map(str, D)))