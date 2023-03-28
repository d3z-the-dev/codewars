def max_rot(n: int) -> int:
    digits = list(str(n))
    max_val = n
    for i in range(len(digits)):
        digits.append(digits.pop(i))
        rotated = int(''.join(digits))
        if rotated > max_val:
            max_val = rotated
    return max_val
