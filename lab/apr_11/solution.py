#
# author: jamie
# email: jinjiedeng.jjd@gmail.com
#
from collections import deque

def BFS (graph, is_visited, source):
    queue = deque()
    queue.append(source)
    while len(queue):
        from_ = queue[0]
        queue.popleft() # this line and the previous line are the only difference from DFS
        for to in graph[from_]:
            if not is_visited[to]:
                is_visited[to] = True
                queue.append(to)

def DFS (graph, is_visited, source):
    stack = deque()
    stack.append(source)
    while len(stack):
        from_ = stack[-1]
        stack.pop() # this line and the previous line are the only difference from BFS
        for to in graph[from_]:
            if not is_visited[to]:
                is_visited[to] = True
                stack.append(to)

def CountConnectedComponetns (graph):
    count = 0
    is_visited = [False for _ in range(n + 1)]
    for source in range(1, len(is_visited)):
        if not is_visited[source]:
            count += 1
            # either BFS or DFS works
            BFS(graph, is_visited, source)
            # DFS(graph, is_visited, source)
    return count

if __name__ == "__main__":
    n = int(input())
    m = int(input())
    graph = [[] for _ in range(n + 1)]
    for _ in range(m):
        u, v = map(int, input().split())
        graph[u].append(v)
        graph[v].append(u)
    print(CountConnectedComponetns(graph))