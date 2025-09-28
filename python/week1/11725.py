import sys
from collections import deque
input = sys.stdin.readline

n = int(input().strip())
g = [[] for _ in range(n+1)]
for _ in range(n-1):
    a,b = map(int, input().split())
    g[a].append(b)
    g[b].append(a)

parent = [0] * (n+1)
parent[1] = -1

q = deque([1])
while q:
    cur = q.popleft()
    for nxt in g[cur]:
        if parent[nxt] == 0:
            parent[nxt] = cur
            q.append(nxt)

print("\n".join(map(str, parent[2:])))