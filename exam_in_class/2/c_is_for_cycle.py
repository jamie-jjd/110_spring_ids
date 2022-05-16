# author: redleaf
# email: redleaf23477@gapp.nthu.edu.tw
def dfs(s, n, graph, vis):
    '''
    iterative version of dfs
    '''
    stack = [s]
    vis[s] = True
    while len(stack) > 0:
        u = stack[-1]

        # pop parent node in dfs tree
        if len(graph[u]) > 0 and len(stack) > 1 and graph[u][-1] == stack[-2]:
            graph[u].pop()

        # if all neighbors of u doesn't lead to a cycle, bye u
        if len(graph[u]) == 0:
            stack.pop()
            continue

        # get an neighbor
        v = graph[u].pop()

        if vis[v] == True:
            # I found a cycle v -> ... -> u -> v
            idx = stack.index(v)
            cycle = stack[idx:]
            return cycle
        else:
            # add tree edge in DFS tree
            vis[v] = True
            stack.append(v)

    # no cycle found
    return []


def find_cycle(n, graph):
    vis = [False] * n
    for u in range(n):
        if vis[u] == False:
            c = dfs(u, n, graph, vis)
            if len(c) > 0:
                return c
    return []


if __name__ == '__main__':
    n, m = map(int, input().split())
    graph = [[] for _ in range(n)]
    for _ in range(m):
        u, v = map(int, input().split())
        u, v = u - 1, v - 1
        graph[u].append(v)
        graph[v].append(u)

    cycle = find_cycle(n, graph)
    if len(cycle) == 0:
        print("IMPOSSIBLE")
    else:
        print(len(cycle))
        print(*[x + 1 for x in cycle])

# author: jamie
# email: jinjiedeng.jjd@gmail.com
def IsCycleExisted (graph, is_visited, parent_u, u, cycle):
    global detected_node
    is_visited[u] = True
    for v in graph[u]:
        if not is_visited[v]:
            is_visited[v] = True
            if IsCycleExisted(graph, is_visited, u, v, cycle):
                if detected_node:
                    cycle.append(u)
                    if detected_node == u:
                        detected_node = 0
                return True
        elif v != parent_u:
            cycle.append(u)
            detected_node = v
            return True
    return False

if __name__ == "__main__":
    n, m = map(int, input().split())
    graph = [[] for _ in range(n + 1)]
    for _ in range(m):
        u, v = map(int, input().split())
        graph[u].append(v)
        graph[v].append(u)
    is_visited = [False] * (n + 1)
    cycle = []
    for source in range(1, n + 1):
        if not is_visited[source]:
            detected_node = 0
            if IsCycleExisted(graph, is_visited, 0, source, cycle):
                break
    if len(cycle):
        print(len(cycle))
        print(" ".join(map(str, cycle)))
    else:
        print("IMPOSSIBLE")