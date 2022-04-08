#
# author: jamie
# email: jinjiedeng.jjd@gmail.com
#
import heapq

def Solve (n, k, revenues):
    min_heap_k = []
    min_heap_2k = []
    for revenue in revenues[:k]:
        heapq.heappush(min_heap_k, revenue)
    for revenue in revenues[k:2 * k]:
        heapq.heappush(min_heap_2k, (heapq.heappushpop(min_heap_k, revenue)))
    print(min_heap_k[0], min_heap_2k[0])
    for revenue in revenues[2 * k:]:
        if min_heap_k[0] < revenue:
            heapq.heappushpop(min_heap_2k, heapq.heappushpop(min_heap_k, revenue))
        elif min_heap_2k[0] < revenue:
            heapq.heappushpop(min_heap_2k, revenue)
        print(min_heap_k[0], min_heap_2k[0])

if __name__ == '__main__':
    n = int(input())
    k = int(input())
    revenues = list(map(int, input().split()))
    Solve(n, k, revenues)