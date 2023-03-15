def solve(s, ops):
    n = len(s)
    D = [[[0, 0] for _ in range(n)] for _ in range(n)]
    for i in range(n):
        D[i][i][s[i] == 't'] = 1
    for l in range(2, n + 1):
        for i in range(n - l + 1):
            j = i + l - 1
            for k in range(i, j):
                for x in [0, 1]:
                    for y in [0, 1]:
                        if ops[k] == '&':
                            D[i][j][x&y] += D[i][k][x] * D[k+1][j][y]
                        elif ops[k] == '|':
                            D[i][j][x|y] += D[i][k][x] * D[k+1][j][y]
                        else:
                            D[i][j][x^y] += D[i][k][x] * D[k+1][j][y]
    return D[0][n-1][1]
