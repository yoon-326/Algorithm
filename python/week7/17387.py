import sys

input = sys.stdin.readline

x1, y1, x2, y2 = map(int, input().split())
x3, y3, x4, y4 = map(int, input().split())

# 좌표를 리스트로 묶어 관리 (비교 연산을 쉽게 하기 위함)
p1 = [x1, y1]
p2 = [x2, y2]
p3 = [x3, y3]
p4 = [x4, y4]

def ccw(p1, p2, p3):
    # 벡터의 외적(Cross Product) 계산
    # (x2-x1)(y3-y1) - (y2-y1)(x3-x1)
    val = (p2[0] - p1[0]) * (p3[1] - p1[1]) - (p2[1] - p1[1]) * (p3[0] - p1[0])
    
    if val > 0: return 1   # 반시계 방향
    elif val < 0: return -1 # 시계 방향
    else: return 0         # 일직선

# 각 선분을 기준으로 상대 선분의 끝점들의 방향성을 확인
# L1(p1, p2) 기준 p3, p4의 위치 관계
check1 = ccw(p1, p2, p3) * ccw(p1, p2, p4)
# L2(p3, p4) 기준 p1, p2의 위치 관계
check2 = ccw(p3, p4, p1) * ccw(p3, p4, p2)

if check1 == 0 and check2 == 0:
    # 두 선분이 일직선 상에 있는 경우 (평행하거나 겹침)
    # 겹치는지 확인하기 위해 정렬 후 범위 비교
    if min(p1, p2) <= max(p3, p4) and min(p3, p4) <= max(p1, p2):
        print(1)
    else:
        print(0)
# 일반적인 교차 (L1이 L2를 가로지르고, L2도 L1을 가로지름)
elif check1 <= 0 and check2 <= 0:
    print(1)
else:
    print(0)