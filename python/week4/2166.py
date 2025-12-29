import sys
input = sys.stdin.readline

N = int(input())
points = []
for _ in range(N):
    points.append(list(map(int, input().split())))

points.append(points[0])

sum1 = 0
sum2 = 0

for i in range(N):
    sum1 += points[i][0] * points[i+1][1]
    sum2 += points[i][1] * points[i+1][0]

area = 0.5 * abs(sum1 - sum2)

print(f"{area:.1f}")