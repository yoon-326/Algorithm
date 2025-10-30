import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

def dfs(row):
    global count
    if row == N:
        count += 1
        return

    for col in range(N):
        d1 = row + col
        d2 = row - col + N - 1
        if not col_used[col] and not diag1_used[d1] and not diag2_used[d2]:
            col_used[col] = True
            diag1_used[d1] = True
            diag2_used[d2] = True

            dfs(row + 1)

            col_used[col] = False
            diag1_used[d1] = False
            diag2_used[d2] = False


N = int(input())
count = 0

col_used = [False] * N
diag1_used = [False] * (2*N - 1)  # 오른쪽 아래 대각선
diag2_used = [False] * (2*N - 1)  # 왼쪽 아래 대각선

dfs(0)
print(count)
