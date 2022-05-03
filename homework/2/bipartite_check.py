# author: redleaf
# email: redleaf23477@gapp.nthu.edu.tw
from collections import deque

graph, vis = [], []

def bfs(u):
    global graph, vis
    q = deque([u])
    while len(q) > 0:
        u = q.popleft()
        for v in graph[u]:
            if vis[v] == -1:
                vis[v] = 1 - vis[u]
                q.append(v)
            elif vis[u] == vis[v]:
                return False
    return True


def recursive_dfs(u):
    global graph, vis
    ans = True
    for v in graph[u]:
        if vis[v] == -1:
            vis[v] = 1 - vis[u]
            ans = ans and dfs(v)
        elif vis[v] == vis[u]:
            ans = False
    return ans


def iterative_dfs(u):
    global graph, vis
    stk = [u]
    while len(stk) > 0:
        u = stk.pop()
        for v in graph[u]:
            if vis[v] == -1:
                vis[v] = 1 - vis[u]
                stk.append(v)
            elif vis[v] == vis[u]:
                return False
    return True


def solve():
    global graph, vis
    V, E = map(int, input().split())
    graph = [[] for _ in range(V)]
    for _ in range(E):
        u, v = map(int, input().split())
        u, v = u - 1, v - 1
        graph[u].append(v)
        graph[v].append(u)
    vis = [-1] * V
    ans = True
    for v in range(V):
        if vis[v] == -1:
            vis[v] = 1
            ans = ans and iterative_dfs(v)
    return ans


if __name__=='__main__':
    print("YES" if solve() else "NO")
