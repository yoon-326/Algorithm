import sys

input = sys.stdin.readline

def solve():
    N = int(input())
    nums = list(map(int, input().split()))
    M = int(input())

    dp = [[0] * N for _ in range(N)]

    for i in range(N):
        dp[i][i] = 1

    for i in range(N - 1, -1, -1):
        for j in range(i + 1, N):
            if nums[i] == nums[j]:
                if j == i + 1:
                    dp[i][j] = 1
                elif dp[i+1][j-1] == 1:
                    dp[i][j] = 1

    for _ in range(M):
        s, e = map(int, input().split())
        print(dp[s-1][e-1])

if __name__ == "__main__":
    solve()