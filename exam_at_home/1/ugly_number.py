#
# author: wang-yang
# email: tnst92002@gmail.com
#
from heapq import *

ug = [0]
pq = [1]

while len(ug) <= 10000:
    v = heappop(pq)
    if v == ug[-1]:
        continue
    ug.append(v)
    heappush(pq, v*2)
    heappush(pq, v*3)
    heappush(pq, v*5)

N = int(input())
for _ in range(N):
    k = int(input())
    print(ug[k])

#
# author: jamie
# email: jinjiedeng.jjd@gmail.com
#
Q = int(input())
Ks = []
for _ in range(Q):
    Ks.append(int(input()))
max_k = max(k for k in Ks)
ugly_number = [0] * (max_k + 1)
i_2, i_3, i_5 = 1, 1, 1
ugly_number[1] = 1
for i in range(2, max_k + 1):
    x_2, x_3, x_5 = ugly_number[i_2] * 2, ugly_number[i_3] * 3, ugly_number[i_5] * 5
    ugly_number[i] = min(x for x in [x_2, x_3, x_5])
    if ugly_number[i] == x_2: i_2 += 1
    if ugly_number[i] == x_3: i_3 += 1
    if ugly_number[i] == x_5: i_5 += 1
for k in Ks:
    print(ugly_number[k])