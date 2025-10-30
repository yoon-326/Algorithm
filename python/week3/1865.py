import sys
input = sys.stdin.readline

INF = int(1e9)

def bellman_ford(n, edges):
    dist = [0] * (n + 1)

    for i in range(1, n + 1):
        for s, e, t in edges:
            if dist[e] > dist[s] + t:
                dist[e] = dist[s] + t
                if i == n:
                    return True
    return False


T = int(input())
for _ in range(T):
    n, m, w = map(int, input().split())
    edges = []

    for _ in range(m):
        s, e, t = map(int, input().split())
        edges.append((s, e, t))
        edges.append((e, s, t))

    for _ in range(w):
        s, e, t = map(int, input().split())
        edges.append((s, e, -t))

    if bellman_ford(n, edges):
        print("YES")
    else:
        print("NO")
