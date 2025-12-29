import sys
import heapq

input = sys.stdin.readline

n, k = map(int, input().split())
jewels = [list(map(int, input().split())) for _ in range(n)]
bags = [int(input()) for _ in range(k)]

jewels.sort()
bags.sort()

temp_jewels = []
answer = 0
j_idx = 0

for bag in bags:
    while j_idx < n and jewels[j_idx][0] <= bag:
        heapq.heappush(temp_jewels, -jewels[j_idx][1])
        j_idx += 1
    
    if temp_jewels:
        answer -= heapq.heappop(temp_jewels)

print(answer)