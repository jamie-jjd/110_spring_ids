#
# author: jamie
# email: jinjiedeng.jjd@gmail.com
#
from collections import deque

def Solve (n, m):
    queue = deque()
    count_enqueue = [0] * n
    count_dequeue = [0] * n
    for _ in range(m):
        op = list(map(int, input().split()))
        if op[0] == 0: # enqueue
            queue.append(op[1])
            count_enqueue[op[1]] += 1
        elif op[0] == 1: # dequeue
            while len(queue) and not (count_enqueue[queue[0]] == 1 and count_dequeue[queue[0]] == 0):
                count_enqueue[queue[0]] -= 1
                count_dequeue[queue[0]] -= 1
                queue.popleft()
            if len(queue):
                count_enqueue[queue[0]] -= 1
                print(queue.popleft())
            else:
                print(-1)
        else: # leave
            count_dequeue[op[1]] += 1

if __name__ == "__main__":
    n, m = map(int, input().split())
    Solve(n, m)