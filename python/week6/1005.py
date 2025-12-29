import sys
from collections import deque

input = sys.stdin.readline

def solve():
    T = int(input())

    for _ in range(T):
        N, K = map(int, input().split())
        times = [0] + list(map(int, input().split()))
        graph = [[] for _ in range(N + 1)]
        indegree = [0] * (N + 1)
        dp = [0] * (N + 1)

        for _ in range(K):
            a, b = map(int, input().split())
            graph[a].append(b)
            indegree[b] += 1

        w = int(input())

        q = deque()
        for i in range(1, N + 1):
            dp[i] = times[i]
            if indegree[i] == 0:
                q.append(i)

        while q:
            now = q.popleft()

            for next_node in graph[now]:
                dp[next_node] = max(dp[next_node], dp[now] + times[next_node])
                indegree[next_node] -= 1
                if indegree[next_node] == 0:
                    q.append(next_node)

        print(dp[w])

if __name__ == "__main__":
    solve()