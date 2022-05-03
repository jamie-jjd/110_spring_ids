# author: redleaf
# email: redleaf23477@gapp.nthu.edu.tw

def add(lhs, rhs): return lhs + rhs
def sub(lhs, rhs): return lhs - rhs
def mul(lhs, rhs): return lhs * rhs
def div(lhs, rhs): return int(lhs / rhs)

def calc(s, op):
    rhs = s.pop()
    lhs = s.pop()
    o = op.pop()
    if o == '+':
        lhs = add(lhs, rhs)
    elif o == '-':
        lhs = sub(lhs, rhs)
    elif o == '*':
        lhs = mul(lhs, rhs)
    elif o == '/':
        lhs = div(lhs, rhs)
    s.append(lhs)

def solve(expr):
    val = {k : v for k, v in zip(['A', 'B', 'C', 'D', 'E'], map(int, input().split()))}
    pri = {'(': 0, '+': 1, '-': 1, '*': 5, '/': 5}
    s, op = [], []
    for ch in expr:
        if ch in ['A', 'B', 'C', 'D', 'E']:
            s.append(val[ch])
        else:
            if ch == ')':
                while op[-1] != '(':
                    calc(s, op)
                op.pop()
            elif ch == '(':
                op.append(ch)
            else:
                while len(op) > 0 and pri[ch] <= pri[op[-1]]:
                    calc(s, op)
                op.append(ch)
    while len(op) > 0:
        calc(s, op)
    print(s[-1])

if __name__=='__main__':
    expr = input()
    for _ in range(int(input())):
        solve(expr)