#
# author: wang-yang
# email: tnst92002@gmail.com
#
from heapq import *

N, M = map(int, input().split())
v = list(map(int, input().split()))
for _ in range(1, N):
    pq = []
    w = list(map(int, input().split()))
    for e in v:
        heappush(pq, (e +  w[0], 0))
    for i in range(M):
        val, pos = heappop(pq)
        v[i] = val
        if pos + 1 < M:
            heappush(pq, (val-w[pos]+w[pos+1], pos+1))
print(' '.join(map(str, v)))

#
# author: jamie
# email: jinjiedeng.jjd@gmail.com
#
from heapq import *

n, m = map(int, input().split())
arrays = []
for i in range(n):
    arrays.append(list(map(int, input().split())))
    for j in range(m - 1, 0, -1):
        arrays[i][j] -= arrays[i][j - 1]
sum, count = 0, m
for i in range(n):
    sum += arrays[i][0]
prev_indexes, indexes, min_heap, sums = [-1] * n, [0] * n, [], []
heappush(min_heap, (sum, indexes))
while count:
    sum, indexes = heappop(min_heap)
    if prev_indexes != indexes:
        sums.append(sum)
        for i in range(n):
            indexes[i] += 1
            heappush(min_heap, (sum + arrays[i][indexes[i]], indexes[:]))
            indexes[i] -= 1
        prev_indexes = indexes
        count -= 1
print(" ".join(map(str, sums)))