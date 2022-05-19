# author: jamie
# email: jinjiedeng.jjd@gmail.com
def EulerTour (adj, euler_tour):
    stack = [(0, 0)]
    while len(stack):
        u, i = stack.pop()
        if i != len(adj[u]):
            stack.append((u, i + 1))
            stack.append((adj[u][i], 0))
        if i == 0:
            euler_tour.append(u)
        if i == len(adj[u]):
            euler_tour.append(u)

if __name__ == "__main__":
    n = int(input())
    adj = []
    for _ in range(n):
        _, *children = map(int, input().split())
        adj.append(children)
    euler_tour = []
    EulerTour(adj, euler_tour)
    print("Euler tour:", " ".join(map(str, euler_tour)))