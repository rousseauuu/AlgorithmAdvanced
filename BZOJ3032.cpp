#include <bits/stdc++.h>

const int N = 1e5 + 10;
typedef long long LL;
LL c[N], r[N];
int n, m, t;

LL solve(int M, LL a[]) {
    int Tm = t / M;
    for (int i = 1; i <= M; ++i) a[i] += a[i - 1] - Tm;
    std::sort(a + 1, a + M + 1);
    LL res = 0;
    for (int i = 1; i <= M; ++i) res += abs(a[i] - a[(M >> 1) + 1]);
    return res;
}


int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(0);
    std::cin >> n >> m >> t;
    int x, y;
    for (int i = 1; i <= t; ++i) {
        std::cin >> x >> y;
        ++c[y]; ++r[x];
    }

    if (t % m == 0 && t % n == 0) std::cout << "both " << solve(m, c) + solve(n, r) << std::endl;
    else if (t % n == 0) std::cout << "row " << solve(n, r) << std::endl;
    else if (t % m == 0) std::cout << "column " << solve(m, c) << std::endl;
    else std::cout << "impossible" << std::endl;

    return 0;
}
