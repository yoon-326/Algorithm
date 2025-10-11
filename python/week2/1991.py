import sys
input = sys.stdin.readline

n = int(input())
tree = {}

for _ in range(n):
    root, left, right = input().split()
    tree[root] = (left, right)

# 전위 순회 (루트) (왼쪽 자식) (오른쪽 자식)
def preorder(node):
    if node == '.':
        return
    print(node, end='')
    preorder(tree[node][0])
    preorder(tree[node][1])

# 중위 순회 (왼쪽 자식) (루트) (오른쪽 자식)
def inorder(node):
    if node == '.':
        return
    inorder(tree[node][0])
    print(node, end='')
    inorder(tree[node][1])

# 후위 순회 (왼쪽 자식) (오른쪽 자식) (루트)
def postorder(node):
    if node == '.':
        return
    postorder(tree[node][0])
    postorder(tree[node][1])
    print(node, end='')

preorder('A')
print()
inorder('A')
print()
postorder('A')