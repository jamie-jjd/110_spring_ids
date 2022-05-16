# author: jamie
# email: jinjiedeng.jjd@gmail.com
from collections import deque

def Reconstruct (post_order, first_post, last_post, in_order, first_in, last_in, pre_order):
    if first_post <= last_post:
        pre_order.append(post_order[last_post])
        middle_in = in_order.index(post_order[last_post])
        middle_post = first_post + (middle_in - first_in)
        Reconstruct(post_order, first_post, middle_post - 1, in_order, first_in, middle_in - 1, pre_order)
        Reconstruct(post_order, middle_post, last_post - 1, in_order, middle_in + 1, last_in, pre_order)

### direct post- + to- to pre- order
if __name__ == "__main__":
    n = int(input())
    post_order = list(map(int, input().split()))
    in_order = list(map(int, input().split()))
    pre_order = deque()
    Reconstruct(post_order, 0, n - 1, in_order, 0, n - 1, pre_order)
    print(" ".join(map(str, pre_order)))

# author: jamie
# email: jinjiedeng.jjd@gmail.com
from collections import deque

def Reconstruct (pre_order, first_pre, last_pre, in_order, first_in, last_in, post_order):
    if first_pre <= last_pre:
        post_order.appendleft(pre_order[first_pre])
        middle_in = in_order.index(pre_order[first_pre])
        middle_pre = first_pre + (middle_in - first_in)
        Reconstruct(pre_order, middle_pre + 1, last_pre, in_order, middle_in + 1, last_in, post_order)
        Reconstruct(pre_order, first_pre + 1, middle_pre, in_order, first_in, middle_in - 1, post_order)

### reuse pre- + in- to post- order to achieve post- + in- to pre- order
if __name__ == "__main__":
    n = int(input())
    post_order = list(map(int, input().split()))
    post_order.reverse()
    in_order = list(map(int, input().split()))
    in_order.reverse()
    pre_order = deque()
    Reconstruct(post_order, 0, n - 1, in_order, 0, n - 1, pre_order)
    pre_order.reverse()
    print(" ".join(map(str, pre_order)))