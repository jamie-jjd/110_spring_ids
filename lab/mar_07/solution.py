#
# author: redleaf
# email: redleaf23477@gapp.nthu.edu.tw
#
import heapq

n = int(input())
A = [(-x, x) for x in map(int, input().split())]
B = [(x, x) for x in map(int, input().split())]
heapq.heapify(A)
heapq.heapify(B)

for _ in range(n):
    (ka, a), (kb, b) = heapq.heappop(A), heapq.heappop(B)
    print(a, b)
    a, b = a - a // 2, b + a // 2
    heapq.heappush(A, (-a, a))
    heapq.heappush(B, (b, b))

print(abs(heapq.heappop(A)[1] - heapq.heappop(B)[1]))
