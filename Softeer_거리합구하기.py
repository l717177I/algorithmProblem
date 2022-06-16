import sys
sys.setrecursionlimit(10 ** 6)
# input = sys.stdin.readline


def dfs1(cur, par):  # current, parent
    subtreeSize[cur] = 1
    for i in range(len(nodes[cur])):
        child = nodes[cur][i][0]
        weight = nodes[cur][i][1]
        if child != par:
            dfs1(child, cur)
            distSum[cur] += distSum[child] + subtreeSize[child] * weight
            subtreeSize[cur] += subtreeSize[child]
    return


def dfs2(cur, par):
    for i in range(len(nodes[cur])):
        child = nodes[cur][i][0]
        weight = nodes[cur][i][1]
        if child != par:
            distSum[child] = distSum[cur] + weight * (n - (2 * subtreeSize[child]))
            dfs2(child, cur)


n = int(input())
subtreeSize = [0] * (n + 1)
nodes = [[] for _ in range(n + 1)]
distSum = [0] * (n + 1)
for _ in range(n - 1):
    x, y, t = map(int, input().split())
    nodes[x].append([y, t])
    nodes[y].append([x, t])

dfs1(1, 1)
dfs2(1, 1)
for d in distSum[1:]:
    print(d)
