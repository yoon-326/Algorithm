import sys
from bisect import bisect_left

input = sys.stdin.readline

n = int(input())
a = list(map(int, input().split()))

lis = [a[0]]
record = [0] * n
record[0] = 0

for i in range(1, n):
    if a[i] > lis[-1]:
        lis.append(a[i])
        record[i] = len(lis) - 1
    else:
        idx = bisect_left(lis, a[i])
        lis[idx] = a[i]
        record[i] = idx

print(len(lis))

result = []
target_idx = len(lis) - 1

for i in range(n - 1, -1, -1):
    if record[i] == target_idx:
        result.append(a[i])
        target_idx -= 1

print(*result[::-1])