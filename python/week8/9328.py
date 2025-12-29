import sys
from collections import deque

input = sys.stdin.readline

dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

def solve():
    h, w = map(int, input().split())
    grid = ['.' * (w + 2)]
    for _ in range(h):
        grid.append('.' + input().strip() + '.')
    grid.append('.' * (w + 2))

    visited = [[False] * (w + 2) for _ in range(h + 2)]
    keys = [False] * 26
    
    k_str = input().strip()
    if k_str != '0':
        for k in k_str:
            keys[ord(k) - ord('a')] = True

    count = 0
    q = deque([(0, 0)])
    visited[0][0] = True
    
    doors = [deque() for _ in range(26)]

    while q:
        x, y = q.popleft()

        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]

            if 0 <= nx < h + 2 and 0 <= ny < w + 2 and not visited[nx][ny]:
                cell = grid[nx][ny]
                
                if cell == '*':
                    continue
                
                visited[nx][ny] = True
                
                if cell == '.':
                    q.append((nx, ny))
                elif cell == '$':
                    count += 1
                    q.append((nx, ny))
                elif 'A' <= cell <= 'Z':
                    door_idx = ord(cell) - ord('A')
                    if keys[door_idx]:
                        q.append((nx, ny))
                    else:
                        doors[door_idx].append((nx, ny))
                elif 'a' <= cell <= 'z':
                    q.append((nx, ny))
                    key_idx = ord(cell) - ord('a')
                    if not keys[key_idx]:
                        keys[key_idx] = True
                        while doors[key_idx]:
                            q.append(doors[key_idx].popleft())

    print(count)

t = int(input())
for _ in range(t):
    solve()