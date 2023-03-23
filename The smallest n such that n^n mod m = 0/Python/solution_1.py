import math
import random


def is_prime(n: int, k=5) -> bool:
    if n < 2:
        return False
    if n in [2, 3]:
        return True
    if n % 2 == 0:
        return False    
    r, d = 0, n - 1
    while d % 2 == 0:
        d //= 2
        r += 1
    for i in range(k):
        a = random.randint(2, n - 2)
        x = pow(a, d, n)
        if x == 1 or x == n - 1:
            continue
        for j in range(r - 1):
            x = pow(x, 2, n)
            if x == n - 1:
                break
        else:
            return False
    return True

def rho(n: int) -> int:
    if n & 1 == 0: return 2
    c = random.randint(1, n - 1)
    r, t = c * (c + 1) % n, c
    while r != t:
        d = math.gcd(abs(t - r), n)
        if d > 1: return d
        r = (c + (r * r + c) ** 2) % n
        t = (c + t * t) % n
    return n

def factor(n: int) -> set:
    if n <= 1: return {*()}
    if is_prime(n): return {n}
    r = n
    while r == n: r = rho(n)
    while n % r == 0: n //= r
    return factor(r) | factor(n)

def f(m: int) -> int:
    n, i = 0, 1
    for p in factor(m):
        i *= p
    while True:
        n += i
        if pow(n, n, m) == 0: return n
