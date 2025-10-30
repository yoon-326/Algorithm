import sys
import heapq
input = sys.stdin.readline
INF = int(1e9)

def dijkstra(start, graph, n):
    dist = [INF] * (n + 1)
    dist[start] = 0
    pq = [(0, start)]

    while pq:
        cost, now = heapq.heappop(pq)
        if cost > dist[now]:
            continue
        for nxt, w in graph[now]:
            new_cost = cost + w
            if new_cost < dist[nxt]:
                dist[nxt] = new_cost
                heapq.heappush(pq, (new_cost, nxt))
    return dist


def main():
    n, m, x = map(int, input().split())

    graph = [[] for _ in range(n + 1)]
    reverse_graph = [[] for _ in range(n + 1)]

    for _ in range(m):
        a, b, t = map(int, input().split())
        graph[a].append((b, t))
        reverse_graph[b].append((a, t))

    dist_from_x = dijkstra(x, graph, n)

    dist_to_x = dijkstra(x, reverse_graph, n)

    answer = 0
    for i in range(1, n + 1):
        total = dist_to_x[i] + dist_from_x[i]
        if total < INF:
            answer = max(answer, total)

    print(answer)


if __name__ == "__main__":
    main()
