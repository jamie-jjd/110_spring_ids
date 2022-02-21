#
# author: Wang-Yang
# email: tnst92002@gmail.com
#
from bisect import *

N = int(input())
A = map(int, input().split())
M = int(input())

A = sorted(A)
for _ in range(M):
    op, v = map(int, input().split())
    if op == 1:
        i = bisect_left(A, v)
        print(1 if i != len(A) and A[i] == v else 0)
    elif op == 2:
        i = bisect_left(A, v)
        print(A[i-1] if i else 0)
    elif op == 3:
        i = bisect_right(A, v)
        print(A[i] if i != len(A) else 0)