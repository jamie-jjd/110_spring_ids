# author: redleaf
# email: redleaf23477@gapp.nthu.edu.tw

def dc(L, R, arr):
    if R - L <= 1: return 0

    M = L + (R - L) // 2
    ans = dc(L, M, arr) + dc(M, R, arr)
    i, j, buff = L, M, []
    while i < M and j < R:
        if arr[i] < arr[j]:
            buff.append(arr[i])
            i += 1
        else:
            buff.append(arr[j])
            j += 1
            ans += M - i
    buff.extend(arr[i:M])
    buff.extend(arr[j:R])
    arr[L:R] = buff
    return ans

if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    print(dc(0, n, arr))

