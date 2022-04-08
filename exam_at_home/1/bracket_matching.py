#
# author: wang-yang
# email: tnst92002@gmail.com
#
N = int(input())

def check(s: str):
    st = []
    for c in s:
        if c == '(':
            st.append(')')
        elif c == '[':
            st.append(']')
        else:
            if len(st) == 0 or st[-1] != c:
                return False
            st.pop()
    return len(st) == 0

for _ in range(N):
    s = input()
    st = []
    print("Yes" if check(s) else "No")