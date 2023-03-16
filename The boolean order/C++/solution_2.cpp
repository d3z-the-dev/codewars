#include <bits/stdc++.h>
using namespace std;

#define Iter(i, a, b) for (int i = a, _b = b; i < _b; i++)
#define Downto(i, a, b) for (int i = a, _b = b; i >= _b; i--)

long long solve(const string &s, const string &op){
    int n = s.size();
    vector<vector<long long> >f[2];
    Iter(t, 0, 2){
        f[t].resize(n);
        for (auto& a:f[t]) a.resize(n);
    }
    Iter(i, 0, n) f[s[i] == 't'][i][i] = 1;
    #define TRANS(OP) {Iter(t1, 0, 2) Iter(t2, 0, 2) f[t1 OP t2][i][j] += f[t1][i][k] * f[t2][k+1][j];}
    Downto(i, n-1, 0) Iter(j, i+1, n) Iter(k, i, j){
        if (op[k]=='&') TRANS(&);
        if (op[k]=='|') TRANS(|);
        if (op[k]=='^') TRANS(^);
    }
    return f[1][0][n-1];
}