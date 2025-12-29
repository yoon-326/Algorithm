import sys
from collections import deque

# 입력 속도 향상
input = sys.stdin.readline

def solve():
    # 1. 입력 받기
    # N: 가수의 수, M: 보조 PD의 수
    N, M = map(int, input().split())
    
    # 진입 차수 리스트 (0번 인덱스는 사용 안 함)
    indegree = [0] * (N + 1)
    
    # 각 노드에 연결된 간선 정보를 담기 위한 인접 리스트
    graph = [[] for _ in range(N + 1)]
    
    # 2. 그래프 구성 및 진입 차수 계산
    for _ in range(M):
        # 입력 형식: [가수 인원 수, 가수1, 가수2, ...]
        data = list(map(int, input().split()))
        
        # 가수가 2명 미만이면 순서 의미 없음
        if data[0] < 2:
            continue
            
        # data[1]부터 실제 가수 번호 시작
        singers = data[1:]
        
        # 순서대로 방향 간선 연결 (앞 가수 -> 뒷 가수)
        for i in range(len(singers) - 1):
            start = singers[i]
            end = singers[i+1]
            
            graph[start].append(end)
            indegree[end] += 1 # 진입 차수 증가
            
    # 3. 위상 정렬 수행
    result = [] # 정렬 결과 담을 리스트
    q = deque()
    
    # 초기: 진입 차수가 0인 노드를 큐에 삽입
    for i in range(1, N + 1):
        if indegree[i] == 0:
            q.append(i)
            
    while q:
        # 큐에서 원소 꺼내기
        now = q.popleft()
        result.append(now)
        
        # 해당 원소와 연결된 노드들의 진입 차수 감소
        for next_node in graph[now]:
            indegree[next_node] -= 1
            # 새롭게 진입 차수가 0이 되면 큐에 삽입
            if indegree[next_node] == 0:
                q.append(next_node)
                
    # 4. 결과 출력
    # 결과 리스트의 길이가 N이 아니라면 사이클이 발생한 것 (순서 정하기 불가능)
    if len(result) != N:
        print(0)
    else:
        for x in result:
            print(x)

if __name__ == "__main__":
    solve()