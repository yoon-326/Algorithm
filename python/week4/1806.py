import sys

input = sys.stdin.readline

N, S = map(int, input().split())
nums = list(map(int, input().split()))

start = 0
end = 0
current_sum = 0
min_length = int(1e9)

while True:
    if current_sum >= S:
        min_length = min(min_length, end - start)
        current_sum -= nums[start]
        start += 1
    elif end == N:
        break
    else:
        current_sum += nums[end]
        end += 1

if min_length == int(1e9):
    print(0)
else:
    print(min_length)