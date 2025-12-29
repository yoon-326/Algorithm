import sys

input = sys.stdin.readline
INF = float('inf')

n = int(input())
w = [list(map(int, input().split())) for _ in range(n)]

# dp[current_node][visited_bitmask]
# -1로 초기화하여 방문 여부를 확인 (0은 비용일 수 없지만, 계산된 값이 0일 순 없으므로 구분 가능)
dp = [[-1] * (1 << n) for _ in range(n)]

def dfs(cur, mask):
    # 모든 도시를 방문한 경우 (mask가 모든 비트가 1일 때)
    if mask == (1 << n) - 1:
        # 현재 도시에서 시작 도시(0번)로 돌아갈 수 있는지 확인
        if w[cur][0] == 0:
            return INF
        else:
            return w[cur][0]

    # 이미 계산한 적이 있는 상태라면 저장된 값 반환 (Memoization)
    if dp[cur][mask] != -1:
        return dp[cur][mask]

    min_cost = INF
    
    # 다음 도시 탐색
    for next_node in range(n):
        # 1. 길이 존재하고 (w[cur][next_node] != 0)
        # 2. 아직 방문하지 않은 도시라면 (mask & (1 << next_node) == 0)
        if w[cur][next_node] != 0 and not (mask & (1 << next_node)):
            cost = dfs(next_node, mask | (1 << next_node)) + w[cur][next_node]
            min_cost = min(min_cost, cost)

    dp[cur][mask] = min_cost
    return min_cost

# 0번 도시에서 시작, 방문 기록 1(2^0)로 시작
print(dfs(0, 1))