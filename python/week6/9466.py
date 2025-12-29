import sys

# 입력 속도 향상을 위한 설정
input = sys.stdin.readline

def solve():
    n = int(input())
    # 인덱스 1부터 사용하기 위해 앞에 [0] 추가
    numbers = [0] + list(map(int, input().split()))
    visited = [False] * (n + 1)
    team_count = 0

    for i in range(1, n + 1):
        if not visited[i]:
            cycle = []
            curr = i
            
            # 방문하지 않은 노드를 따라가며 경로 저장
            while not visited[curr]:
                visited[curr] = True
                cycle.append(curr)
                curr = numbers[curr]
            
            # 반복문이 끝났다는 것은 이미 방문한 노드(curr)를 만났다는 뜻
            
            # 그 방문한 노드(curr)가 '현재 탐색 중인 경로(cycle)'에 있다면 사이클 발생
            if curr in cycle:
                # 사이클이 시작된 지점(curr)부터 끝까지가 한 팀이 됨
                # 예: 1 -> 2 -> 3 -> 4 -> 2 인 경우
                # cycle: [1, 2, 3, 4], curr: 2
                # cycle.index(2)는 1번째 인덱스. cycle[1:]은 [2, 3, 4] (3명)
                team_count += len(cycle[cycle.index(curr):])
                
            # 만약 curr가 cycle에 없다면(이전에 이미 처리된 그룹을 만난 경우),
            # 현재 경로의 노드들은 팀을 이룰 수 없음 (그냥 넘어감)

    # 전체 학생 수 - 팀에 속한 학생 수 = 팀이 없는 학생 수
    print(n - team_count)

t = int(input())
for _ in range(t):
    solve()