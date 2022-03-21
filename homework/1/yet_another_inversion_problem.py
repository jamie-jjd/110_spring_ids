#
# author: redleaf
# email: redleaf@gapp.nthu.edu.tw
#
def solve1(A, B, C):
    a, b, c, ans = 0, 0, 0, 0
    while a < len(A) and b < len(B) and c < len(C):
        if B[b] < A[a] and B[b] < C[c]:
            ans += (len(A) - a) * (len(C) - c)
            b += 1
        elif A[a] < C[c]:
            a += 1
        else:
            c += 1
    return ans

if __name__ == '__main__':
    na, nb, nc = map(int, input().split())
    A = sorted(list(map(int, input().split())))
    B = sorted(list(map(int, input().split())))
    C = sorted(list(map(int, input().split())))
    print(solve1(A, B, C))