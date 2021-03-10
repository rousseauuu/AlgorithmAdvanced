#include <bits/stdc++.h>
const int N = 5010;

int n, m;
int s[N][N];

int main() {
    int cnt, R;
    std::ios::sync_with_stdio(false);
    std::cin >> cnt >> R;

    R = std::min(5001, R);
    n = m = 5001;
    
    while (cnt--) {
        int x, y, w;
        std::cin >> x >> y >> w;
        s[++x][++y] += w;
    }

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];

    int res = 0;

    for (int i = R; i <= n; ++i)
        for (int j = R; j <= m; ++j)
            res = std::max(res, s[i][j] - s[i - R][j] - s[i][j - R] + s[i - R][j - R]);

    std::cout << res << std::endl;

    return 0;
}