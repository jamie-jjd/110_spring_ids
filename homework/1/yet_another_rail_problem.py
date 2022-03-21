#
# author: redleaf
# email: redleaf@gapp.nthu.edu.tw
#
from collections import deque

def solve(n, arr):
    queue, a = deque(), 1
    for b in arr:
        if len(queue) != 0 and b == queue[0]:
            queue.popleft()
        else:
            while a != b:
                queue.append(a)
                a += 1
                if a > n: return False
            a += 1
    return True

if __name__ == '__main__':
    for _ in range(int(input())):
        n = int(input())
        arr = list(map(int, input().split()))
        print("YES" if solve(n, arr) else "NO")