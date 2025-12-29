import sys

input = sys.stdin.readline
MOD = 1_000_000_000

n = int(input())

# dp[길이][마지막_숫자][사용_숫자_비트마스크]
# 길이: 1 ~ N
# 마지막 숫자: 0 ~ 9
# 비트마스크: 0000000000(0) ~ 1111111111(1023)
dp = [[[0] * 1024 for _ in range(10)] for _ in range(n + 1)]

# 초기화: 길이가 1일 때는 1~9만 가능 (0으로 시작 불가능)
for i in range(1, 10):
    dp[1][i][1 << i] = 1

# DP 수행
for length in range(1, n):
    for last in range(10):
        for mask in range(1024):
            # 현재 상태에 값이 있다면 다음 단계로 전이
            if dp[length][last][mask] > 0:
                current_count = dp[length][last][mask]
                
                # 1. last - 1 (0보다 큰 경우만)
                if last > 0:
                    next_digit = last - 1
                    next_mask = mask | (1 << next_digit)
                    dp[length + 1][next_digit][next_mask] = (dp[length + 1][next_digit][next_mask] + current_count) % MOD
                
                # 2. last + 1 (9보다 작은 경우만)
                if last < 9:
                    next_digit = last + 1
                    next_mask = mask | (1 << next_digit)
                    dp[length + 1][next_digit][next_mask] = (dp[length + 1][next_digit][next_mask] + current_count) % MOD

# 정답 계산: 길이가 N이고, 마지막 숫자는 상관없으며, 비트마스크가 1023(모든 숫자 사용)인 경우의 합
ans = 0
for i in range(10):
    ans = (ans + dp[n][i][1023]) % MOD

print(ans)