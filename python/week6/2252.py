import sys
from collections import deque

# 입력 속도 향상
input = sys.stdin.readline

def solve():
    # N: 학생 수, M: 키 비교 횟수
    N, M = map(int, input().split())
    
    # 그래프(인접 리스트)와 진입 차수 테이블 초기화
    graph = [[] for _ in range(N + 1)]
    indegree = [0] * (N + 1)
    
    # 간선 정보 입력
    for _ in range(M):
        A, B = map(int, input().split())
        graph[A].append(B) # A가 B 앞에 서야 함
        indegree[B] += 1   # B의 진입 차수 증가
        
    # 위상 정렬 시작
    q = deque()
    
    # 진입 차수가 0인 학생(가장 앞에 설 수 있는 학생) 큐에 삽입
    for i in range(1, N + 1):
        if indegree[i] == 0:
            q.append(i)
            
    result = []
    
    while q:
        now = q.popleft()
        result.append(now)
        
        # 현재 학생 뒤에 서야 하는 학생들의 진입 차수 감소
        for next_node in graph[now]:
            indegree[next_node] -= 1
            # 새롭게 진입 차수가 0이 되면 큐에 삽입
            if indegree[next_node] == 0:
                q.append(next_node)
                
    # 결과 출력 (언패킹 연산자 *를 사용하여 공백 구분 출력)
    print(*result)

if __name__ == "__main__":
    solve()