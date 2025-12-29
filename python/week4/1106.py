import sys
input = sys.stdin.readline

C, N = map(int, input().split())
cities = []
for _ in range(N):
    cities.append(list(map(int, input().split())))

dp_size = C + 101
INF = int(1e9)
dp = [INF] * dp_size
dp[0] = 0

for cost, customers in cities:
    for i in range(customers, dp_size):
        dp[i] = min(dp[i], dp[i - customers] + cost)

answer = min(dp[C:])
print(answer)