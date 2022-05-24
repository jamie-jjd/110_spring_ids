# author: jamie
# email: jinjiedeng.jjd@gmail.com
if __name__ == "__main__":
    N = input()
    m, k = map(int, input().split())
    table = {}
    for i in range(len(N) - k + 1):
      key = N[i:i+k]
      if table.get(key) is None: table[key] = 0
      table[key] += 1
    for _ in range(m):
        B = input()
        print(0 if table.get(B) is None else table[B])

# author: jamie
# email: jinjiedeng.jjd@gmail.com
if __name__ == "__main__":
    N = input()
    m, k = map(int, input().split())
    table = {}
    key = 0
    for i, b in enumerate(N):
        # this is equivalent to key = ((key * 2) + (N[i] - '0')) % 2^k
        key = ((key << 1) | (ord(b) - ord('0'))) & ((1 << k) - 1)
        if i >= k - 1:
            if table.get(key) is None: table[key] = 0
            table[key] += 1
    for _ in range(m):
        key = 0
        B = input()
        for b in B: key = (key << 1) | (ord(b) - ord('0'))
        print(0 if table.get(key) is None else table[key])