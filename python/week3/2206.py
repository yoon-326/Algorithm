import sys
from collections import deque
input = sys.stdin.readline

def bfs():
    q = deque()
    # r, c, broken, dist
    q.append((0, 0, 0))
    visited[0][0][0] = 1

    while q:
        r, c, broken = q.popleft()

        if r == n - 1 and c == m - 1:
            return visited[r][c][broken]

        for dr, dc in ((1,0),(-1,0),(0,1),(0,-1)):
            nr = r + dr
            nc = c + dc

            if 0 <= nr < n and 0 <= nc < m:
                if grid[nr][nc] == 0 and visited[nr][nc][broken] == 0:
                    visited[nr][nc][broken] = visited[r][c][broken] + 1
                    q.append((nr, nc, broken))

                elif grid[nr][nc] == 1 and broken == 0 and visited[nr][nc][1] == 0:
                    # 부수고 간다
                    visited[nr][nc][1] = visited[r][c][0] + 1
                    q.append((nr, nc, 1))

    return -1


n, m = map(int, input().split())
grid = [list(map(int, list(input().strip()))) for _ in range(n)]

# visited[r][c][0 or 1]
visited = [[[0]*2 for _ in range(m)] for __ in range(n)]

print(bfs())
