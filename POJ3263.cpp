#include <bits/stdc++.h>

const int N = 1e4 + 10;

std::map<std::pair<int, int>, bool> existed;
int c[N], d[N];

int main() {
    int n, p, h, m;
    std::cin >> n >> p >> h >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        std::cin >> a >> b;
        if (a > b)
            std::swap(a, b);
        if (existed[std::make_pair(a, b)])
            continue;
        d[a + 1]--;
        d[b]++;
        existed[std::make_pair(a, b)] = true;
    }
    for (int i = 1; i <= n; i++) {
        c[i] = c[i - 1] + d[i];
        std::cout << h + c[i] << std::endl;
    }

    return 0;
}