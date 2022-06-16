import sys
from collections import deque
fastin = sys.stdin.readline

# (0) input, parameter
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

h, w = map(int, fastin().split())
pic = [list(map(int, fastin().split())) for _ in range(h)]
q = int(fastin())


# (1) BFS
def bfs(sx, sy):
    global pic
    visited = [[False] * w for _ in range(h)]
    q = deque()
    pixels = [[sx, sy]]
    q.append([sx, sy])
    visited[sx][sy] = True
    while q:
        x, y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < h and 0 <= ny < w:
                if not visited[nx][ny] and pic[nx][ny] == pic[x][y]:
                    visited[nx][ny] = True
                    q.append([nx, ny])
                    pixels.append([nx, ny])
    return pixels


# (2) 색칠 함수
def coloring_pic(pix, c):
    for p in pix:
        pic[p[0]][p[1]] = c


for _ in range(q):
    i, j, c = map(int, fastin().split())
    # coloring.append([i-1, j-1, c])
    if pic[i-1][j-1] == c: continue
    else:
        Pixel = bfs(i-1, j-1)
        coloring_pic(Pixel, c)


for i in range(h):
    for j in range(w):
        print(pic[i][j], end = " ")
    print()
