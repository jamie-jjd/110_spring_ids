#
# author: redleaf
# email: redleaf@gapp.nthu.edu.tw
#
import heapq
def KthElements(k, n, a):
    a = [-x for x in a]
    heap = a[0:k]

    heapq.heapify(heap)
    ans = [-heap[0]]

    for i in a[k:]:
        heapq.heappushpop(heap, i)
        ans.append(-heap[0])

    return ans

if __name__ == '__main__':

    n, k = map(int, input().split())
    arr = list(map(int, input().split()))

    res = KthElements(k, n, arr)
    print(*res)

