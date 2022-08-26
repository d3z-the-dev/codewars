def find_all(sum_dig, digs):
    array = []
    dig = int(''.join(['1'] * digs)) 
    while dig <= (10 ** digs) - 1:
        DIG = str(dig)
        if sum(int(i) for i in DIG) == sum_dig: array.append(dig)
        if '9' in DIG:
            i = DIG.find('9') - 1
            dig = int(DIG[:i] + ''.join([str(int(DIG[i]) + 1)] * (DIG.count('9') + 1)))
        else:
            dig += 1
    return [len(array), array[0], array[-1]] if array else []
