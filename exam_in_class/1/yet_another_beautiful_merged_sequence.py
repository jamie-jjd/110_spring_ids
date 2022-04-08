#
# author: redleaf
# email: redleaf23477@gapp.nthu.edu.tw
#
def sol1():
    n, m = map(int, input().split())
    A, B = [], []
    for _ in range(n):
        x, y = map(int, input().split())
        A.append((x, y))
    for _ in range(m):
        x, y = map(int, input().split())
        B.append((x, y))

    ans, i, j = n + m, 0, 0
    while i < n and j < m:
        if A[i][0] < B[j][0]:
            if A[i][1] <= B[j][1]:
                ans -= 1
            i += 1
        elif A[i][0] == B[j][0]:
            if A[i][1] <= B[j][1]:
                i += 1
            else:
                j += 1
            ans -= 1
        else:
            if B[j][1] <= A[i][1]:
                ans -= 1
            j += 1
    print(ans)

if __name__=='__main__':
    sol1()