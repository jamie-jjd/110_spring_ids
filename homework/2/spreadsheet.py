# author: redleaf
# email: redleaf23477@gapp.nthu.edu.tw
from collections import deque

def solve():
    n, m = map(int, input().split())
    graph = [[] for _ in range(n)]
    val = [0] * n
    indeg = [0] * n
    for _ in range(m):
        cmd = list(map(int, input().split()[1:]))
        v = cmd[0]
        val[v-1] = cmd[-1]
        for u in cmd[1:-1]:
            graph[u - 1].append(v - 1)
            indeg[v - 1] += 1
    q = deque([x for x in range(n) if indeg[x] == 0])
    while len(q) > 0:
        u = q.popleft()
        for v in graph[u]:
            indeg[v] -= 1
            val[v] += val[u]
            if indeg[v] == 0:
                q.append(v)
    for i in range(n):
        print(val[i] if indeg[i] == 0 else "#REF!")

if __name__=='__main__':
    solve()