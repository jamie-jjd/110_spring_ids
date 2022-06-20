# author: jamie
# email: jinjiedeng.jjd@gmail.com

def IsConnected (adj):
    stack, is_in_stack = [], [False] * len(adj)
    stack.append(0)
    is_in_stack[0] = True
    while len(stack):
        u = stack.pop()
        for v in adj[u]:
            if not is_in_stack[v]:
                is_in_stack[v] = True
                stack.append(v)
    return sum(is_in_stack) == len(adj)
    
def IsAllEvenDegree (adj):
    return sum([len(_) % 2 for _ in adj]) == 0
    
def IsExistedEulerCircuit (adj):
    return IsConnected(adj) and IsAllEvenDegree(adj)    
    
if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        n, m = map(int, input().split())
        adj = [[] for _ in range(n)]
        for _ in range(m):
            u, v = map(int, input().split())
            adj[u].append(v)
            adj[v].append(u)
        print("yes" if IsExistedEulerCircuit(adj) else "no")