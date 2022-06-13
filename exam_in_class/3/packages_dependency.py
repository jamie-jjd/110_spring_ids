# author: redleaf
# email: redleaf23477@gapp.nthu.edu.tw
graph, dep, stat = None, None, None

def install(u):
    global graph, dep, stat
    ans = 1
    for v in graph[u]:
        dep[v] += 1
        if stat[v] == 0:
            stat[v] = 2
            ans += install(v)
    return ans

def remove(u):
    global graph, dep, stat
    if dep[u] != 0:
        return 0
    ans = 1
    stat[u] = 0
    for v in graph[u]:
        dep[v] -= 1
        if dep[v] == 0 and stat[v] != 1:
            ans += remove(v)
    return ans


if __name__ == '__main__':
    n, q = map(int, input().split())
    graph = []
    for u in range(n):
        graph.append(list(map(int, input().split()))[1:])

    dep = [0] * n
    stat = [0] * n  # 0 = uninstalled, 1 = user installed, 2 = sys installed

    for _ in range(q):
        qry = input().split()
        if qry[0] == 'INSTALL':
            p = int(qry[1])
            stat[p] = 1
            print(install(p))
        elif qry[0] == 'REMOVE':
            p = int(qry[1])
            print(remove(p))
        else:
            ans = [i for i in range(n) if stat[i] != 0]
            print(len(ans), *ans);

# author: jamie
# email: jinjiedeng.jjd@gmail.com
from collections import deque

def Install (adj, user_installed, auto_installed, in_degree, x):
    count = 0
    user_installed.add(x)
    queue = deque()
    queue.append(x)
    while len(queue):
        count += 1
        u = queue.popleft()
        for v in adj[u]:
            if v not in user_installed and v not in auto_installed:
                auto_installed.add(v)
                queue.append(v)
            in_degree[v] += 1
    return count
    
def Remove (adj, user_installed, auto_installed, in_degree, x):
    count = 0
    if in_degree[x] == 0:
        queue = deque()
        if x in user_installed: user_installed.remove(x)
        elif x in auto_installed: auto_installed.remove(x)
        queue.append(x)
        while len(queue):
            count += 1
            u = queue.popleft()
            for v in adj[u]:
                in_degree[v] -= 1
                if v in auto_installed and in_degree[v] == 0:
                    auto_installed.remove(v)
                    queue.append(v)
    return count
    
if __name__ == "__main__":
    n, q = map(int, input().split())
    adj, in_degree = [[] for _ in range(n)], [0 for _ in range(n)]
    for u in range(n):
        m, *vs = map(int, input().split())
        for v in vs:
            adj[u].append(v)
    user_installed, auto_installed = set(), set()
    for _ in range(q):
        operation, *x = input().split()
        if operation == "INSTALL":
            x = int(x[0])
            print(Install(adj, user_installed, auto_installed, in_degree, x))
        elif operation == "REMOVE":
            x = int(x[0])
            print(Remove(adj, user_installed, auto_installed, in_degree, x))
        elif operation == "LIST":
            installed = [u for u in user_installed]
            for u in auto_installed: installed.append(u)
            print(str(len(installed)) + " " + " ".join(map(str, sorted(installed))))