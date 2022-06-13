# author: jamie
# email: jinjiedeng.jjd@gmail.com
if __name__ == "__main__":
    n = int(input())
    inverted_index = {}
    for i in range(n):
        m_i = int(input())
        document = input().split()
        for word in document:
            if word not in inverted_index:
                inverted_index[word] = set()
            inverted_index[word].add(i)
    q = int(input())
    for _ in range(q):
        word = input()
        print(0 if word not in inverted_index else len(inverted_index[word]))