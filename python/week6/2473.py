import sys

input = sys.stdin.readline

def solve():
    N = int(input())
    arr = list(map(int, input().split()))
    arr.sort()

    min_diff = float('inf')
    result = []

    for i in range(N - 2):
        left = i + 1
        right = N - 1

        while left < right:
            current_sum = arr[i] + arr[left] + arr[right]

            if abs(current_sum) < min_diff:
                min_diff = abs(current_sum)
                result = [arr[i], arr[left], arr[right]]

            if current_sum < 0:
                left += 1
            elif current_sum > 0:
                right -= 1
            else:
                print(*result)
                return

    print(*result)

if __name__ == "__main__":
    solve()