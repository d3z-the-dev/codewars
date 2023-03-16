#include <iostream>
#include <vector>
#include <string>

long long solve(std::string s, std::string ops) {
    int n = s.size();
    std::vector<std::vector<std::vector<long long>>> D(
        n, std::vector<std::vector<long long>>(n, std::vector<long long>(2, 0)));
    for (int i = 0 ; i < n ; i++) {
        if (s[i] == 'f') {
            D[i][i][0] = 1;
        } else {
            D[i][i][1] = 1;
        }
    }
    for (int length = 2 ; length <= n ; length++) {
        for (int i = 0 ; i <= n - length ; i++) {
            int j = i + length - 1;
            for (int k = i ; k < j ; k++) {
                if (ops[k] == '&') {
                    D[i][j][0] += D[i][k][0] * D[k+1][j][0] + D[i][k][0] * D[k+1][j][1] + D[i][k][1] * D[k+1][j][0];
                    D[i][j][1] += D[i][k][1] * D[k+1][j][1];
                } else if (ops[k] == '|') {
                    D[i][j][0] += D[i][k][0] * D[k+1][j][0];
                    D[i][j][1] += D[i][k][1] * D[k+1][j][0] + D[i][k][0] * D[k+1][j][1] + D[i][k][1] * D[k+1][j][1];
                } else {
                    D[i][j][0] += D[i][k][0] * D[k+1][j][0] + D[i][k][1] * D[k+1][j][1];
                    D[i][j][1] += D[i][k][0] * D[k+1][j][1] + D[i][k][1] * D[k+1][j][0];
                }
            }
        }
    }
    return D[0][n-1][1];
}