# author: jamie
# email: jinjiedeng.jjd@gmail.com
def LookupSymbolTable (symbol_table, rvalue):
    if rvalue[0] == '-' or rvalue[0].isdigit(): return int(rvalue)
    return 0 if rvalue not in symbol_table else symbol_table[rvalue]

if __name__ == "__main__":
    T = int(input())
    symbol_table = {}
    for _ in range(T):
        operation, lvalue, *rvalues = input().split()
        if operation == "print":
            print(0 if lvalue not in symbol_table else symbol_table[lvalue])
        else:
            if lvalue not in symbol_table: symbol_table[lvalue] = 0
            rvalue_0 = LookupSymbolTable(symbol_table, rvalues[0])
            rvalue_1 = LookupSymbolTable(symbol_table, rvalues[1])
            if operation == "add": symbol_table[lvalue] = rvalue_0 + rvalue_1
            if operation == "sub": symbol_table[lvalue] = rvalue_0 - rvalue_1
            if operation == "mul": symbol_table[lvalue] = rvalue_0 * rvalue_1
            if operation == "div": symbol_table[lvalue] = rvalue_0 // rvalue_1
            print(symbol_table[lvalue])