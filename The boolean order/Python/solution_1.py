def solve(s, ops):
    n = len(s)
    D = [[[0, 0] for _ in range(n)] for _ in range(n)]
    for i in range(n):
        if s[i] == 'f':
            D[i][i][0] = 1
        else:
            D[i][i][1] = 1
    for length in range(2, n + 1):
        for i in range(n - length + 1):
            j = i + length - 1
            for k in range(i, j):
                if ops[k] == '&':
                    D[i][j][0] += D[i][k][0] * D[k+1][j][0] + D[i][k][0] * D[k+1][j][1] + D[i][k][1] * D[k+1][j][0]
                    D[i][j][1] += D[i][k][1] * D[k+1][j][1]
                elif ops[k] == '|':
                    D[i][j][0] += D[i][k][0] * D[k+1][j][0]
                    D[i][j][1] += D[i][k][1] * D[k+1][j][0] + D[i][k][0] * D[k+1][j][1] + D[i][k][1] * D[k+1][j][1]
                else:
                    D[i][j][0] += D[i][k][0] * D[k+1][j][0] + D[i][k][1] * D[k+1][j][1]
                    D[i][j][1] += D[i][k][0] * D[k+1][j][1] + D[i][k][1] * D[k+1][j][0]
    return D[0][n-1][1]
