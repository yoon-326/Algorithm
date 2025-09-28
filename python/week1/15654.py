n, m = map(int, input().split())
nums = list(map(int, input().split()))
nums.sort()

visited = [False] * n
result = []

def dfs(depth):
    if depth == m:
        print(*result)
        return
    
    for i in range(n):
        if not visited[i]:
            visited[i] = True
            result.append(nums[i])

            dfs(depth + 1)

            result.pop()
            visited[i] = False

dfs(0)