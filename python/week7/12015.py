import sys
from bisect import bisect_left

input = sys.stdin.readline

n = int(input())
a = list(map(int, input().split()))

# LIS의 '길이'를 구하기 위한 배열
# lis[i]는 길이가 i+1인 증가 부분 수열 중 가장 작은 마지막 값을 저장
lis = [a[0]]

for item in a:
    # 현재 원소가 lis의 마지막 원소보다 크다면 뒤에 추가 (길이 증가)
    if lis[-1] < item:
        lis.append(item)
    # 작거나 같다면 들어갈 위치를 찾아 교체 (길이 유지, 더 유리한 값으로 갱신)
    else:
        idx = bisect_left(lis, item)
        lis[idx] = item

print(len(lis))
print(*lis)