def generator(digs, start=1):
    if digs != 1:
        for dig in range(start, 10):
            for i in generator(digs - 1, dig): yield [dig] + i
    else:
        for dig in range(start, 10): yield [dig]

def find_all(sum_dig, digs):
    array = [dig for dig in generator(digs) if sum(dig) == sum_dig]
    inter = lambda array: int(''.join(map(str, array)))
    return [len(array), inter(array[0]), inter(array[-1])] if array else []
