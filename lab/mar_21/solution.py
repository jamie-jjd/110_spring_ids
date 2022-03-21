#
# author: wang yang
# email: tnst92002@gmail.com
#
N = int(input())
M = int(input())

Adj = [[]for _ in range(N+1)] # adjacency list

for _ in range(M):
    x,y = map(int, input().split())
    Adj[x].append(y)
    Adj[y].append(x)

def Sol(Adj, v):
    hit = [0 for i in range(N+1)]
    for u in Adj[v]:
        for w in Adj[u]:
            hit[w] = w
    hit[v] = 0
    return sum(hit)

ans = 0
for i in range(1, N+1):
    ans = max(ans, Sol(Adj, i))
print(ans)

N = int(input())
M = int(input())

#
# author: wang yang
# email: tnst92002@gmail.com
#
Adj = [[0] * (N+1) for _ in range(N+1)] # adjacency matrix

for _ in range(M):
    x,y = map(int, input().split())
    Adj[x][y] = Adj[y][x] = 1

def Sol(Adj, v):
    hit = [0 for i in range(N+1)]
    for u in range(1, N+1):
        if Adj[v][u]:
            for w in range(1, N+1):
                if Adj[u][w]:
                    hit[w] = w
    hit[v] = 0
    return sum(hit)

ans = 0
for i in range(1, N+1):
    ans = max(ans, Sol(Adj, i))
print(ans)

#
# author: redleaf
# email: redleaf23477@gapp.nthu.edu.tw
#
def adj_list():
    n = int(input())
    m = int(input())
    graph = [[] for _ in range(n)]
    for _ in range(m):
        u, v = map(int, input().split())
        u, v = u-1, v-1
        graph[u].append(v)
        graph[v].append(u)

    ans = 0
    for i in range(n):
        vis = [0] * n
        for u in graph[i]:
            for v in graph[u]:
                vis[v] = 1
        vis[i] = 0
        ans = max(ans, sum((i+1) * vis[i] for i in range(n)))
    print(ans)

def adj_mat():
    n = int(input())
    m = int(input())
    graph = [[0] * n for _ in range(n)]
    for _ in range(m):
        u, v = map(int, input().split())
        u, v = u-1, v-1
        graph[u][v] = graph[v][u] = 1

    ans = 0
    for i in range(n):
        vis = [0] * n
        for u in [u for u in range(n) if graph[i][u] == 1]:
            for v in [v for v in range(n) if graph[u][v] == 1]:
                vis[v] = 1
        vis[i] = 0
        ans = max(ans, sum((i+1) * vis[i] for i in range(n)))
    print(ans)

if __name__=='__main__':
    adj_mat()