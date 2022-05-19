# author: jamie
# email: jinjiedeng.jjd@gmail.com
from collections import deque

def Fire (forest, H, W, fx, fy):
    queue = deque()
    dx = [-1, 0, 0, 1]
    dy = [0, -1, 1, 0]
    forest[fx][fy] = 1
    queue.append((fx, fy, 1))
    while len(queue):
        x, y, d = queue.popleft()
        for i in range(4):
            next_x = x + dx[i]
            next_y = y + dy[i]
            if -1 < next_x and next_x < H and -1 < next_y and next_y < W and d + 1 < forest[next_x][next_y]:
                forest[next_x][next_y] = d + 1
                queue.append((next_x, next_y, d + 1))

def Escape (forest, H, W, k, sx, sy, ex, ey):
    queue = deque()
    dx = [-1, -1, -1, 0, 0, 1, 1, 1]
    dy = [-1, 0, 1, -1, 1, -1, 0, 1]
    if k < forest[sx][sy]:
        forest[sx][sy] = k
        queue.append((sx, sy, k))
        while len(queue):
            x, y, d = queue.popleft()
            for i in range(8):
                next_x = x + dx[i]
                next_y = y + dy[i]
                if -1 < next_x and next_x < H and -1 < next_y and next_y < W and d + 1 < forest[next_x][next_y]:
                    forest[next_x][next_y] = d + 1
                    queue.append((next_x, next_y, d + 1))

if __name__ == "__main__":
    H, W = map(int, input().split())
    forest = [[] for _ in range(H)]
    for i in range(H):
        for c in input():
            forest[i].append(0 if c == "*" else H * W)
    fx, fy = map(int, input().split())
    k = int(input())
    sx, sy, ex, ey = map(int, input().split())
    forest[ex][ey] = 0
    Fire(forest, H, W, fx, fy)
    forest[ex][ey] = H * W
    Escape(forest, H, W, k, sx, sy, ex, ey)
    print("Help!" if forest[ex][ey] == H * W else forest[ex][ey] - k)