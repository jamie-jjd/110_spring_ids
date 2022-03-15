#
# author: wang-yang
# email: tnst92002@gmail.com
#
from collections import deque

n = int(input())
m = int(input())

dq = [deque() for _ in range(n+1)]
for _ in range(m):
    op, i, j, *k = map(int, input().split())
    k = k[0] if k else None
    if op == 0:
        if j == 0:
            dq[k].append(i)
        else:
            dq[k].appendleft(i)
    else:
        if i == 0:
            val = dq[j].pop()
        else:
            val = dq[j].popleft()
        print(val)

#
# author: redleaf
# email: redleaf23477@gapp.nthu.edu.tw
#
from collections import deque

n = int(input())
m = int(input())

deq = [deque() for _ in range(n)]

for _ in range(m):
    ops = list(map(int, input().split()))
    if ops[0] == 0:
        op, i, j, k = ops
        if j == 0:
            deq[k-1].appendleft(i)
        else:
            deq[k-1].append(i)
    else:
        op, j, k = ops
        if j == 0:
            print(deq[k-1].popleft())
        else:
            print(deq[k-1].pop())
