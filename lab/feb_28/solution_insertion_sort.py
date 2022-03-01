# author: redleaf
# email: redleaf23477@gapp.nthu.edu.tw

def insertion(arr):
    ans = 0
    for i in range(1, len(arr)):
        buff, j = arr[i], i - 1
        while j >= 0 and arr[j] > buff:
            arr[j + 1] = arr[j]
            ans += 1
            j -= 1
        arr[j + 1] = buff
    return ans

if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    print(insertion(arr))