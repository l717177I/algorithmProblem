import sys
from collections import deque

fastin = sys.stdin.readline
nums = [[1, 1, 1, 0, 1, 1, 1],
        [0, 0, 1, 0, 0, 1, 0],
        [1, 0, 1, 1, 1, 0, 1],
        [1, 0, 1, 1, 0, 1, 1],
        [0, 1, 1, 1, 0, 1, 0],
        [1, 1, 0, 1, 0, 1, 1],
        [1, 1, 0, 1, 1, 1, 1],
        [1, 1, 1, 0, 0, 1, 0],
        [1, 1, 1, 1, 1, 1, 1],
        [1, 1, 1, 1, 0, 1, 1]
        ]


def func(x):
    n = 0
    for i in range(len(x)):
        t = nums[int(x[i])]
        # print(x)
        n += sum(t)
    return n


def change(x, y):
    cnt = 0
    for i in range(7):
        tmp = 2 * x[i] - y[i]
        if tmp == 0 or tmp == 1:
            continue
        else:
            cnt += 1
    return cnt


t = int(input())

for _ in range(t):
    result = 0
    A, B = input().split()
    x = len(B)
    if len(A) > len(B):
        n = len(A) - len(B)
        result += func(A[:n])
        A = A[n:]
    elif len(A) < len(B):
        n = len(B) - len(A)
        result += func(B[:n])
        B = B[n:]
        x = len(A)
    if A != B:
        for i in range(x):
            a, b = int(A[i]), int(B[i])
            result += change(nums[a], nums[b])

    print(result)
