from collections import deque

n, k = map(int, input().split())
MAX = 100001
distance = [-1] * MAX

dq = deque()
dq.append(n)
distance[n] = 0

while dq:
    x = dq.popleft()
    
    if x == k:
        print(distance[x])
        break

    # 0초 이동 (순간이동)
    if 0 <= x*2 < MAX and distance[x*2] == -1:
        distance[x*2] = distance[x]
        dq.appendleft(x*2)

    # 1초 이동 (x-1)
    if 0 <= x-1 < MAX and distance[x-1] == -1:
        distance[x-1] = distance[x] + 1
        dq.append(x-1)
        
    # 1초 이동 (x+1)
    if 0 <= x+1 < MAX and distance[x+1] == -1:
        distance[x+1] = distance[x] + 1
        dq.append(x+1)
