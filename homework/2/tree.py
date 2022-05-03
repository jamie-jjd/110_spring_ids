# author: redleaf
# email: redleaf23477@gapp.nthu.edu.tw
arr, graph = None, None

def dfs(u, pa):
    global arr, graph
    stack = [(u, pa, 0)]
    while len(stack) > 0:
        u, pa, idx = stack.pop()
        if idx + 1 <= len(graph[u]):
            stack.append((u, pa, idx + 1))
        if idx == len(graph[u]):
            if u != pa: arr[pa] += arr[u]
            continue
        v = graph[u][idx]
        if v != pa:
            stack.append((v, u, 0))

def solve():
    global arr, graph
    n = int(input())
    arr = list(map(int, input().split()))
    graph = [[] for _ in range(n)]
    for _ in range(n-1):
        u, v = map(int, input().split())
        u, v = u-1, v-1
        graph[u].append(v)
        graph[v].append(u)
    dfs(0, 0)
    print(*arr)

if __name__=='__main__':
    solve()
