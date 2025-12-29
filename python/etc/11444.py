import sys
sys.setrecursionlimit(10**6)
MOD = 1_000_000_007

def fib(n):
    # fib(n) -> (F(n), F(n+1))
    if n == 0:
        return (0, 1)

    a, b = fib(n // 2)  # a = F(k), b = F(k+1) where k = n//2

    c = (a * ((2 * b - a) % MOD)) % MOD
    d = (a * a + b * b) % MOD

    if n % 2 == 0:
        return (c, d)
    else:
        return (d, (c + d) % MOD)

n = int(sys.stdin.readline())
print(fib(n)[0] % MOD)
