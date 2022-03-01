# author: redleaf
# email: redleaf23477@gapp.nthu.edu.tw

def bubble(arr):
    ans = 0
    for _ in range(len(arr)):
        for i in range(1, len(arr)):
            if arr[i] < arr[i-1]:
                arr[i], arr[i-1] = arr[i-1], arr[i]
                ans += 1
    return ans

if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    print(bubble(arr))
