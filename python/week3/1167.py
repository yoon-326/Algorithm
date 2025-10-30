import sys
from collections import deque
input = sys.stdin.readline

def bfs(start):
    dist = [-1] * (v + 1)
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
    for i in range(1, v + 1):
        if dist[i] > max_dist:
            max_dist = dist[i]
            far_node = i
    return far_node, max_dist


v = int(input())
graph = [[] for _ in range(v + 1)]

for _ in range(v):
    data = list(map(int, input().split()))
    node = data[0]
    idx = 1
    while data[idx] != -1:
        to_node = data[idx]
        weight = data[idx + 1]
        graph[node].append((to_node, weight))
        idx += 2

node_a, _ = bfs(1)

_, diameter = bfs(node_a)

print(diameter)
