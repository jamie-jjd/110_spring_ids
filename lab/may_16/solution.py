# author: jamie
# email: jinjiedeng.jjd@gmail.com

if __name__ == "__main__":
    n, k = map(int, input().split())
    S = list(map(int, input().split()))
    D = {}
    U = []
    for i in range(k):
        if D.get(S[i]) is None: D[S[i]] = 0
        D[S[i]] += 1
    U.append(len(D))
    for i in range(k, n):
        D[S[i - k]] -= 1
        if D[S[i - k]] == 0: D.pop(S[i - k])
        if D.get(S[i]) is None: D[S[i]] = 0
        D[S[i]] += 1
        U.append(len(D))
    print(" ".join(map(str, U)))