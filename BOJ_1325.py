# 효율적인 해킹
# Pypy3으로 채점
import sys
from collections import deque
fastin = sys.stdin.readline


def bfs(start):
    q = deque()
    q.append(start)
    visited = [False for _ in range(n + 1)]
    visited[start] = True
    cnt = 1
    while q:
        s = q.popleft()
        for i in graph[s]:
            if not visited[i]:
                visited[i] = True
                cnt += 1
                q.append(i)

    return cnt


n, m = map(int, fastin().split())
graph = [[] for _ in range(n + 1)]
for i in range(m):
    a, b = map(int, fastin().split())
    graph[b].append(a)
answer = []
max_cnt = 0
for i in range(1, n+1):
    tmp = bfs(i)
    if max_cnt == tmp:
        answer.append(i)
    if max_cnt < tmp:
        max_cnt = tmp
        answer = []
        answer.append(i)


answer.sort()
for a in answer:
    print(a, end = " ")
