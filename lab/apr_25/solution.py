#
# author: jamie
# email: jinjiedeng.jjd@gmail.com
#
from collections import deque

### topological sort (with queue) ###
def IsDAG (graph):
    in_degree = [0] * len(graph)
    for vs in graph:
        for v in vs:
            in_degree[v] += 1
    queue = deque()
    for i in range(1, len(graph)):
        if in_degree[i] == 0:
            queue.append(i)
    while len(queue):
        u = queue[0]
        queue.popleft()
        for v in graph[u]:
            in_degree[v] -= 1
            if in_degree[v] == 0:
                queue.append(v)
    return sum(in_degree) == 0

### iterative version ###
# def DFS (graph, is_forward, source, finished_time):
#     stack = [source]
#     while len(stack):
#         u = stack[-1]
#         if is_forward[u]:
#             is_forward[u] = False
#             for v in graph[u]:
#                 if finished_time[v] == 0:
#                     stack.append(v)
#         else:
#             if finished_time[u] == 0:
#                 finished_time[0] += 1
#                 finished_time[u] = finished_time[0]
#             stack.pop()

### recursive version ###
# def DFS (graph, is_forward, u, finished_time):
#     is_forward[u] = False
#     for v in graph[u]:
#         if is_forward[v]:
#             DFS(graph, is_forward, v, finished_time)
#     finished_time[0] += 1
#     finished_time[u] = finished_time[0]

### topological sort (DFS) ###
# def IsDAG (graph):
#     finished_time = [0] * len(graph)
#     is_forward = [True] * len(graph)
#     time = 1
#     for source in range(1, len(graph)):
#         if finished_time[source] == 0:
#             DFS(graph, is_forward, source, finished_time)
#     is_DAG = True
#     for u in range(1, len(graph)):
#         for v in graph[u]:
#             is_DAG &= (finished_time[v] < finished_time[u])
#     return is_DAG

if __name__ == "__main__":
    n, m = map(int, input().split())
    graph = [[] for _ in range(n + 1)]
    for _ in range(m):
        u, v = map(int, input().split())
        graph[u].append(v)
    print("yes" if IsDAG(graph) else "no")