# author: jamie
# email: jinjiedeng.jjd@gmail.com
if __name__ == "__main__":
    n = int(input())
    string_set = set(input().split())
    q = int(input())
    for _ in range(q):
        op, string = input().split()
        if op == '1': # insert
            string_set.add(string)
            print(len(string_set))
        elif op == '2': # remove
            string_set.discard(string)
            print(len(string_set))
        elif op == '3': # is_member
            print("Yes" if string in string_set else "No")