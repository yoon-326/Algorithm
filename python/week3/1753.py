import sys, heapq # 우선순위 큐
input = sys.stdin.readline
INF = int(1e9)

V, E = map(int, input().split())
K = int(input())

graph = [[] for _ in range(V + 1)]
distance = [INF] * (V + 1)

for _ in range(E):
    u, v, w = map(int, input().split())
    graph[u].append((v, w))

# (x, y) 튜플 형태의 데이터는 첫 번째 요소를 기준으로 오름차순 정렬
q = []
heapq.heappush(q, (0, K))
distance[K] = 0

while q:
    dist, now = heapq.heappop(q)

    # 이미 더 짧은 경로로 방문한 적이 있으면 패스
    if distance[now] < dist:
        continue

    # 인접 노드 확인
    for nxt, cost in graph[now]:
        new_cost = dist + cost
        if new_cost < distance[nxt]:
            distance[nxt] = new_cost
            heapq.heappush(q, (new_cost, nxt))

# 결과 출력
for i in range(1, V + 1):
    print("INF" if distance[i] == INF else distance[i])
