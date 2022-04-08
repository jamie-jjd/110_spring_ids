#
# author: jamie
# email: jinjiedeng.jjd@gmail.com
#
from collections import deque

def Solve (A, B, S):
    while len(A):
        S.append(A[0])
        A.popleft()
        while len(S) and (S[0] == B[0] or S[-1] == B[0]):
            if S[0] == B[0]:
                S.popleft()
                B.popleft()
            elif len(S) and S[-1] == B[0]:
                S.pop()
                B.popleft()
    print("NO" if len(B) else "YES")

if __name__ == "__main__":
    m = int(input())
    for _ in range(m):
        n = int(input())
        A = deque(map(int, input().split()))
        B = deque(map(int, input().split()))
        S = deque()
        Solve(A, B, S)