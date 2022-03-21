#
# author: redleaf
# email: redleaf@gapp.nthu.edu.tw
#
def solve(n, arr):
    stack, a = [], 1
    for b in arr:
        while len(stack) == 0 or stack[-1] != b:
            if a > n: return False
            stack.append(a)
            a += 1
        stack.pop()
    return True

if __name__ == '__main__':
    for _ in range(int(input())):
        n = int(input())
        arr = list(map(int, input().split()))
        print("YES" if solve(n, arr) else "NO")