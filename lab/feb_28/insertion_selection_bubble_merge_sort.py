# author: jamie
# email: jinjiedeng.jjd@gmail.com
from typing import List

def MinIndex (array: List[int]):
    min_index = 0
    min = array[0]
    for i in range(1, len(array)):
        if array[i] < array[min_index]:
            min_index = i
    return min_index

def SelectionSort (array: List[int]):
    for begin in range(len(array) - 1):
        min_index = begin + MinIndex(array[begin:])
        array[begin], array[min_index] = array[min_index], array[begin]

# author: redleaf
# email: redleaf23477@gapp.nthu.edu.tw
def bubble(arr):
    for _ in range(len(arr)):
        for i in range(1, len(arr)):
            if arr[i] < arr[i-1]:
                arr[i], arr[i-1] = arr[i-1], arr[i]

def insertion(arr):
    for i in range(1, len(arr)):
        buff, j = arr[i], i - 1
        while j >= 0 and arr[j] > buff:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = buff

def dc(L, R, arr):
    if R - L <= 1: return 0

    M = L + (R - L) // 2
    dc(L, M, arr)
    dc(M, R, arr)
    i, j, buff = L, M, []
    while i < M and j < R:
        if arr[i] < arr[j]:
            buff.append(arr[i])
            i += 1
        else:
            buff.append(arr[j])
            j += 1
    buff.extend(arr[i:M])
    buff.extend(arr[j:R])
    arr[L:R] = buff