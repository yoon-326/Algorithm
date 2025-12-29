import sys
input = sys.stdin.readline

board = [list(map(int, list(input().strip()))) for _ in range(9)]
zeros = []

row_check = [[False] * 10 for _ in range(9)]
col_check = [[False] * 10 for _ in range(9)]
box_check = [[False] * 10 for _ in range(9)]

for i in range(9):
    for j in range(9):
        if board[i][j] == 0:
            zeros.append((i, j))
        else:
            num = board[i][j]
            box_idx = (i // 3) * 3 + (j // 3)
            row_check[i][num] = True
            col_check[j][num] = True
            box_check[box_idx][num] = True

def dfs(idx):
    if idx == len(zeros):
        for row in board:
            print("".join(map(str, row)))
        sys.exit(0)

    r, c = zeros[idx]
    box_idx = (r // 3) * 3 + (c // 3)

    for num in range(1, 10):
        if not row_check[r][num] and not col_check[c][num] and not box_check[box_idx][num]:
            
            row_check[r][num] = True
            col_check[c][num] = True
            box_check[box_idx][num] = True
            board[r][c] = num

            dfs(idx + 1)

            row_check[r][num] = False
            col_check[c][num] = False
            box_check[box_idx][num] = False
            board[r][c] = 0

dfs(0)