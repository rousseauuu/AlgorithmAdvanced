#include <bits/stdc++.h>

typedef long long LL;
const int N = 5e5 + 10;

int n;
int a[N];

int main() {
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    for (int i = n; i; --i)
        a[i] -= a[i - 1];

    LL pos = 0, neg = 0;
    for (int i = 2; i <= n; ++i) 
        if (a[i] > 0)
            pos += a[i];
        else
            neg -= a[i];

    std::cout << std::min(pos, neg) + abs(pos - neg) << std::endl;
    std::cout << abs(pos - neg) + 1 << std::endl;

    return 0;
}