#include <bits/stdc++.h>

typedef long long LL;
typedef std::pair<long long, long long> PLL;

PLL calc(int n, LL m) {
    if (n == 0)
        return std::make_pair(0, 0);
    LL len = 1LL << (n - 1);
    LL cnt = 1LL << (2 * n - 2);
    PLL pos = calc(n - 1, m % cnt);
    LL x = pos.first;
    LL y = pos.second;
    LL z = m / cnt;
    if (z == 0)
        return std::make_pair(y, x);
    if (z == 1)
        return std::make_pair(x, y + len);
    if (z == 2)
        return std::make_pair(x + len, y + len);
    return std::make_pair(2 * len - y - 1, len - x - 1);
}


int main() {
    std::ios::sync_with_stdio(false);
    int T;
    std::cin >> T;
    while (T--) {
        LL N, A, B;
        std::cin >> N >> A >> B;
        auto ac = calc(N, A - 1);
        auto bc = calc(N, B - 1);
        double x = ac.first - bc.first;
        double y = ac.second - bc.second;
        std::printf("%.0lf\n", sqrt(x * x + y * y) * 10);
    }
}