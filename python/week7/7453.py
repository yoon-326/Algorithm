import sys

# 입력 속도 향상을 위한 설정
input = sys.stdin.readline

def solve():
    n = int(input())
    
    # 4개의 배열 입력 받기
    # A, B, C, D 배열을 전치(Transpose)하여 각 리스트로 분리
    arr = [list(map(int, input().split())) for _ in range(n)]
    ab = []
    cd = []
    
    # 각 배열 분리
    A = [row[0] for row in arr]
    B = [row[1] for row in arr]
    C = [row[2] for row in arr]
    D = [row[3] for row in arr]
    
    # A와 B의 모든 합을 카운팅 (딕셔너리 사용)
    # ab_dict = { 합 : 등장 횟수 }
    ab_dict = {}
    for i in range(n):
        for j in range(n):
            s = A[i] + B[j]
            if s in ab_dict:
                ab_dict[s] += 1
            else:
                ab_dict[s] = 1
    
    ans = 0
    
    # C와 D의 모든 합을 구하고, 그 합의 부호를 바꾼 값이 ab_dict에 있는지 확인
    for i in range(n):
        for j in range(n):
            target = -(C[i] + D[j])
            if target in ab_dict:
                ans += ab_dict[target]
                
    print(ans)

if __name__ == '__main__':
    solve()