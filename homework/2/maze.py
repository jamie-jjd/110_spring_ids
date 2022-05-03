# author: redleaf
# email: redleaf23477@gapp.nthu.edu.tw
from collections import deque


def find(maze, ch):
    for r in range(R):
        c = maze[r].find(ch)
        if c != -1:
            return (r, c)
    return (-1, -1)


def bfs(maze, R, C):
    vis = [[-1] * C for _ in range(R)]
    r, c = find(maze, "A")
    vis[r][c] = 0
    q = deque([(r, c)])

    legal = lambda r, c: 0 <= r and r < R and 0 <= c and c < C

    while len(q) > 0:
        r, c = q.popleft()
        if maze[r][c] == "B":
            return vis[r][c]
        for dr, dc in zip([-1, 1, 0, 0], [0, 0, -1, 1]):
            nr, nc = r + dr, c + dc
            if legal(nr, nc) and maze[nr][nc] != "#" and vis[nr][nc] == -1:
                vis[nr][nc] = vis[r][c] + 1
                q.append((nr, nc))

    return -1


if __name__=='__main__':
    R, C = map(int, input().split())
    maze = [input() for _ in range(R)]
    ans = bfs(maze, R, C)
    print(ans if ans != -1 else "IMPOSSIBLE")
