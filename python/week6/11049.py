import sys

# 입력을 한 번에 다 읽어서 처리 (I/O 속도 최적화)
def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return

    iterator = iter(input_data)
    n = int(next(iterator))

    # 행렬 차원 파싱
    # p 배열: [행렬0_행, 행렬0_열, 행렬1_열, ..., 행렬N-1_열]
    p = [0] * (n + 1)
    p[0] = int(next(iterator)) # 첫 행렬 행
    p[1] = int(next(iterator)) # 첫 행렬 열
    
    for i in range(2, n + 1):
        next(iterator) # i번째 행렬의 행(이전 열과 같으므로 버림)
        p[i] = int(next(iterator)) # i번째 행렬의 열

    # dp[i][j]: i번 행렬부터 j번 행렬까지의 최소 곱셈 비용
    dp = [[0] * n for _ in range(n)]

    # 대각선 방향으로 DP 테이블 채우기
    # length: 곱하는 행렬의 개수 (2개부터 N개까지)
    for length in range(2, n + 1):
        for i in range(n - length + 1):
            j = i + length - 1
            
            # 루프 내에서 자주 쓰이는 값 지역 변수로 할당 (속도 최적화)
            p_i = p[i]
            p_j1 = p[j+1]
            
            # k가 i일 때의 초기값 (첫 번째 분할 경우의 수)
            # (A_i) * (A_i+1 ... A_j)
            min_val = dp[i+1][j] + p_i * p[i+1] * p_j1
            
            # 나머지 k (i+1 ~ j-1)에 대해 최소 비용 갱신
            # min() 함수 대신 if문을 사용하여 함수 호출 오버헤드 제거
            for k in range(i + 1, j):
                cost = dp[i][k] + dp[k+1][j] + p_i * p[k+1] * p_j1
                if cost < min_val:
                    min_val = cost
            
            dp[i][j] = min_val

    print(dp[0][n-1])

if __name__ == '__main__':
    solve()