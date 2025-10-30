import sys
input = sys.stdin.readline

expr = input().strip()
stack = []
result = []

for ch in expr:
    if ch.isalpha():
        result.append(ch)
    elif ch == '(':
        stack.append(ch)
    elif ch == ')':
        while stack and stack[-1] != '(':
            result.append(stack.pop())
        stack.pop()  # '(' 제거
    else:
        while stack and stack[-1] != '(':
            if (ch in '+-' and stack[-1] in '+-*/') or (ch in '*/' and stack[-1] in '*/'):
                result.append(stack.pop())
            else:
                break
        stack.append(ch)

while stack:
    result.append(stack.pop())

print(''.join(result))
