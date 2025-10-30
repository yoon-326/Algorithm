import sys
from collections import deque
input = sys.stdin.readline

n = int(input().strip())
graph = [[] for _ in range(n + 1)]

for _ in range(n - 1):
    a, b, w = map(int, input().split())
    graph[a].append((b, w))
    graph[b].append((a, w))

node_a, _ = bfs(1, graph, n)

_, diameter = bfs(node_a, graph, n)

print(diameter)


def bfs(start, graph, n):
    dist = [-1] * (n + 1)
    dist[start] = 0
    q = deque([start])

    while q:
        now = q.popleft()
        for nxt, w in graph[now]:
            if dist[nxt] == -1:
                dist[nxt] = dist[now] + w
                q.append(nxt)

    far_node = 1
    max_dist = 0
    for node in range(1, n + 1):
        if dist[node] > max_dist:
            max_dist = dist[node]
            far_node = node
    return far_node, max_dist