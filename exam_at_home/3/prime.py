# author: jamie
# email: jinjiedeng.jjd@gmail.com
from collections import deque

def CreatePrimeTable ():
    is_prime = [True for i in range(10000)]
    is_prime[0] = is_prime[1] = False
    for i in range(2, 10000):
        if is_prime[i]:
            for multiple in range(i * i, len(is_prime), i):
                is_prime[multiple] = False
    return is_prime

def MinStep (is_prime, p, q):
    queue, distance = deque(), [len(is_prime)] * len(is_prime)
    queue.append(p)
    distance[p] = 0
    while len(queue):
        u = queue.popleft()
        if u == q: return distance[u]
        for exponent in range(4):
            prefix_base, base = 10 ** (exponent + 1), 10 ** exponent
            prefix, suffix = (u // prefix_base) * prefix_base, u % base
            digit = (u % prefix_base) // base
            for d in range(10):
                if d != digit and not (exponent == 3 and d == 0):
                    v = prefix + d * base + suffix
                    if is_prime[v] and distance[u] + 1 < distance[v]:
                        queue.append(v)
                        distance[v] = distance[u] + 1
    return -1

if __name__ == "__main__":
    T = int(input())
    is_prime = CreatePrimeTable()
    for _ in range(T):
        p, q = map(int, input().split())
        min_step = MinStep(is_prime, p, q)
        print("Impossible" if min_step == -1 else min_step)