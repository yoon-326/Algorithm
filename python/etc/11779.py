import sys
import heapq

input = sys.stdin.readline
INF = int(1e9)

N = int(input())
M = int(input())

graph = [[] for _ in range(N + 1)]
for _ in range(M):
    u, v, w = map(int, input().split())
    graph[u].append((w, v))

start, end = map(int, input().split())

distance = [INF] * (N + 1)
path_parent = [0] * (N + 1)
pq = []

distance[start] = 0
heapq.heappush(pq, (0, start))

while pq:
    dist, now = heapq.heappop(pq)

    if dist > distance[now]:
        continue

    for cost, next_node in graph[now]:
        new_cost = dist + cost
        if new_cost < distance[next_node]:
            distance[next_node] = new_cost
            path_parent[next_node] = now
            heapq.heappush(pq, (new_cost, next_node))

path = []
current = end
while current != 0:
    path.append(current)
    current = path_parent[current]

path.reverse()

print(distance[end])
print(len(path))
print(*path)