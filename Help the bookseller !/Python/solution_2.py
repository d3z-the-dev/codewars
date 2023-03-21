stock_list = lambda l, m: ' - '.join(f'({c} : {sum(int(i.split()[1]) for i in l if i[0] == c)})' for c in m) if l and m else ''
