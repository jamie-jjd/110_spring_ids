#
# author: redleaf
# email: redleaf@gapp.nthu.edu.tw
#
from collections import deque

def push(mylist, buff, cursor):
    if cursor == '[':
        mylist.extendleft(reversed(buff))
    else:
        mylist.extend(buff)

def solve(s):
    mylist, buff, cursor = deque(), [], ']'
    for ch in s:
        if ch == '[' or ch == ']':
            push(mylist, buff, cursor)
            cursor = ch
            buff = []
        else:
            buff.append(ch)
    push(mylist, buff, cursor)
    print(*mylist, sep='')

if __name__ == '__main__':
    for _ in range(int(input())):
        solve(input())