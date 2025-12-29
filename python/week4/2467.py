import sys
input = sys.stdin.readline

N = int(input())
solutions = list(map(int, input().split()))

left = 0
right = N - 1

min_diff = float('inf')
answer_left = 0
answer_right = 0

while left < right:
    current_sum = solutions[left] + solutions[right]
    
    if abs(current_sum) < min_diff:
        min_diff = abs(current_sum)
        answer_left = solutions[left]
        answer_right = solutions[right]
    
    if current_sum < 0:
        left += 1
    elif current_sum > 0:
        right -= 1
    else:
        break

print(answer_left, answer_right)