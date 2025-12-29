import sys

# 입력 속도 향상을 위해 sys.stdin.readline 사용
input = sys.stdin.readline

def solve():
    # 1. 입력 받기
    s1 = input().strip()
    s2 = input().strip()
    
    len1 = len(s1)
    len2 = len(s2)
    
    # 2. DP 테이블 초기화 (행: len1+1, 열: len2+1)
    # 인덱스 계산 편의를 위해 0번째 행/열을 패딩으로 둠
    dp = [[0] * (len2 + 1) for _ in range(len1 + 1)]
    
    # 3. DP 테이블 채우기 (LCS 길이 계산)
    for i in range(1, len1 + 1):
        for j in range(1, len2 + 1):
            # 문자가 같은 경우 (현재 인덱스는 i-1, j-1 임을 주의)
            if s1[i-1] == s2[j-1]:
                dp[i][j] = dp[i-1][j-1] + 1
            # 문자가 다른 경우
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])
                
    # 첫 번째 출력: LCS 길이
    print(dp[len1][len2])
    
    # 4. 역추적 (LCS 문자열 찾기)
    result = []
    i, j = len1, len2
    
    # 길이가 0이 아닐 때만 역추적 수행
    while i > 0 and j > 0:
        # 1) 두 문자가 같아서 LCS에 포함된 경우
        if s1[i-1] == s2[j-1]:
            result.append(s1[i-1])
            i -= 1
            j -= 1
        # 2) 위쪽 값과 같다면 위로 이동
        elif dp[i-1][j] == dp[i][j]:
            i -= 1
        # 3) 왼쪽 값과 같다면 왼쪽으로 이동
        else:
            j -= 1
            
    # 두 번째 출력: 구해진 문자를 역순으로 출력
    if result:
        print("".join(result[::-1]))

if __name__ == "__main__":
    solve()