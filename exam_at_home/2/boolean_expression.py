# author: jamie
# email: jinjiedeng.jjd@gmail.com
def Priority (c):
    if   c == '&': return 3
    elif c == '|': return 2
    elif c == '^': return 1
    elif c == '(': return 0

def InfixToPostfix (infix, postfix):
    stack = []
    for c in infix:
        if c == '(':
            stack.append('(')
        elif c == ')':
            while stack[-1] != '(':
                postfix.append(stack.pop())
            stack.pop()
        elif c == '&' or c == '|' or c == '^':
            while len(stack) and Priority(c) <= Priority(stack[-1]):
                postfix.append(stack.pop())
            stack.append(c)
        else:
            postfix.append(c)
    while len(stack):
        postfix.append(stack.pop())

def Evaluate (postfix, value):
    stack = []
    for c in postfix:
        if c == '&' or c == '|' or c == '^':
            rhs = stack.pop()
            lhs = stack.pop()
            if   c == '&': stack.append(lhs & rhs)
            elif c == '|': stack.append(lhs | rhs)
            elif c == '^': stack.append(lhs ^ rhs)
        elif c == '1' or c == '0':
            stack.append(ord(c) - ord('0'))
        else:
            stack.append(value[ord(c) - ord('A')])
    return stack.pop()

if __name__ == "__main__":
    infix = input()
    T = int(input())
    for _ in range(T):
        value = list(map(int, input().split()))
        postfix = []
        InfixToPostfix(infix, postfix)
        print(Evaluate(postfix, value))