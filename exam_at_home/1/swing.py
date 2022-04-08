#
# author: wang-yang
# email: tnst92002@gmail.com
#
N = int(input())

def run(s: str):
    res = []
    cnt = [0] * 26
    for c in s:
        cnt[c] += 1
    order = 0
    while True:
        end = True
        if order == 0 :
            for i in range(26):
                if cnt[i] != 0:
                    end = False
                    cnt[i] = cnt[i] - 1
                    res.append(i)
        else:
            for i in range(25, -1, -1):
                if cnt[i] != 0:
                    end = False
                    cnt[i] = cnt[i] - 1
                    res.append(i)
        order = 1 - order
        if end:
            break
    return res

for _ in range(N):
    len, *arr = map(int, input().split())
    res = run(arr)
    print(' '.join(map(str,res)))