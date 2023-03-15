function solve(s, ops) {
    let n = s.length;
    let D = Array.from(Array(n), () => Array.from(Array(n), () => Array(2).fill(0)))
    for (let i = 0; i < n; i++) {
        if (s[i] == "t") D[i][i][1] = 1
        else D[i][i][0] = 1
    }
    for (let len = 2; len <= n; len++) {
        for (let i = 0; i < n - len + 1; i++) {
            let j = i + len - 1
            for (let k = i; k < j; k++) {
                let x1 = D[i][k][1], y1 = D[k+1][j][1], x0 = D[i][k][0], y0 = D[k+1][j][0]
                if (ops[k] == "&") {
                    D[i][j][1] += x1 * y1
                    D[i][j][0] += x0 * y0 + x0 * y1 + x1 * y0
                } else if (ops[k] == "|") {
                    D[i][j][1] += x1 * y1 + x1 * y0 + x0 * y1
                    D[i][j][0] += x0 * y0
                } else {
                    D[i][j][1] += x1 * y0 + x0 * y1
                    D[i][j][0] += x0 * y0 + x1 * y1
                }
            }
        }
    }
    return D[0][n-1][1]
}