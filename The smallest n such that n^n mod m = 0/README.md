# [The smallest n such that n^n mod m = 0](https://www.codewars.com/kata/638b4205f418c4ab857f2692)

You have a natural number `m`.

You need to write a function `f(m)` which finds the smallest positive number `n` such that
```math
 n^n\equiv 0 \mod m 
```

In other words
```math
n^n
```
is divisible by `m`.

For example:

```
f(13) = 13
f(420) = 210
f(666) = 222
f(1234567890) = 411522630
```

In this kata all the tests will be with
```math
 1 \leqslant m \leqslant 10^{24} 
```

Keep in mind that `n <= m`, so iterating over `n` and cheking `pow(n,n,m) == 0` in total for 
```math
O(nlog(n))
```
operations is not an option.
